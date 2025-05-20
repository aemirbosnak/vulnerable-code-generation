//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    int result;

    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    result = connect(sock, (struct sockaddr *) &server, sizeof(server));

    if (result == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", port);
        } else {
            perror("connect");
        }
    } else {
        printf("Port %d is open.\n", port);
        close(sock);
    }

    return NULL;
}

int main() {
    int i, j, max_threads, port;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &max_threads);

    printf("Enter the ports to scan (comma-separated): ");
    scanf("%s", ports);

    num_ports = strlen(ports);

    for (i = 0; i < num_ports; i++) {
        if (ports[i]!= ',') {
            port = ports[i] - '0';
            pthread_create(&threads[j], NULL, scan_port, &port);
            j++;
        }
    }

    for (i = 0; i < j; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}