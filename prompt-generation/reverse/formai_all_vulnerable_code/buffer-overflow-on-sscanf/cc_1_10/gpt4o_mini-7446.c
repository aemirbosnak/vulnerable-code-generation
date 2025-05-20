//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_THREADS 200
#define TIMEOUT 1

typedef struct {
    char *ip_address;
    int port;
} port_info;

void *scan_port(void *arg) {
    port_info *info = (port_info *)arg;
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    server.sin_family = AF_INET;
    server.sin_port = htons(info->port);
    server.sin_addr.s_addr = inet_addr(info->ip_address);

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result >= 0) {
        printf("Port %d is open on %s\n", info->port, info->ip_address);
    } else {
        // The port is closed or unreachable
    }

    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range (e.g., 1-100)>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port, end_port;
    sscanf(argv[2], "%d-%d", &start_port, &end_port);

    if (start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        port_info *info = malloc(sizeof(port_info));
        if (info == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        info->ip_address = ip_address;
        info->port = port;

        if (pthread_create(&threads[thread_count++], NULL, scan_port, info) != 0) {
            perror("Failed to create thread");
            free(info);
            continue;
        }

        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset count after joining
        }
    }

    // Join any remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}