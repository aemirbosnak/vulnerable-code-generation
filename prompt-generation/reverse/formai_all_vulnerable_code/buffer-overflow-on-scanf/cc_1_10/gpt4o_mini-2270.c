//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORT 65535
#define MIN_PORT 1

int total_ports = MAX_PORT - MIN_PORT + 1;
int active_threads = 0;
pthread_mutex_t lock;

typedef struct {
    char *ip_address;
    int port_start;
    int port_end;
} thread_data;

void *scan_port(void *arg) {
    thread_data *data = (thread_data *)arg;
    int sock;
    struct sockaddr_in server;

    for (int port = data->port_start; port <= data->port_end; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation failed");
            continue;
        }

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr(data->ip_address);
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
            printf("Port %d is open on %s\n", port, data->ip_address);
        }

        close(sock);
    }

    pthread_mutex_lock(&lock);
    active_threads--;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void create_threads(char *ip_address, int ports_per_thread) {
    pthread_t threads[MAX_THREADS];
    thread_data thread_args[MAX_THREADS];
    int thread_count = 0;

    for (int i = MIN_PORT; i <= MAX_PORT; i += ports_per_thread) {
        if (thread_count >= MAX_THREADS) {
            printf("Maximum thread limit reached. Waiting for threads to finish.\n");
            for (int j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }

        thread_args[thread_count].ip_address = ip_address;
        thread_args[thread_count].port_start = i;
        thread_args[thread_count].port_end = (i + ports_per_thread - 1 > MAX_PORT) ? 
                                MAX_PORT : i + ports_per_thread - 1;

        pthread_mutex_lock(&lock);
        active_threads++;
        pthread_mutex_unlock(&lock);

        pthread_create(&threads[thread_count], NULL, scan_port, &thread_args[thread_count]);
        thread_count++;
    }

    for (int j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }
}

int main() {
    char ip_address[16];
    int ports_per_thread;

    printf("Enter the IP address to scan: ");
    scanf("%15s", ip_address);

    printf("Enter the number of ports to scan per thread (e.g., 100): ");
    scanf("%d", &ports_per_thread);
    
    if (ports_per_thread <= 0 || ports_per_thread > MAX_PORT) {
        fprintf(stderr, "Invalid number of ports\n");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&lock, NULL);
    
    create_threads(ip_address, ports_per_thread);

    pthread_mutex_destroy(&lock);
    printf("Port scanning completed!\n");
    return 0;
}