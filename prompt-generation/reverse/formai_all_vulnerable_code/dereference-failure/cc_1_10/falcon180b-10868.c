//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

struct port_info {
    int port;
    char *ip;
    char *service;
};

void *scan_port(void *arg) {
    int sock = *(int *) arg;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int port;

    for (port = 1; port <= MAX_PORTS; port++) {
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
            sprintf(buffer, "Port %d is open on 127.0.0.1\n", port);
            write(sock, buffer, strlen(buffer));
        }
    }

    close(sock);
    return NULL;
}

int main() {
    int i, num_threads = 0;
    pthread_t threads[MAX_THREADS];
    int sockets[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        sockets[i] = socket(AF_INET, SOCK_STREAM, 0);
        if (sockets[i] == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            exit(1);
        }
        num_threads++;
    }

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, &sockets[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}