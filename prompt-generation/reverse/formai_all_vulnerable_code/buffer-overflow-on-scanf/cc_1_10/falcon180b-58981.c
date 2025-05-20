//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *scan_port(void *arg) {
    int port = *(int *) arg;

    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        close(sock);
        return NULL;
    }

    close(sock);
    pthread_mutex_lock(&lock);
    ports[num_ports++] = port;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    int i, max_threads;

    printf("Enter the number of threads: ");
    scanf("%d", &max_threads);

    for (i = 1; i <= MAX_PORTS; i++) {
        ports[num_ports++] = i;
    }

    pthread_t threads[max_threads];

    for (i = 0; i < max_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &ports[i]);
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Open ports:\n");
    for (i = 0; i < num_ports; i++) {
        printf("%d ", ports[i]);
    }

    return 0;
}