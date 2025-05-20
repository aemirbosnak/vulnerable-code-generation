//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#define TRUE   1
#define FALSE  0
#define PORT 8888
#define MAX 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1) {
        error_handling("socket failed");
        exit(1);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error_handling("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        error_handling("listen");
        exit(1);
    }

    printf("The server is listening on port %d\n", PORT);

    while (TRUE) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        if (client_socket == -1) {
            error_handling("accept");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[MAX];
        bzero(buffer, MAX);

        while (recv(client_socket, buffer, MAX, 0) > 0) {
            printf("Received message: %s", buffer);
            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(1);
}