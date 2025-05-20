//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_ports(void *arg) {
    int sock, port;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    for (port = *(int *) arg; port <= *(int *) arg + 10; port++) {
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("127.0.0.1");
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
            return NULL;
        }
    }

    close(sock);
    return NULL;
}

int main() {
    int i, j, max_threads = 0;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (i = 1; i <= num_ports; i++) {
        ports[i] = i;
    }

    for (i = 0; i < num_ports; i += MAX_PORTS / num_ports) {
        for (j = i; j < i + MAX_PORTS / num_ports && j < num_ports; j++) {
            pthread_create(&threads[max_threads], NULL, scan_ports, &ports[j]);
            max_threads++;
        }

        for (j = 0; j < max_threads; j++) {
            pthread_join(threads[j], NULL);
        }

        max_threads = 0;
    }

    return 0;
}