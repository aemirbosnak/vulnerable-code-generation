//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_THREADS 10
#define SERVER_PORT 8080

struct request {
    int sock;
    char data[MAX_REQUEST_SIZE];
};

void *handle_request(void *arg) {
    struct request *req = arg;
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 13\r\n\r\nHello, World!";
    send(req->sock, response, strlen(response), 0);
    close(req->sock);
    free(req);
    return NULL;
}

int main() {
    int server_sock, client_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[MAX_THREADS];

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_THREADS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        addrlen = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            perror("accept");
            continue;
        }

        struct request *req = malloc(sizeof(struct request));
        req->sock = client_sock;
        memset(req->data, 0, MAX_REQUEST_SIZE);

        pthread_create(&threads[0], NULL, handle_request, req);
    }

    return 0;
}