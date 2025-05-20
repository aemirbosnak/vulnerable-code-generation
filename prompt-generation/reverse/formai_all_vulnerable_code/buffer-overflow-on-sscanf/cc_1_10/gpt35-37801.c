//FormAI DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

struct thread_args {
    char *ip_address;
    int port;
};

void *scan_port(void *ptr) {
    struct thread_args *args = (struct thread_args *) ptr;
    char *ip_address = args->ip_address;
    int port = args->port;

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &(server_addr.sin_addr));
    server_addr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() error");
        pthread_exit(NULL);
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt() error");
        close(sockfd);
        pthread_exit(NULL);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
        printf("%-6d open\n", port);
    } else {
        printf("%-6d closed\n", port);
    }

    close(sockfd);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./portscanner <ip_address> <port_range>\n");
        exit(1);
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];
    int min_port, max_port;

    if (sscanf(port_range, "%d-%d", &min_port, &max_port) != 2) {
        printf("Invalid port range\n");
        exit(1);
    }

    if ((min_port < 0 || min_port > 65535) || (max_port < 0 || max_port > 65535) || (max_port < min_port)) {
        printf("Invalid port range\n");
        exit(1);
    }

    pthread_t threads[max_port-min_port+1];
    int thread_index = 0;

    for (int i = min_port; i <= max_port; i++) {
        struct thread_args *args = (struct thread_args *) malloc(sizeof(struct thread_args));
        args->ip_address = ip_address;
        args->port = i;

        if (pthread_create(&threads[thread_index], NULL, scan_port, (void *)args)) {
            perror("pthread_create() error");
            exit(1);
        }

        thread_index++;

        usleep(5000);
    }

    for (int i = 0; i < thread_index; i++) {
        if (pthread_join(threads[i], NULL)) {
            perror("pthread_join() error");
            exit(1);
        }
    }

    return 0;
}