//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

int port_range[2] = {PORT_RANGE_MIN, PORT_RANGE_MAX};
int num_threads = 1;
int thread_id[MAX_THREADS];
int thread_socket[MAX_THREADS];

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    int thread_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (thread_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    char ip_address[16] = {0};
    sprintf(ip_address, "127.0.0.%d", thread_id + 1);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_range[0]);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(thread_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to %s:%d: %s\n", ip_address, port_range[0], strerror(errno));
        close(thread_socket);
        exit(1);
    }

    close(thread_socket);
}

int main() {
    printf("Enter number of threads (1-100): ");
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        exit(1);
    }

    pthread_t thread_id_array[MAX_THREADS];
    for (int i = 0; i < num_threads; i++) {
        thread_id[i] = i + 1;
        pthread_create(&thread_id_array[i], NULL, thread_func, (void *) &thread_id[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread_id_array[i], NULL);
    }

    return 0;
}