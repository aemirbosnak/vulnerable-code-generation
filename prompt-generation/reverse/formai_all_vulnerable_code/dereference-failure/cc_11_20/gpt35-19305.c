//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <port_number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(ip_address);
    proxy_addr.sin_port = htons(port_number);

    if (connect(client_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Connected to proxy server at %s:%d\n", ip_address, port_number);

    while (true) {
        char buf[BUF_SIZE] = { 0 };
        printf("Enter HTTP request (or 'q' to quit):\n");
        fgets(buf, BUF_SIZE, stdin);

        if (buf[0] == 'q') {
            break;
        }

        // Make sure the input is a valid HTTP request
        if (strncmp(buf, "GET /", 5) != 0 && strncmp(buf, "POST /", 6) != 0) {
            printf("Invalid HTTP request\n");
            continue;
        }

        // Send the HTTP request to the proxy server
        if (send(client_socket, buf, strlen(buf), 0) == -1) {
            perror("send");
            return 1;
        }

        // Receive the HTTP response from the proxy server
        while (true) {
            char recv_buf[BUF_SIZE] = { 0 };
            int recv_len = recv(client_socket, recv_buf, BUF_SIZE - 1, 0);
            if (recv_len == -1) {
                perror("recv");
                return 1;
            }
            if (recv_len == 0) {
                break;
            }
            printf("%s", recv_buf);
        }
    }

    close(client_socket);

    return 0;
}