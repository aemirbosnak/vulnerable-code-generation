//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    char buffer[MAX];

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, MAX, 0);

        if (bytes_received <= 0) {
            if (bytes_received == 0)
                printf("Client disconnected\n");
            else
                perror("recv");

            close(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("Received message: %s", buffer);

        send(client_socket, buffer, strlen(buffer), 0);
    }

    return 0;
}