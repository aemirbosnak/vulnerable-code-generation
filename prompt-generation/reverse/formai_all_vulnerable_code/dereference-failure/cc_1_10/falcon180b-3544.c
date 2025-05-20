//Falcon-180B DATASET v1.0 Category: Chat server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_info {
    int sock;
    char ip[INET6_ADDRSTRLEN];
    char name[20];
};

void *handle_client(void *arg) {
    struct client_info *client = (struct client_info *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        send(client->sock, buffer, bytes_received, 0);
    }

    close(client->sock);
    printf("Client disconnected: %s\n", client->name);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CLIENTS);

    printf("Chat server started on port 8080\n");

    while (1) {
        struct client_info client_info;
        socklen_t client_size = sizeof(client_info.ip);

        int client_sock = accept(server_sock, (struct sockaddr *) &client_info.ip, &client_size);

        if (client_sock == -1) {
            printf("Error accepting client\n");
            continue;
        }

        inet_ntop(AF_INET, &client_info.ip, client_info.ip, INET6_ADDRSTRLEN);

        printf("Client connected: %s\n", client_info.ip);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_info);
    }

    return 0;
}