//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 64
#define BUFFER_SIZE 1024

int port_scan(int port);
void *thread_func(void *arg);

int main(int argc, char **argv) {
    int num_threads = 1, start_port = 1, end_port = 1025;
    char ip_address[16] = "127.0.0.1";

    if (argc >= 4) {
        num_threads = atoi(argv[1]);
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
        strcpy(ip_address, argv[4]);
    }

    if (start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    if (num_threads > MAX_THREADS) {
        printf("Maximum number of threads exceeded\n");
        exit(1);
    }

    pthread_t threads[num_threads];
    int thread_ids[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i * (end_port - start_port) / num_threads + start_port;
        pthread_create(&threads[i], NULL, thread_func, (void *)&thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread_func(void *arg) {
    int port = *((int *) arg);

    if (port_scan(port)) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }

    return NULL;
}

int port_scan(int port) {
    int sockfd, ret;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(port);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        if (errno == ECONNREFUSED) {
            close(sockfd);
            return 1;
        } else {
            printf("Connect failed: %s\n", strerror(errno));
            close(sockfd);
            return -1;
        }
    } else {
        close(sockfd);
        return 0;
    }
}