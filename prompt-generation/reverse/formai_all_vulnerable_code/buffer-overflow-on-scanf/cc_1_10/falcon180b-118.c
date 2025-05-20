//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int scan_port(int sock, int port) {
    struct sockaddr_in server;
    int opt = 1;

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

void *scan_thread(void *arg) {
    int *port = (int *) arg;

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    if (scan_port(sock, *port)) {
        printf("Port %d is open\n", *port);
    } else {
        printf("Port %d is closed\n", *port);
    }

    close(sock);
    return NULL;
}

int main() {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Error: Number of threads cannot exceed %d\n", MAX_THREADS);
        return 1;
    }

    for (i = 0; i < num_threads; i++) {
        int port = i + 1;
        pthread_create(&threads[i], NULL, scan_thread, (void *)&port);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}