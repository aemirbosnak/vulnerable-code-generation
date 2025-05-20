//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0

struct sockaddr_in target;
char *ip;
int port;
int num_threads;
pthread_t threads[MAX_THREADS];

void *scan_port(void *arg) {
    int sock = *(int *) arg;
    char buf[BUF_SIZE];
    int ret;

    ret = connect(sock, (struct sockaddr *) &target, sizeof(target));
    if (ret == 0) {
        printf("Port %d is open\n", port);
        close(sock);
        return NULL;
    } else if (errno!= ECONNREFUSED) {
        perror("connect");
        close(sock);
        return NULL;
    }

    close(sock);
    return NULL;
}

int main(int argc, char **argv) {
    int sock, max_fd, ret;
    struct sockaddr_in server;
    pthread_attr_t attr;
    char *endptr;
    int opt;

    if (argc!= 4) {
        printf("Usage: %s <IP> <port> <num_threads>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    if (num_threads > MAX_THREADS) {
        printf("Number of threads cannot be greater than %d\n", MAX_THREADS);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    max_fd = sock;

    for (int i = 0; i < num_threads; i++) {
        ret = pthread_create(&threads[i], &attr, scan_port, (void *) &sock);
        if (ret!= 0) {
            printf("Error creating thread: %s\n", strerror(ret));
            return 1;
        }
    }

    pthread_attr_destroy(&attr);

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    close(sock);
    return 0;
}