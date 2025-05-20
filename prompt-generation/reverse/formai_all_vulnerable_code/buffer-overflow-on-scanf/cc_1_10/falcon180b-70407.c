//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 50
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;
pthread_mutex_t mutex;

void *scan_ports(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = thread_id * (MAX_PORTS / MAX_THREADS) + 1;
    int end_port = (thread_id == MAX_THREADS - 1)? MAX_PORTS : (thread_id + 1) * (MAX_PORTS / MAX_THREADS);

    for (int port = start_port; port <= end_port; port++) {
        pthread_mutex_lock(&mutex);
        if (ports[port] == 0) {
            ports[port] = 1;
        }
        pthread_mutex_unlock(&mutex);

        if (ports[port] == 1) {
            printf("Port %d is open\n", port);
        }
    }

    return NULL;
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS || num_threads <= 0) {
        printf("Invalid number of threads\n");
        exit(1);
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, scan_ports, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}