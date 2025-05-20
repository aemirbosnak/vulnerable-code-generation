//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: distributed
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

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_port;
char target_ip[16];
int num_threads;
pthread_t threads[MAX_THREADS];

void *scan_thread(void *arg) {
    int thread_id = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Thread %d: Error creating socket\n", thread_id);
        return NULL;
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    inet_pton(AF_INET, target_ip, &target_addr.sin_addr);
    target_addr.sin_port = htons(target_port + thread_id);

    if (connect(sock, (struct sockaddr *) &target_addr, sizeof(target_addr)) == -1) {
        printf("Thread %d: Port %d is closed\n", thread_id, target_port + thread_id);
        close(sock);
        return NULL;
    }

    printf("Thread %d: Port %d is open\n", thread_id, target_port + thread_id);
    close(sock);
    return NULL;
}

int main() {
    printf("Enter target IP address: ");
    scanf("%s", target_ip);

    printf("Enter starting port number: ");
    scanf("%d", &target_port);

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Error: Number of threads exceeds maximum limit\n");
        return 1;
    }

    for (int i = 0; i < num_threads; i++) {
        int thread_id = i + 1;
        pthread_create(&threads[i], NULL, scan_thread, (void *) &thread_id);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}