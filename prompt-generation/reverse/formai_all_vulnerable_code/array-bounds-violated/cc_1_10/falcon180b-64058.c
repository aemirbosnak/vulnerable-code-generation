//Falcon-180B DATASET v1.0 Category: Chat server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct client {
    int sock;
    char ip[INET_ADDRSTRLEN];
    char name[20];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_sock, char *msg) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sock!= sender_sock) {
            send(clients[i].sock, msg, strlen(msg), 0);
        }
    }
}

void handle_client(int sock) {
    char buffer[BUFFER_SIZE];
    while (TRUE) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(sock);
            break;
        }
        buffer[bytes_received - 1] = '\0';
        broadcast(sock, buffer);
    }
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Chat server started on port %d\n", PORT);

    while (TRUE) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_size);
        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, clients[num_clients].ip, INET_ADDRSTRLEN);
        sprintf(clients[num_clients].name, "Client %d", num_clients + 1);
        clients[num_clients].sock = client_sock;
        num_clients++;

        printf("Client connected: %s (%s)\n", clients[num_clients - 1].name, clients[num_clients - 1].ip);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)&clients[num_clients - 1]);
    }

    close(server_sock);
    return 0;
}