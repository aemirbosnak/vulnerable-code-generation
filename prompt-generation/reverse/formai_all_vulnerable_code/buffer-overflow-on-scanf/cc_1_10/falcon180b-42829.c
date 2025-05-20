//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_ports(void *arg) {
    int start_port = *(int *) arg;
    int end_port = start_port + MAX_PORTS / num_ports;

    for (int port = start_port; port < end_port; port++) {
        if (ports[port] == 0) {
            ports[port] = 1;
            printf("Port %d is open.\n", port);
        }
    }

    return NULL;
}

int main() {
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Error: Number of threads exceeds limit.\n");
        return 1;
    }

    printf("Enter ports to scan (comma-separated): ");
    char input[BUFFER_SIZE];
    scanf("%[^\n]", input);

    char *port_str = strtok(input, ",");
    while (port_str!= NULL) {
        int port = atoi(port_str);
        if (port <= 0 || port > MAX_PORTS) {
            printf("Error: Invalid port number.\n");
            return 1;
        }
        ports[port] = 0;
        port_str = strtok(NULL, ",");
        num_ports++;
    }

    for (int i = 0; i < num_threads; i++) {
        int start_port = i * MAX_PORTS / num_threads;
        int end_port = (i + 1) * MAX_PORTS / num_threads;
        pthread_create(&threads[i], NULL, scan_ports, &start_port);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}