//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

#define MAX_THREADS 10

typedef struct {
    int sock;
    struct sockaddr_in address;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char buffer[1024];
    int bytes_received;

    while (TRUE) {
        bytes_received = recv(data->sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Thread %d received: %s\n", data->address.sin_port, buffer);
    }

    close(data->sock);
    free(data);
    pthread_exit(NULL);
}

int main() {
    int server_sock, client_sock, new_sock, max_clients = 10, port = 8080;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t threads[MAX_THREADS];
    int i, thread_count = 0;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, max_clients) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        addr_size = sizeof(client_addr);
        if ((new_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addr_size)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (thread_count >= MAX_THREADS) {
            printf("Maximum number of threads reached.\n");
            close(new_sock);
            continue;
        }

        thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));
        data->sock = new_sock;
        data->address.sin_family = AF_INET;
        data->address.sin_port = htons(port);
        data->address.sin_addr.s_addr = client_addr.sin_addr.s_addr;
        pthread_create(&threads[thread_count], NULL, thread_func, data);
        thread_count++;
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_sock);
    return 0;
}