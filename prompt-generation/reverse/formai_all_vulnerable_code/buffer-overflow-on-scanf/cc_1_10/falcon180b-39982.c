//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scanned_ports[MAX_PORTS];

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    int result = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (result == 0) {
        scanned_ports[port] = 1;
        close(sock);
    } else {
        scanned_ports[port] = 0;
        close(sock);
    }
    return NULL;
}

int main() {
    int num_threads = 0;
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, (void *) &i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_PORTS; i++) {
        if (scanned_ports[i] == 0) {
            printf("Port %d is closed.\n", i);
        }
    }

    return 0;
}