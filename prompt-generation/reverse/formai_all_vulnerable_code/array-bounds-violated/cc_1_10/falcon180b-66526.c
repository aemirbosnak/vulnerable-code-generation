//Falcon-180B DATASET v1.0 Category: Email Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define PORT 110
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define WAIT_TIME 5

typedef struct client_info {
    int sock;
    char username[64];
    char password[64];
    char mailbox[64];
    int authenticated;
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("Client %d sent: %s\n", client_sock, buffer);
    }

    close(client_sock);
    num_clients--;
}

void accept_connections() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, 3);

    while (1) {
        printf("Waiting for connection...\n");
        int client_sock = accept(server_sock, NULL, NULL);

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server is full. Please try again later.\n", 45, 0);
            close(client_sock);
            continue;
        }

        clients[num_clients].sock = client_sock;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_sock);
    }
}

int main() {
    srand(time(NULL));

    printf("Starting POP3 server on port %d...\n", PORT);
    accept_connections();

    return 0;
}