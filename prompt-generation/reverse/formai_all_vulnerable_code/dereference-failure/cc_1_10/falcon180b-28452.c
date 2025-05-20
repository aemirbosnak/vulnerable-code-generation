//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket_desc) {
    char buffer[BUFFER_SIZE];
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(*((int*)socket_desc), buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        printf("Client %d sent: %s\n", *((int*)socket_desc), buffer);
        for(int i=0; i<num_clients; i++) {
            if(i!= *((int*)socket_desc)) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }
    close(*((int*)socket_desc));
    num_clients--;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is running on port 8080\n");

    while(1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if(client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        printf("Client connected\n");
        int *socket_desc = malloc(sizeof(int));
        *socket_desc = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, socket_desc);
        client_sockets[num_clients] = client_socket;
        num_clients++;
    }

    return 0;
}