//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUF_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in peer;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char buf[BUF_SIZE];
    int n;

    while ((n = recv(data->sock, buf, BUF_SIZE, 0)) > 0) {
        buf[n] = '\0';
        printf("Thread %d received: %s\n", data->sock, buf);
    }

    close(data->sock);
    free(data);

    return NULL;
}

int main() {
    int server_sock, client_sock, new_sock, max_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[MAX_THREADS];
    int i, num_threads = 0;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, MAX_THREADS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    addrlen = sizeof(struct sockaddr_in);

    while (1) {
        if ((new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        if (num_threads >= MAX_THREADS) {
            printf("Maximum number of threads reached\n");
            close(new_sock);
            continue;
        }

        thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));
        data->sock = new_sock;
        memcpy(&data->peer, &client_addr, sizeof(struct sockaddr_in));

        if (pthread_create(&threads[num_threads], NULL, thread_func, data)) {
            printf("Error creating thread\n");
            free(data);
        } else {
            num_threads++;
        }
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_sock);
    return 0;
}