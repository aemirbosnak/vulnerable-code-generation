//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUF_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void *thread(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUF_SIZE];

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        error("bind");
    }

    if (listen(server_socket, 10) == -1) {
        error("listen");
    }

    printf("Server listening on port %s\n", argv[1]);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len);

        if (client_socket == -1) {
            error("accept");
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread, &client_socket);
    }

    return 0;
}