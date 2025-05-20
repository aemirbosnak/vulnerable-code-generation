//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
struct sockaddr_in server_addr;
int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *socket_desc);

int main(int argc, char *argv[]) {
    int opt = 1;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == 0) {
        printf("Could not create socket");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, addrlen);

    listen(server_socket, 3);

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        int new_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen);

        if (new_socket < 0) {
            printf("Error accepting connection");
        } else {
            client_sockets[client_count] = new_socket;
            client_count++;
        }
    }

    return 0;
}

void *handle_client(void *socket_desc) {
    int sock = *(int *) socket_desc;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        recv(sock, buffer, BUFFER_SIZE, 0);

        printf("Message from client: %s\n", buffer);
    }

    close(sock);
    pthread_exit(0);
}