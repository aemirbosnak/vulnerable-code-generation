//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *ip;
    int port;
} thread_data_t;

void *check_port(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    int sock;
    struct sockaddr_in server;
    struct timeval tv;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Set timeout for socket connection
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));

    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    server.sin_addr.s_addr = inet_addr(data->ip);

    // Connect and check if port is open
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) >= 0) {
        printf("Port %d is OPEN\n", data->port);
    } else {
        printf("Port %d is CLOSED\n", data->port);
    }

    close(sock);
    free(data);
    return NULL;
}

int main() {
    char target_ip[16];
    int start_port, end_port;
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    printf("Welcome to the C Port Scanner!\n");
    printf("Enter the IP address to scan: ");
    scanf("%15s", target_ip);
    printf("Enter the starting port: ");
    scanf("%d", &start_port);
    printf("Enter the ending port: ");
    scanf("%d", &end_port);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range.\n");
        exit(EXIT_FAILURE);
    }

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            // Wait for all threads to finish if we reach max thread count
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread counter
        }

        // Allocate memory for thread data and create a thread
        thread_data_t *data = (thread_data_t *)malloc(sizeof(thread_data_t));
        data->ip = strdup(target_ip);
        data->port = port;

        if (pthread_create(&threads[thread_count++], NULL, check_port, data) != 0) {
            fprintf(stderr, "Error creating thread for port %d\n", port);
            free(data->ip);
            free(data);
            continue;
        }
    }

    // Wait for remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed!\n");
    return 0;
}