//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

typedef struct {
    char *ip;
    int port;
} thread_data;

void *port_scan(void *arg) {
    thread_data *data = (thread_data *)arg;
    struct sockaddr_in server;
    int sock;
    char *ip = data->ip;
    int port = data->port;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    // Set timeout for connection
    struct timeval timeout;
    timeout.tv_sec = 1;  // 1 second timeout
    timeout.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

    // Try to connect
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        // Port is closed
        close(sock);
        return NULL;
    }

    // Port is open
    printf("Port %d is open on %s\n", port, ip);
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = argv[1];
    int start_port, end_port;
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2) {
        fprintf(stderr, "Invalid port range format. Use start-end.\n");
        return EXIT_FAILURE;
    }

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Port range must be between 1-65535 and start must be less than or equal to end.\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    thread_data thread_data_array[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        thread_data_array[thread_count].ip = ip;
        thread_data_array[thread_count].port = port;

        // Create a new thread for scanning the port
        if (pthread_create(&threads[thread_count], NULL, port_scan, (void *)&thread_data_array[thread_count]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
        thread_count++;

        // Limit the number of concurrent threads
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;  // Reset the counter after joining
        }
    }

    // Wait for remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s from %d to %d.\n", ip, start_port, end_port);
    return EXIT_SUCCESS;
}