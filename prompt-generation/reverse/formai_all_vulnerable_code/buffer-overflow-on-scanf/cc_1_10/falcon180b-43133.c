//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PORTS 1000
#define BUFF_SIZE 1024

struct hostent *server;
int sock;
int port_range[MAX_PORTS];
int num_threads;
pthread_t threads[MAX_THREADS];

void *scan_ports(void *arg) {
    int start_port = *(int *) arg;
    char buffer[BUFF_SIZE];
    int bytes_received;
    int port;

    for (port = start_port; port <= start_port + MAX_PORTS / num_threads; port++) {
        if (connect(sock, (struct sockaddr *) &server->h_addr, server->h_length) == 0) {
            sprintf(buffer, "Port %d is open\n", port);
            write(sock, buffer, strlen(buffer));
        } else {
            sprintf(buffer, "Port %d is closed\n", port);
            write(sock, buffer, strlen(buffer));
        }
    }

    return NULL;
}

int main() {
    int i, j;
    char hostname[BUFF_SIZE];
    char *ports_str;
    int num_ports;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    server = gethostbyname(hostname);

    if (server == NULL) {
        printf("Invalid hostname\n");
        exit(1);
    }

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter number of ports to scan: ");
    scanf("%d", &num_ports);

    for (i = 0; i < num_threads; i++) {
        port_range[i] = i * (num_ports / num_threads) + 1;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_ports, (void *) &port_range[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);

    return 0;
}