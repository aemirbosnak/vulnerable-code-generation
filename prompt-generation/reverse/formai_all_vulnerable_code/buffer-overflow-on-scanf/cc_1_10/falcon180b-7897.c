//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int scanned_ports[MAX_PORTS];
int num_open_ports = 0;

void *port_scanner(void *arg) {
    int port = *(int *) arg;
    int sockfd;
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return NULL;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt))) {
        perror("setsockopt");
        close(sockfd);
        return NULL;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
        close(sockfd);
        scanned_ports[port] = 1;
        num_open_ports++;
    } else {
        close(sockfd);
    }

    return NULL;
}

int main() {
    int i, j, max_threads;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &max_threads);

    for (i = 0; i < max_threads; i++) {
        pthread_create(&threads[i], NULL, port_scanner, (void *) &i);
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total open ports: %d\n", num_open_ports);

    return 0;
}