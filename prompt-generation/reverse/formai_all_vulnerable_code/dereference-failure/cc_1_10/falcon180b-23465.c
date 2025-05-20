//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

struct client {
    int sock;
    char ip[16];
    int port;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        send(clients[0].sock, buffer, bytes_received, 0);
    }

    close(client_sock);
}

void accept_connections() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 10);

    printf("Proxy server started on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server is full.\r\n", 15, 0);
            close(client_sock);
            continue;
        }

        strcpy(clients[num_clients].ip, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].port = ntohs(client_addr.sin_port);
        clients[num_clients].sock = client_sock;

        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)&clients[num_clients - 1]);
    }
}

int main() {
    accept_connections();

    return 0;
}