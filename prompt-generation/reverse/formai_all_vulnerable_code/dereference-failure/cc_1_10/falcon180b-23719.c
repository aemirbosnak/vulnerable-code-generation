//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int new_socket;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        error_handling("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        error_handling("listen");
    }

    printf("Server is listening on port %d\n", atoi(argv[1]));

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);

        if (new_socket == -1) {
            error_handling("accept");
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(new_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                error_handling("recv");
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(new_socket, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                error_handling("send");
            }
        }

        close(new_socket);
    }

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}