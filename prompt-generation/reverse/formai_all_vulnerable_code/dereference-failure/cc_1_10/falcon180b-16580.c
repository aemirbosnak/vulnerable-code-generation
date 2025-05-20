//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 50
#define BUFFER_SIZE 1024

int port;
char *ip;
int num_threads;

void *thread_func(void *arg) {
    int sock = *(int *) arg;

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(sock);
            pthread_exit(0);
        }

        printf("Thread %d received: %s\n", sock, buffer);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <port number> <number of threads>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    if (num_threads > MAX_THREADS) {
        printf("Error: Maximum number of threads is %d\n", MAX_THREADS);
        return 1;
    }

    int master_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (master_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(master_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(master_socket);
        return 1;
    }

    printf("Connected to server\n");

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &master_socket);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(master_socket);

    return 0;
}