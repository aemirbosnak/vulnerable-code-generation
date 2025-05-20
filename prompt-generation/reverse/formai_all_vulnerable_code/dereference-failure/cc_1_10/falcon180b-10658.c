//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define MAX_REQUEST_SIZE 1024
#define PORT 8080

typedef struct {
    int client_socket;
    char request[MAX_REQUEST_SIZE];
    struct sockaddr_in client_addr;
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *) arg;
    char response[1024];
    sprintf(response, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", strlen("<html><body><h1>Hello, World!</h1></body></html>"));
    send(client->client_socket, response, strlen(response), 0);
    close(client->client_socket);
    free(client);
    return NULL;
}

void accept_connection(int server_socket) {
    client_t *client = (client_t *) malloc(sizeof(client_t));
    memset(client, 0, sizeof(client_t));
    client->client_socket = accept(server_socket, (struct sockaddr *) &client->client_addr, NULL);
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, handle_client, client);
    pthread_detach(thread_id);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("bind failed\n");
        exit(2);
    }

    if (listen(server_socket, BACKLOG) < 0) {
        printf("listen failed\n");
        exit(3);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        accept_connection(server_socket);
    }

    return 0;
}