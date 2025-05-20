//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_MAX 65535
#define THREAD_MAX 100

int scanned_ports[PORT_MAX];

void *thread_scan(void *arg) {
    int port = *(int *) arg;
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Thread %d: Error creating socket\n", port);
        return NULL;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0) {
        close(sockfd);
        scanned_ports[port] = 1;
        printf("Thread %d: Port %d is open\n", port, port);
    } else {
        close(sockfd);
        scanned_ports[port] = 0;
        printf("Thread %d: Port %d is closed\n", port, port);
    }
    return NULL;
}

void scan_ports(int start_port, int end_port) {
    int i;
    pthread_t threads[THREAD_MAX];

    for (i = start_port; i <= end_port; i++) {
        scanned_ports[i] = -1;
    }

    for (i = 0; i < THREAD_MAX; i++) {
        pthread_create(&threads[i], NULL, thread_scan, (void *) &i);
    }

    for (i = 0; i < THREAD_MAX; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    int start_port, end_port;

    if (argc!= 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);

    if (start_port > end_port || start_port < 1 || end_port > PORT_MAX) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(start_port, end_port);

    return 0;
}