//Falcon-180B DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024
#define PORT 8080

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[MAX_MSG_SIZE];
    while(1) {
        memset(buffer, 0, MAX_MSG_SIZE);
        int bytes_received = recv(client_socket, buffer, MAX_MSG_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", client_socket, buffer);
    }
    close(client_socket);
    return NULL;
}

void accept_connections(int server_socket) {
    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if(client_socket < 0) {
            printf("Error accepting connection\n");
            continue;
        }
        if(num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }
        client_sockets[num_clients] = client_socket;
        num_clients++;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        return 1;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }
    if(listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }
    printf("Server started on port %d\n", PORT);
    accept_connections(server_socket);
    return 0;
}