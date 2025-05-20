#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10

void *scan_port(int port) {
    int sockfd, err;
    struct sockaddr_in sock_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        return NULL;
    }

    sock_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        perror("Error connecting to port");
        close(sockfd);
        return NULL;
    }

    close(sockfd);
    return NULL;
}

int main() {
    int start, end, port;
    pthread_t threads[MAX_THREADS];

    printf("Enter the starting port: ");
    scanf("%d", &start);

    printf("Enter the ending port: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Error: start port must be less than or equal to end port.\n");
        return 1;
    }

    for (port = start; port <= end; port++) {
        pthread_create(&threads[port], NULL, scan_port, (void *)port);
    }

    for (port = start; port <= end; port++) {
        pthread_join(threads[port], NULL);
    }

    return 0;
}
