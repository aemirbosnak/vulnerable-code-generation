//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFLEN 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <port> <remote_host> <remote_port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *remote_host = argv[2];
    int remote_port = atoi(argv[3]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        char buf[BUFLEN];
        int nbytes;
        while ((nbytes = read(client_fd, buf, BUFLEN)) > 0) {
            // Parse the HTTP request
            char *method = strtok(buf, " ");
            char *path = strtok(NULL, " ");
            char *version = strtok(NULL, "\r\n");

            // Connect to the remote host
            int remote_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (remote_fd == -1) {
                perror("socket");
                break;
            }

            struct sockaddr_in remote_addr;
            memset(&remote_addr, 0, sizeof(remote_addr));
            remote_addr.sin_family = AF_INET;
            remote_addr.sin_addr.s_addr = inet_addr(remote_host);
            remote_addr.sin_port = htons(remote_port);

            if (connect(remote_fd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
                perror("connect");
                break;
            }

            // Send the request to the remote host
            if (write(remote_fd, buf, nbytes) == -1) {
                perror("write");
                break;
            }

            // Read the response from the remote host
            while ((nbytes = read(remote_fd, buf, BUFLEN)) > 0) {
                // Send the response to the client
                if (write(client_fd, buf, nbytes) == -1) {
                    perror("write");
                    break;
                }
            }

            // Clean up
            close(remote_fd);
        }

        close(client_fd);
    }

    close(server_fd);

    return 0;
}