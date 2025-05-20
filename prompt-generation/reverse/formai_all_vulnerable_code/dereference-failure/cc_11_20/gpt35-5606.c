//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PORT 8080

int main(int argc, char *argv[])
{
    int client_fd, server_fd, bytes_received;
    struct sockaddr_in client_addr, server_addr;
    struct hostent *host;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Connect to server
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(PORT);
    if (bind(client_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("Error binding socket");
        return -1;
    }
    listen(client_fd, 5);
    printf("Proxy listening on port %d...\n", PORT);
    while (1) {
        int client_len = sizeof(client_addr);

        if ((server_fd = accept(client_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Receive request from client
        bzero(buffer, BUFFER_SIZE);
        bytes_received = recv(server_fd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received < 0) {
            perror("Error receiving from client");
            return -1;
        }

        // Parse request for server
        char *method = strtok(buffer, " ");
        char *target = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");
        char *host_header = NULL;
        char *path = NULL;
        if (strncmp(target, "http://", 7) == 0) {
            host_header = strstr(target, "Host: ");
            if (host_header != NULL) {
                sscanf(host_header, "Host: %s\r\n", buffer);
                host = gethostbyname(buffer);
                path = strchr(target + 7, '/');
            }
        }

        // Connect to server and forward request
        if (host != NULL) {
            bzero(&server_addr, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(80);
            server_addr.sin_addr = *((struct in_addr *)host->h_addr);
            server_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                perror("Error connecting to server");
                return -1;
            }

            if (send(server_fd, method, strlen(method), 0) < 0) {
                perror("Error sending method to server");
                return -1;
            }
            if (send(server_fd, " ", 1, 0) < 0) {
                perror("Error sending space to server");
                return -1;
            }
            if (path != NULL) {
                if (send(server_fd, path, strlen(path), 0) < 0) {
                    perror("Error sending path to server");
                    return -1;
                }
            } else {
                if (send(server_fd, target, strlen(target), 0) < 0) {
                    perror("Error sending target to server");
                    return -1;
                }
            }
            if (send(server_fd, version, strlen(version), 0) < 0) {
                perror("Error sending version to server");
                return -1;
            }
            if (send(server_fd, "\r\n", 2, 0) < 0) {
                perror("Error sending end-of-line to server");
                return -1;
            }
            while ((bytes_received = recv(server_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
                if (send(client_fd, buffer, bytes_received, 0) < 0) {
                    perror("Error sending response to client");
                    return -1;
                }
                bzero(buffer, BUFFER_SIZE);
            }
            if (bytes_received < 0) {
                perror("Error receiving from server");
                return -1;
            }
            close(server_fd);
        }

        close(client_fd);
        printf("Proxy closed connection\n");
    }

    return 0;
}