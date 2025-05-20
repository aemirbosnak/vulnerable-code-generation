//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Validate the arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Create a listening socket
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("listen");
        exit(1);
    }

    // Bind the listening socket
    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(atoi(argv[2]));
    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_fd, SOMAXCONN) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept a new connection
    int client_fd = accept(listen_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("accept");
        exit(1);
    }

    // Forward the client request to the server
    char buf[1024];
    while (1) {
        if (recv(client_fd, buf, sizeof(buf), 0) < 0) {
            perror("recv");
            exit(1);
        }
        if (send(socket_fd, buf, strlen(buf), 0) < 0) {
            perror("send");
            exit(1);
        }
        if (recv(client_fd, buf, sizeof(buf), 0) < 0) {
            perror("recv");
            exit(1);
        }
        if (send(socket_fd, buf, strlen(buf), 0) < 0) {
            perror("send");
            exit(1);
        }
    }

    // Close the connections
    close(client_fd);
    close(socket_fd);
    close(listen_fd);

    return 0;
}