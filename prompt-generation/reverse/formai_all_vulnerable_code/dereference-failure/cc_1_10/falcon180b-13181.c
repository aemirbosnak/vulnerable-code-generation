//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 100
#define BUF_SIZE 1024

struct host_info {
    char *ip;
    int port;
};

void *scan_port(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Failed to create socket - %s\n", strerror(errno));
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host->ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(host->port);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr))!= -1) {
        close(sock);
        printf("Port %d is open on %s\n", host->port, host->ip);
    } else {
        close(sock);
        printf("Port %d is closed on %s\n", host->port, host->ip);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port;

    if (argc > 3) {
        end_port = atoi(argv[3]);
    }

    if (start_port > end_port) {
        printf("Error: Start port cannot be greater than end port\n");
        return 1;
    }

    int num_threads = end_port - start_port + 1;
    pthread_t threads[MAX_THREADS];
    struct host_info hosts[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        hosts[i].ip = ip_addr;
        hosts[i].port = start_port + i;
    }

    int rc;
    for (int i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], NULL, scan_port, &hosts[i]);
        if (rc) {
            printf("Error: Unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}