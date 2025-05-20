//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *thread_func(void *arg) {
    int port = *(int *) arg;

    struct sockaddr_in server_addr;
    int sockfd;
    int addrlen;
    int ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    addrlen = sizeof(server_addr);

    ret = connect(sockfd, (struct sockaddr *) &server_addr, addrlen);
    if (ret == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", port);
        } else {
            perror("connect");
        }
        close(sockfd);
        return NULL;
    }

    close(sockfd);
    return NULL;
}

int main() {
    int i, j, max_threads;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (i = 1; i <= num_ports; i++) {
        ports[i - 1] = i;
    }

    max_threads = num_ports;
    if (max_threads > MAX_THREADS) {
        max_threads = MAX_THREADS;
    }

    for (i = 0; i < max_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &ports[i]);
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}