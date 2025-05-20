//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char ip[INET_ADDRSTRLEN];
    int port;
};

void *handle_client(void *arg) {
    struct client_data *data = (struct client_data *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(data->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received message from %s:%d: %s\n", data->ip, data->port, buffer);
    }

    close(data->sock);
    free(data);
    return NULL;
}

int main() {
    int server_sock, client_sock, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    pthread_t thread_id;
    struct client_data *client_data;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, BACKLOG) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        addrlen = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, client_data->ip, INET_ADDRSTRLEN);
        client_data->port = ntohs(client_addr.sin_port);

        if (pthread_create(&thread_id, NULL, handle_client, (void *) client_data)!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    return 0;
}