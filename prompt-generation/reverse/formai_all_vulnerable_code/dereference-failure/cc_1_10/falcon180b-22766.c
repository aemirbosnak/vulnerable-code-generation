//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define NUM_THREADS 10
#define MAX_REQUESTS 100

int num_threads;

struct thread_data {
    int thread_id;
    int sockfd;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;
    int sockfd = data->sockfd;

    char buffer[BUFFER_SIZE];
    int bytes_received;

    for (int i = 0; i < MAX_REQUESTS; i++) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Thread %d received data: %s\n", thread_id, buffer);
    }

    close(sockfd);
    return NULL;
}

int main() {
    int server_sockfd;
    struct sockaddr_in server_addr;
    int opt = 1;

    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sockfd, 10) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    num_threads = NUM_THREADS;

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->thread_id = i;

        if ((data->sockfd = accept(server_sockfd, NULL, NULL)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_create(&threads[i], NULL, thread_func, data);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_sockfd);

    return 0;
}