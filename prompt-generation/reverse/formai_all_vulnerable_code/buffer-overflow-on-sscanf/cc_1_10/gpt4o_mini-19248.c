//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define TIMEOUT 1
#define MAX_THREADS 200

typedef struct {
    char *ip_address;
    int port;
} port_scan_t;

void *scan_port(void *arg) {
    port_scan_t *port_info = (port_scan_t *) arg;
    int sock;
    struct sockaddr_in server;

    // Creating a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error creating socket for port %d: %s\n", port_info->port, strerror(errno));
        free(port_info);
        return NULL;
    }

    // Set timeout for socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Initialize the sockaddr_in structure
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port_info->port);
    
    if (inet_pton(AF_INET, port_info->ip_address, &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address for port %d: %s\n", port_info->port, strerror(errno));
        close(sock);
        free(port_info);
        return NULL;
    }

    // Attempt to connect to the port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stdout, "Port %d is closed.\n", port_info->port);
    } else {
        fprintf(stdout, "Port %d is open!\n", port_info->port);
    }

    close(sock);
    free(port_info);
    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <START_PORT>-<END_PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *ip_address = argv[1];
    int start_port, end_port;

    // Parsing port range
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2 ||
        start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range. Please specify a range between %d and %d.\n", MIN_PORT, MAX_PORT);
        exit(EXIT_FAILURE);
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    for (int port = start_port; port <= end_port; port++) {
        if (thread_count >= MAX_THREADS) {
            fprintf(stderr, "Maximum thread limit reached. Please try a smaller range.\n");
            break;
        }

        port_scan_t *port_info = malloc(sizeof(port_scan_t));
        port_info->ip_address = ip_address;
        port_info->port = port;

        if (pthread_create(&threads[thread_count++], NULL, scan_port, port_info) != 0) {
            fprintf(stderr, "Error creating thread for port %d: %s\n", port, strerror(errno));
            free(port_info);
            continue; // Skip to next port on error
        }

        // Optional: Sleep between creating threads to avoid overwhelming network
        usleep(50000); // 50ms delay
    }

    // Joining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}