//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 5
#define MAX_LINE 1024
#define RESPONSE "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Welcome to my website!</h1></body></html>"

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_received;
    int opt = TRUE;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(2);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        perror("listen");
        exit(3);
    }

    while (TRUE) {
        client_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket == -1) {
            perror("accept");
            exit(4);
        }

        char buffer[MAX_LINE];
        bytes_received = recv(client_socket, buffer, MAX_LINE, 0);
        if (bytes_received <= 0) {
            perror("recv");
            exit(5);
        }

        buffer[bytes_received] = '\0';
        printf("Received request: %s\n", buffer);

        send(client_socket, RESPONSE, strlen(RESPONSE), 0);
        close(client_socket);
    }

    return 0;
}