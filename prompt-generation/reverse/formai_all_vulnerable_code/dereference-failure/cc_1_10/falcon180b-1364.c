//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int port;
char *ip;
int num_threads;
int threads_finished;

void *scan_port(void *arg) {
    int sock = *(int *) arg;
    close(sock);
    return NULL;
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    int sock, port_num;
    struct sockaddr_in server;
    int opt = 1;

    for (port_num = start_port; port_num <= end_port; port_num++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        server.sin_family = AF_INET;
        server.sin_port = htons(port_num);
        inet_pton(AF_INET, ip_address, &server.sin_addr);

        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port_num);
            close(sock);
        } else {
            printf("Port %d is closed\n", port_num);
        }
    }
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <ip_address> <start_port> <end_port>\n");
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (port <= 0 || end_port <= 0 || port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    num_threads = 0;
    pthread_t threads[MAX_THREADS];

    for (int i = port; i <= end_port; i++) {
        pthread_create(&threads[num_threads], NULL, scan_port, (void *) i);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}