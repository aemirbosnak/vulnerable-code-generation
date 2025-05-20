//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket for port %d\n", port);
        return NULL;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
    } else {
        printf("Port %d is closed\n", port);
        close(sock);
    }

    return NULL;
}

int main() {
    printf("Enter number of ports to scan: ");
    scanf("%d", &num_ports);

    for (int i = 0; i < num_ports; i++) {
        ports[i] = i;
    }

    int num_threads = num_ports;

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}