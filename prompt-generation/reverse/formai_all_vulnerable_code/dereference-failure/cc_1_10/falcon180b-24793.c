//Falcon-180B DATASET v1.0 Category: Chat server ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

char *client_ip_addresses[MAX_CLIENTS];

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        send(server_socket, buffer, bytes_received, 0);
    }

    close(*((int *) client_socket));
    num_clients--;
}

int main() {
    int opt = 1;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is listening on port %d\n", PORT);

    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, (socklen_t *) &addrlen);

        if (client_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip_addresses[num_clients], INET_ADDRSTRLEN);
        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
    }

    close(server_socket);
    return 0;
}