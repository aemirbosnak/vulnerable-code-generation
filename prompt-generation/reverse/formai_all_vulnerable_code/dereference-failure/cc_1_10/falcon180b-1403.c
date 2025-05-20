//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

struct thread_data {
    int sock;
    struct sockaddr_in server_addr;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        int bytes_received = recv(data->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(data->sock);
            free(arg);
            return NULL;
        }

        printf("Thread %d received %d bytes: %s\n", data->sock, bytes_received, buffer);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, MAX_THREADS) == -1) {
        printf("Error listening on socket\n");
        close(server_socket);
        return 1;
    }

    printf("Server started on port %s\n", argv[1]);

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addrlen);

        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client connected on socket %d\n", new_socket);

        struct thread_data *data = malloc(sizeof(struct thread_data));

        data->sock = new_socket;
        memcpy(&data->server_addr, &server_addr, sizeof(server_addr));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_func, data);
    }

    close(server_socket);
    return 0;
}