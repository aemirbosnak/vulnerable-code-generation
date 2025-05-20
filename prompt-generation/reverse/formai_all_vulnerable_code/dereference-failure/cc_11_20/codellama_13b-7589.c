//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
/*
* Simple HTTP Proxy Example Program
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen_port> <target_host> <target_port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket");
        return 1;
    }

    // Set socket options
    int enable = 1;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Bind socket to local port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listen_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(listen_sock, 1) < 0) {
        perror("listen");
        return 1;
    }

    // Accept incoming connection
    int client_sock = accept(listen_sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    // Create socket for target server
    int target_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (target_sock < 0) {
        perror("socket");
        return 1;
    }

    // Set target server address
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(atoi(argv[3]));
    target_addr.sin_addr.s_addr = inet_addr(argv[2]);
    if (target_addr.sin_addr.s_addr == INADDR_NONE) {
        fprintf(stderr, "Invalid target address: %s\n", argv[2]);
        return 1;
    }

    // Connect to target server
    if (connect(target_sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Transfer data between client and target server
    char buf[BUFSIZE];
    while (1) {
        // Receive data from client
        int n = recv(client_sock, buf, BUFSIZE, 0);
        if (n < 0) {
            perror("recv");
            break;
        } else if (n == 0) {
            break;
        }

        // Send data to target server
        if (send(target_sock, buf, n, 0) < 0) {
            perror("send");
            break;
        }

        // Receive data from target server
        n = recv(target_sock, buf, BUFSIZE, 0);
        if (n < 0) {
            perror("recv");
            break;
        } else if (n == 0) {
            break;
        }

        // Send data to client
        if (send(client_sock, buf, n, 0) < 0) {
            perror("send");
            break;
        }
    }

    // Close sockets
    close(client_sock);
    close(target_sock);

    return 0;
}