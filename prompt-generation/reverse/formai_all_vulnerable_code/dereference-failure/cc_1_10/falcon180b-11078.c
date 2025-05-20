//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUF_SIZE];
    int bytes_received;
    int opt = TRUE;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(1);
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_sock, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (opt) {
        memset(buffer, 0, BUF_SIZE);
        bytes_received = recv(listen_sock, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        send(client_sock, buffer, bytes_received, 0);
    }

    close(listen_sock);
    close(client_sock);

    return 0;
}