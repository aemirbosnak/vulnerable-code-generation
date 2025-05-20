//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <math.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100

int ports[MAX_PORTS];
int num_ports = 0;
pthread_t threads[MAX_THREADS];
int thread_count = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        printf("Port %d is open.\n", port);
        close(sock);
    } else {
        printf("Port %d is closed.\n", port);
    }

    return NULL;
}

int main() {
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (int i = 1; i <= num_ports; i++) {
        ports[i - 1] = i;
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_create(&threads[thread_count], NULL, scan_port, &ports[i]);
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}