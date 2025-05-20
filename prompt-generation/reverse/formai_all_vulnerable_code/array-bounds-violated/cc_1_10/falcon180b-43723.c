//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define BUFLEN 1024
#define PORT 8080

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFLEN];

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        error_handling("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
        exit(2);
    }

    if (listen(listen_socket, 5) == -1) {
        error_handling("listen failed");
        exit(3);
    }

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket == -1) {
            error_handling("accept failed");
            exit(4);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((recv(client_socket, buffer, BUFLEN, 0)) > 0) {
            buffer[recv(client_socket, buffer, BUFLEN, 0)] = '\0';
            printf("Received message: %s", buffer);
        }

        close(client_socket);
    }

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}