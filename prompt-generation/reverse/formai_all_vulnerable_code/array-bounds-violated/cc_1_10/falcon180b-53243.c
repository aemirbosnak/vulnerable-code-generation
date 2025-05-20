//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BACKLOG 5

int client_socket[MAX_CLIENTS];
int client_status[MAX_CLIENTS];

void *handle_client(void *socket_desc) {
    char buffer[1024];
    int bytes_received, bytes_sent;

    while (client_status[*(int*)socket_desc] == 1) {
        bytes_received = recv(*(int*)socket_desc, buffer, 1024, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Client %d sent: %s\n", *(int*)socket_desc, buffer);
        } else {
            close(*(int*)socket_desc);
            client_status[*(int*)socket_desc] = 0;
            printf("Client %d disconnected\n", *(int*)socket_desc);
        }
    }

    return NULL;
}

int main() {
    int server_socket, new_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id[MAX_CLIENTS];

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, BACKLOG) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (1) {
        addrlen = sizeof(client_addr);
        if ((new_socket = accept(server_socket, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen)) < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_socket[i] == 0) {
                client_socket[i] = new_socket;
                client_status[i] = 1;
                pthread_create(&thread_id[i], NULL, handle_client, (void*)&i);
                break;
            }
        }
    }

    return 0;
}