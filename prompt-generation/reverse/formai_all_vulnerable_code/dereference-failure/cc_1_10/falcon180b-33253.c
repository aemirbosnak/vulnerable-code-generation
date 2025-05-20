//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

char *welcome_message = "Welcome to the Smart Home Light Control System!\r\n";

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d sent: %s", *((int *) client_socket), buffer);
    }
    close(*((int *) client_socket));
    num_clients--;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    while (1) {
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, NULL);
        if (client_socket == -1) {
            printf("Error accepting client connection: %s\n", strerror(errno));
            continue;
        }
        printf("Client %d connected\n", num_clients);
        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    close(server_socket);
    return 0;
}