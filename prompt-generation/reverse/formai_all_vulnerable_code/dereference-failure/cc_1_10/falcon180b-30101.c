//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

typedef struct {
    int sock;
    struct sockaddr_in addr;
    char name[20];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(client_sock);
            break;
        }

        send(client_sock, buffer, bytes_received, 0);
    }

    close(client_sock);
}

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        printf("Waiting for client...\n");

        new_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addrlen);

        if (new_sock == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        clients[num_clients].sock = new_sock;
        strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].addr = client_addr;

        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &new_sock);
    }

    return 0;
}