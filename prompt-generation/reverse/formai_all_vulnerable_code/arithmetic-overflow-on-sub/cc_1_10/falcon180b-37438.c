//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

struct host_info {
    char *ip;
    int port;
};

void *scan_port(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sockfd, ret;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(host->port);
    inet_pton(AF_INET, host->ip, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr_in));
    if (ret == -1) {
        fprintf(stdout, "Port %d on %s is closed\n", host->port, host->ip);
    } else {
        fprintf(stdout, "Port %d on %s is open\n", host->port, host->ip);
        close(sockfd);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port, end_port;

    if (sscanf(argv[2], "%d-%d", &start_port, &end_port)!= 2) {
        fprintf(stderr, "Invalid port range\n");
        return 1;
    }

    int num_threads = end_port - start_port + 1;
    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Number of threads exceeds maximum limit\n");
        return 1;
    }

    pthread_t threads[num_threads];
    struct host_info hosts[num_threads];

    for (int i = 0; i < num_threads; i++) {
        hosts[i].ip = ip;
        hosts[i].port = start_port + i;
        pthread_create(&threads[i], NULL, scan_port, &hosts[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}