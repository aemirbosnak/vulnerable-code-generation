//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define MAX_PORTS 1024
#define MAX_THREADS 100

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int port;
} thread_args;

void *scan_port(void *arg) {
    thread_args *args = (thread_args *)arg;
    int err = connect(args->sockfd, (struct sockaddr *)&args->addr, sizeof(args->addr));
    if (err == 0) {
        printf("Port %d open on %s\n", args->port, inet_ntoa(args->addr.sin_addr));
    }
    close(args->sockfd);
    free(args);
    return NULL;
}

int main(int argc, char **argv) {
    int num_threads = 0;
    if (argc < 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        return 1;
    }
    char *ip_addr = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        printf("Invalid port range: %s\n", port_range);
        return 1;
    }
    int num_ports = end_port - start_port + 1;
    if (num_ports > MAX_PORTS) {
        printf("Too many ports to scan: %d\n", num_ports);
        return 1;
    }
    pthread_t threads[MAX_THREADS];
    for (int i = start_port; i <= end_port; i++) {
        if (num_threads >= MAX_THREADS) {
            for (int j = 0; j < num_threads; j++) {
                pthread_join(threads[j], NULL);
            }
            num_threads = 0;
        }
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        addr.sin_addr.s_addr = inet_addr(ip_addr);
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            exit(1);
        }
        thread_args *args = malloc(sizeof(thread_args));
        args->sockfd = sockfd;
        args->addr = addr;
        args->port = i;
        pthread_create(&threads[num_threads++], NULL, scan_port, args);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}