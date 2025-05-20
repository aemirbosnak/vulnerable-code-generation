//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int num_threads;
pthread_t threads[MAX_THREADS];
int thread_results[MAX_THREADS];
char *ip_address;
int port_start;
int port_end;

void *scan_port(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons((unsigned short) *((int *) arg));
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
        close(sock);
        thread_results[*(int *) arg] = 1;
    } else {
        close(sock);
        thread_results[*(int *) arg] = 0;
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 5) {
        printf("Usage: %s <IP Address> <Port Start> <Port End> <Number of Threads>\n", argv[0]);
        exit(1);
    }

    ip_address = argv[1];
    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);
    num_threads = atoi(argv[4]);

    if (num_threads > MAX_THREADS) {
        printf("Maximum number of threads is %d\n", MAX_THREADS);
        exit(1);
    }

    int i;
    for (i = 0; i < num_threads; i++) {
        int port = port_start + i * (port_end - port_start) / num_threads;
        pthread_create(&threads[i], NULL, scan_port, (void *) &port);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scan complete.\n");

    return 0;
}