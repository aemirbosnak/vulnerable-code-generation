//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

struct thread_data {
    int sock;
    char ip[16];
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int bytes_received;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(data->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Thread %d received %d bytes from %s\n", pthread_self(), bytes_received, data->ip);
    }

    close(data->sock);
    free(arg);
    pthread_exit(NULL);
}

int main() {
    int server_sock, client_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int opt = 1;
    pthread_t threads[MAX_THREADS];

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_THREADS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1) {
        addrlen = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, client_addr.sin_zero, 16);
        printf("Connection from %s\n", client_addr.sin_zero);

        pthread_create(&threads[0], NULL, thread_func, (void *)&client_addr);
    }

    return 0;
}