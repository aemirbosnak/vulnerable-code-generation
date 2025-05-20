//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int port;
char *ip;
int num_threads;
int thread_id;

void *scan_port(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
    }

    close(sock);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <ip> <port> <num_threads>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    pthread_t threads[MAX_THREADS];
    int rc;

    for (int i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, scan_port, (void *)i);
        if (rc) {
            printf("Error creating thread: %s\n", strerror(rc));
            exit(1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}