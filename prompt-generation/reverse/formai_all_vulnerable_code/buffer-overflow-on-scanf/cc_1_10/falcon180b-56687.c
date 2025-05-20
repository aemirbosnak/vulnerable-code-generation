//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int ports[MAX_PORTS];

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (result == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
        close(sock);
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving data from port %d\n", port);
        close(sock);
        return NULL;
    }

    printf("Port %d is open and responding with:\n%s", port, buffer);
    close(sock);
    return NULL;
}

int main() {
    int num_threads = 1;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of threads (1-%d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    int i;
    for (i = 0; i < num_threads; i++) {
        int port = 1 + i * (MAX_PORTS / num_threads);
        ports[i] = port;
        pthread_create(&threads[i], NULL, scan_port, (void *) &port);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}