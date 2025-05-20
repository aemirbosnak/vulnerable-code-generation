//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int scan_port(int sock, const char *ip, int port) {
    char buffer[BUFFER_SIZE];
    int ret = 0;
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == 0) {
        printf("Port %d is open on %s\n", port, ip);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed on %s\n", port, ip);
    } else {
        printf("Error connecting to %s:%d - %s\n", ip, port, strerror(errno));
    }

    return ret;
}

void *scan_thread(void *args) {
    char *ip = (char *)args;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket - %s\n", strerror(errno));
        return NULL;
    }

    for (int i = 1; i <= 65535; i++) {
        scan_port(sock, ip, i);
    }

    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <number of threads>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int num_threads = atoi(argv[2]);

    if (num_threads > MAX_THREADS) {
        printf("Error: Maximum number of threads is %d\n", MAX_THREADS);
        return 1;
    }

    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_thread, (void *)ip);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}