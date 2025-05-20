//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

int open_ports[1024];
int port_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *scan_port(void *arg) {
    int port = *(int *)arg;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    
    // Use ipv4 address
    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        printf("Invalid address\n");
        return NULL;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Attempt to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        pthread_mutex_lock(&mutex);
        open_ports[port_count++] = port;
        printf("Port %d is open\n", port);
        pthread_mutex_unlock(&mutex);
    }
    close(sock);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int port_numbers[MAX_THREADS];
    int start_port, end_port;

    printf("Welcome to the C Port Scanner!\n");
    printf("Enter the start port: ");
    scanf("%d", &start_port);
    printf("Enter the end port: ");
    scanf("%d", &end_port);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range.\n");
        return 1;
    }

    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        port_numbers[thread_count] = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, (void *)&port_numbers[thread_count]) != 0) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
            return 1;
        }

        thread_count++;
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // reset for the next batch
        }
    }

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print open ports
    if (port_count > 0) {
        printf("\nSummary of open ports:\n");
        for (int i = 0; i < port_count; i++) {
            printf("Open Port: %d\n", open_ports[i]);
        }
    } else {
        printf("No open ports found in the specified range.\n");
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}