//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

struct connection {
    int sock;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    int buffer_len;
};

void *handle_connection(void *arg) {
    struct connection *conn = (struct connection *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(conn->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received %s\n", buffer);
    }

    close(conn->sock);
    free(conn);
}

int main() {
    int listen_sock, new_sock;
    struct sockaddr_in listen_addr, client_addr;
    int addr_len, opt = 1;
    pthread_t thread_id;
    struct connection *conn;

    if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(8080);

    if (bind(listen_sock, (struct sockaddr *) &listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        addr_len = sizeof(client_addr);
        if ((new_sock = accept(listen_sock, (struct sockaddr *) &client_addr, &addr_len)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (pthread_create(&thread_id, NULL, handle_connection, (void *) &client_addr)!= 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}