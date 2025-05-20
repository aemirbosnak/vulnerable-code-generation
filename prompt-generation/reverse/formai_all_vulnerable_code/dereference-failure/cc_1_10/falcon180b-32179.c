//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char ip[16];
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message from %s: %s\n", client->ip, buffer);
    }

    close(client->sock);
    free(client);

    return NULL;
}

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

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

    while (1) {
        if ((new_sock = accept(server_sock, (struct sockaddr *)&client_addr, sizeof(client_addr))) == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char ip[16];
        inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));

        struct client_data *client = (struct client_data *) malloc(sizeof(struct client_data));
        client->sock = new_sock;
        strcpy(client->ip, ip);

        if (pthread_create(&thread_id, NULL, handle_client, client)!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    return 0;
}