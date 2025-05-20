//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[MAX_MSG_SIZE];
    while (1) {
        memset(buffer, 0, MAX_MSG_SIZE);
        int bytes_received = recv(*((int *) client_socket), buffer, MAX_MSG_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(*((int *) client_socket));
    num_clients--;
}

void accept_connections() {
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            break;
        }
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
        client_sockets[num_clients++] = client_socket;
    }
}

int main(int argc, char *argv[]) {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_socket, 3);

    accept_connections();

    return 0;
}