//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 10
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports;

void *thread_func(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        close(sock);
        ports[port] = 1;
    } else {
        ports[port] = 0;
    }
    return NULL;
}

int main() {
    int i, max_threads;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of ports to scan: ");
    scanf("%d", &num_ports);

    for (i = 0; i < num_ports; i++) {
        ports[i] = 0;
    }

    max_threads = num_ports;
    if (max_threads > MAX_THREADS) {
        max_threads = MAX_THREADS;
    }

    for (i = 0; i < max_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scan complete.\n");
    for (i = 0; i < num_ports; i++) {
        if (ports[i] == 1) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    return 0;
}