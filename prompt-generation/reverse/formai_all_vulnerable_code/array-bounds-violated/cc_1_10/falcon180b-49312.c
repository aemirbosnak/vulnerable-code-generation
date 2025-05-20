//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    uint8_t mac[6];
    int signal_strength;
    int connected;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Client %d sent: %s\n", clients[client_sock].signal_strength, buffer);
    }

    close(client_sock);
    clients[client_sock].connected = FALSE;
    num_clients--;
}

void accept_connections() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CLIENTS);

    while (TRUE) {
        int client_sock = accept(server_sock, NULL, NULL);

        if (num_clients >= MAX_CLIENTS) {
            close(client_sock);
            continue;
        }

        clients[num_clients].sock = client_sock;
        clients[num_clients].connected = TRUE;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_sock);
    }
}

int main() {
    accept_connections();
    return 0;
}