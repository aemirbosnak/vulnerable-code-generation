//Falcon-180B DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024
#define SERVER_PORT 8080

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients;
pthread_t threads[MAX_CLIENTS];

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char msg[MAX_MSG_SIZE];
    while(1) {
        memset(msg, 0, MAX_MSG_SIZE);
        int bytes_received = recv(client_socket, msg, MAX_MSG_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        printf("Client %d sent message: %s\n", client_socket, msg);
        for(int i = 0; i < num_clients; i++) {
            if(i!= client_socket) {
                send(client_sockets[i], msg, strlen(msg), 0);
            }
        }
    }
    close(client_socket);
    return NULL;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Server is listening on port %d\n", SERVER_PORT);

    while(1) {
        socklen_t addr_size = sizeof(struct sockaddr_in);
        int client_socket = accept(server_socket, (struct sockaddr *)&server_addr, &addr_size);
        if(client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        printf("Client %d connected\n", client_socket);

        pthread_create(&threads[num_clients], NULL, handle_client, (void *)&client_socket);
        client_sockets[num_clients] = client_socket;
        num_clients++;
    }

    return 0;
}