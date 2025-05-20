//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: irregular
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
} port_scan_t;

void *scan_port(void *arg) {
    port_scan_t *scan_info = (port_scan_t *)arg;
    int sock;
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(scan_info->port);
    target.sin_addr.s_addr = inet_addr(scan_info->ip);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        free(scan_info);
        return NULL;
    }

    // Set timeout for the connection
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Try to connect
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d: OPEN\n", scan_info->port);
    } else {
        printf("Port %d: CLOSED\n", scan_info->port);
    }

    close(sock);
    free(scan_info);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP> <PortStart-PortEnd>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = argv[1];
    int port_start, port_end;
    sscanf(argv[2], "%d-%d", &port_start, &port_end);
  
    if (port_start < 1 || port_end > 65535 || port_start > port_end) {
        printf("Invalid port range.\n");
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = port_start; port <= port_end; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }

        port_scan_t *scan_info = malloc(sizeof(port_scan_t));
        scan_info->ip = ip;
        scan_info->port = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, scan_info) != 0) {
            printf("Failed to create thread for port %d.\n", port);
            free(scan_info);
            continue;
        }
        
        thread_count++;
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}