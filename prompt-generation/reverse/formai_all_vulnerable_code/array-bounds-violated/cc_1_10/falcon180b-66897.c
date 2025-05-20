//Falcon-180B DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/wait.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0
#define PORT 80
#define IP "127.0.0.1"

int main() {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUF_SIZE];
    int bytes_received;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(IP);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        close(client_socket);
    }

    return 0;
}