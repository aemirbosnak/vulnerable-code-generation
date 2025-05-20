//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>

int main() {
    int server_fd, client_fd, n;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];
    int port = 8080;

    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number\n");
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(server_fd, 5) < 0) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &n);
        if (client_fd < 0) {
            fprintf(stderr, "Error accepting client: %s\n", strerror(errno));
            continue;
        }

        printf("New client connected: %s\n", inet_ntoa(client_addr.sin_addr));
        while (1) {
            n = read(client_fd, buffer, sizeof(buffer));
            if (n < 0) {
                fprintf(stderr, "Error reading from client: %s\n", strerror(errno));
                close(client_fd);
                continue;
            }

            if (strcmp(buffer, "END") == 0) {
                break;
            }

            printf("Received: %s\n", buffer);
            if (write(client_fd, "OK", 3) < 0) {
                fprintf(stderr, "Error writing to client: %s\n", strerror(errno));
                close(client_fd);
                continue;
            }
        }

        close(client_fd);
    }

    close(server_fd);
    return 0;
}