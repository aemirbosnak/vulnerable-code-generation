//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 500
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

int open_ports[PORT_RANGE_END - PORT_RANGE_START + 1] = {0};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* scan_port(void* arg) {
    int port = *(int*)arg;
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to target IP

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) >= 0) {
        pthread_mutex_lock(&mutex);
        open_ports[port - PORT_RANGE_START] = 1; // Mark the port as open
        pthread_mutex_unlock(&mutex);
    }

    close(sock);
    return NULL;
}

void print_open_ports(int host_port_range_start, int host_port_range_end) {
    printf("Open ports:\n");
    for (int i = host_port_range_start; i <= host_port_range_end; i++) {
        if (open_ports[i - PORT_RANGE_START]) {
            printf("Port %d is open.\n", i);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Host IP> <Port Range (e.g., 20-80)>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host_ip = argv[1];
    int port_range_start, port_range_end;
    sscanf(argv[2], "%d-%d", &port_range_start, &port_range_end);

    if (port_range_start < PORT_RANGE_START || port_range_end > PORT_RANGE_END ||
        port_range_start > port_range_end) {
        fprintf(stderr, "Error: Port range must be between %d and %d\n", PORT_RANGE_START, PORT_RANGE_END);
        exit(EXIT_FAILURE);
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    
    for (int port = port_range_start; port <= port_range_end; port++) {
        if (thread_count >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0; // Reset thread counter after joining
        }
        int* port_num = malloc(sizeof(int));
        *port_num = port;

        if (pthread_create(&threads[thread_count], NULL, scan_port, port_num) != 0) {
            perror("Failed to create thread");
            free(port_num);
            exit(EXIT_FAILURE);
        }
        thread_count++;
    }

    // Wait for any remaining threads to finish
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    print_open_ports(port_range_start, port_range_end);
    return 0;
}