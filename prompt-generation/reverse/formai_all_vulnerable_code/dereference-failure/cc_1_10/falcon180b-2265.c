//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 50
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

int port_range[2] = {PORT_RANGE_MIN, PORT_RANGE_MAX};

void *thread_port_scanner(void *arg);

int main(int argc, char **argv) {
    int num_threads = 1;
    pthread_t threads[MAX_THREADS];

    if (argc > 1) {
        num_threads = atoi(argv[1]);
    }

    if (num_threads > MAX_THREADS) {
        printf("Error: Number of threads exceeds maximum limit.\n");
        return 1;
    }

    for (int i = 0; i < num_threads; i++) {
        int port_start = port_range[0] + (port_range[1] - port_range[0]) / num_threads * i;
        int port_end = port_range[0] + (port_range[1] - port_range[0]) / num_threads * (i + 1) - 1;

        pthread_create(&threads[i], NULL, thread_port_scanner, (void *)&port_start);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread_port_scanner(void *arg) {
    int port_start = *((int *) arg);

    for (int i = port_start; i <= port_range[1]; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            printf("Error: Failed to create socket.\n");
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed.\n", i);
            } else {
                printf("Error: Failed to connect to port %d.\n", i);
            }
        } else {
            printf("Port %d is open.\n", i);
        }

        close(sock);
    }

    return NULL;
}