//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535

int ports[MAX_PORTS];
int num_ports = 0;

void *scan_port(void *arg) {
    int port = *(int *) arg;
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return NULL;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        close(sockfd);
        return NULL;
    }

    close(sockfd);
    printf("Port %d is open\n", port);
    return NULL;
}

int main() {
    int i, maxfd, clientfd;
    struct sockaddr_in servaddr;
    pthread_t thread_id[MAX_THREADS];

    printf("Enter number of ports to scan: ");
    scanf("%d", &num_ports);

    for (i = 0; i < num_ports; i++) {
        ports[i] = i + 1;
    }

    printf("Enter IP address: ");
    scanf("%s", &servaddr.sin_addr.s_addr);

    maxfd = socket(AF_INET, SOCK_STREAM, 0);
    if (maxfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);

    if (bind(maxfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    listen(maxfd, 5);

    for (i = 0; i < num_ports; i++) {
        printf("Scanning port %d...\n", ports[i]);
        pthread_create(&thread_id[i], NULL, scan_port, &ports[i]);
    }

    for (i = 0; i < num_ports; i++) {
        pthread_join(thread_id[i], NULL);
    }

    close(maxfd);
    return 0;
}