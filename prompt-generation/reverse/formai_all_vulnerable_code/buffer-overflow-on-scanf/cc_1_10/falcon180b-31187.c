//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

int port_range[2] = {PORT_RANGE_MIN, PORT_RANGE_MAX};
int thread_count = 1;
int thread_id[MAX_THREADS];

void *scan_ports(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = port_range[0] + (thread_id - 1) * (port_range[1] - port_range[0]) / thread_count;
    int end_port = start_port + (port_range[1] - port_range[0]) / thread_count;

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;

        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
            close(sock);
            printf("Port %d is open on thread %d\n", port, thread_id);
        } else {
            close(sock);
        }
    }

    return NULL;
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        return 1;
    }

    thread_count = num_threads;
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < thread_count; i++) {
        int rc = pthread_create(&threads[i], NULL, scan_ports, (void *) &i);
        if (rc) {
            printf("Error creating thread: %s\n", strerror(rc));
            return 1;
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}