//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listening_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen = sizeof(client_addr);

    listening_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listening_socket == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listening_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listening_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listening_socket, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        new_socket = accept(listening_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        if (new_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[1024];
        int bytes_received;

        while ((bytes_received = recv(new_socket, buffer, sizeof(buffer), 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);
        }

        close(new_socket);
    }

    return 0;
}