//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

int port_range_start;
int port_range_end;
int thread_count = 0;
pthread_t threads[MAX_THREADS];

void *scan_ports(void *arg) {
    int thread_id = *(int *) arg;
    int port = port_range_start + (thread_id * (port_range_end - port_range_start)) / thread_count;

    while (port <= port_range_end) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            perror("socket");
            continue;
        }

        struct sockaddr_in server;
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
            printf("Port %d is open.\n", port);
            close(sock);
        } else {
            printf("Port %d is closed.\n", port);
        }

        port++;
    }

    return NULL;
}

int main() {
    printf("Enter the starting port: ");
    scanf("%d", &port_range_start);
    printf("Enter the ending port: ");
    scanf("%d", &port_range_end);

    printf("Enter the number of threads: ");
    scanf("%d", &thread_count);

    if (thread_count > MAX_THREADS || thread_count <= 0) {
        printf("Invalid number of threads.\n");
        return 1;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, scan_ports, (void *) &i);
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}