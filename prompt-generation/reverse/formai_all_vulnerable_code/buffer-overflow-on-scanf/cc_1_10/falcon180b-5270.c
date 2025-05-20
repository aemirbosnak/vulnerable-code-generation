//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 1000
#define BUFLEN 1024

int open_port(int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Failed to create socket.\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        close(sockfd);
        return 1;
    } else {
        close(sockfd);
        return 0;
    }
}

void *thread_func(void *param) {
    int *port_num = (int *)param;

    if (open_port(*port_num)) {
        printf("Port %d is open.\n", *port_num);
    } else {
        printf("Port %d is closed.\n", *port_num);
    }

    return NULL;
}

int main() {
    int num_threads, num_ports;
    pthread_t threads[MAX_THREADS];
    int port_list[MAX_PORTS];

    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    for (int i = 0; i < num_ports; i++) {
        printf("Enter port number %d: ", i + 1);
        scanf("%d", &port_list[i]);
    }

    printf("Enter the number of threads to use: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, &port_list[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}