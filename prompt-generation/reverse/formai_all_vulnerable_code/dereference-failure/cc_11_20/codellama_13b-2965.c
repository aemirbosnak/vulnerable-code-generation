//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
/*
 * C Simple HTTP Proxy example program in a Claude Shannon style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sock, sock_client, sock_server;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_LINE];
    char *line;
    int n;

    if (argc != 3) {
        printf("Usage: %s <proxy_ip> <proxy_port>\n", argv[0]);
        return 1;
    }

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        // accept incoming connection
        sock_client = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (sock_client < 0) {
            perror("accept");
            return 1;
        }

        // connect to server
        sock_server = socket(AF_INET, SOCK_STREAM, 0);
        if (sock_server < 0) {
            perror("socket");
            return 1;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(atoi(argv[2]));
        server_addr.sin_addr.s_addr = inet_addr(argv[1]);
        if (connect(sock_server, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            return 1;
        }

        // forward data
        while ((n = read(sock_client, buffer, MAX_LINE)) > 0) {
            write(sock_server, buffer, n);
        }
        if (n < 0) {
            perror("read");
            return 1;
        }

        // close sockets
        close(sock_client);
        close(sock_server);
    }

    return 0;
}