//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define TIMEOUT 1

typedef struct {
    char *host;
    int port;
} thread_data;

void *scan_port(void *arg) {
    thread_data *data = (thread_data *)arg;
    int sockfd;
    struct sockaddr_in target;

    // Initialize the target address structure
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(data->port);
    
    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, data->host, &target.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        pthread_exit(NULL);
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Set the timeout for connecting
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    // Attempt to connect to the target port
    if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) < 0) {
        // Port is closed
        close(sockfd);
        pthread_exit(NULL);
    }

    // If we reached here, the port is open
    printf("Port %d is open on %s\n", data->port, data->host);
    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port range (e.g., 1-1024)>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    int start_port, end_port;

    // Parse provided port range
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2 || start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range.\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        // Prepare data for the thread
        data[thread_count].host = host;
        data[thread_count].port = port;

        // Create a thread to scan the port
        if (pthread_create(&threads[thread_count], NULL, scan_port, &data[thread_count]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }

        thread_count++;

        // Join threads if the maximum count has been reached
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread count
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed on %s.\n", host);
    return EXIT_SUCCESS;
}