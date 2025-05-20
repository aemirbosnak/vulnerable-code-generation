//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 8192

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr, client_addr;
    int server_fd, client_fd, client_addr_len, bytes_read;
    char buffer[BUFFER_SIZE];
    struct hostent *host;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if ((server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Failed to listen to socket");
        exit(1);
    }

    while (1) {
        client_addr_len = sizeof(client_addr);
        if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len)) < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        if (fork() == 0) {
            close(server_fd);

            bzero(buffer, BUFFER_SIZE);
            bytes_read = read(client_fd, buffer, BUFFER_SIZE);
            if (bytes_read < 0) {
                perror("Failed to read data from client");
                exit(1);
            }

            char method[10], uri[100], version[10];
            sscanf(buffer, "%s %s %s", method, uri, version);

            char *host_start = strstr(buffer, "Host:");
            host_start += strlen("Host:");

            char *host_end = index(host_start, '\r');
            *host_end = '\0';

            if ((host = gethostbyname(host_start)) == NULL) {
                perror("Failed to resolve hostname");
                exit(1);
            }

            struct sockaddr_in remote_addr;
            bzero((char *) &remote_addr, sizeof(remote_addr));
            remote_addr.sin_family = AF_INET;
            remote_addr.sin_port = htons(80);
            memcpy(&remote_addr.sin_addr, host->h_addr, host->h_length);

            int remote_fd;
            if ((remote_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
                perror("Failed to create remote socket");
                exit(1);
            }

            if (connect(remote_fd, (struct sockaddr *) &remote_addr, sizeof(remote_addr)) < 0) {
                perror("Failed to connect to remote host");
                exit(1);
            }

            if (write(remote_fd, buffer, bytes_read) < 0) {
                perror("Failed to write data to remote host");
                exit(1);
            }

            while ((bytes_read = read(remote_fd, buffer, BUFFER_SIZE)) > 0) {
                if (write(client_fd, buffer, bytes_read) < 0) {
                    perror("Failed to write data to client");
                    exit(1);
                }
            }

            close(remote_fd);
            close(client_fd);
            exit(0);
        } else {
            close(client_fd);
        }
    }

    return 0;
}