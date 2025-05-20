//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int scan_port(int sock, struct sockaddr_in *addr, int port) {
    char buffer[BUFFER_SIZE];
    int result;

    if (connect(sock, (struct sockaddr *) addr, sizeof(struct sockaddr_in)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
        return 1;
    } else {
        printf("Port %d is closed\n", port);
        close(sock);
        return 0;
    }
}

void *thread_scan(void *param) {
    int *port = param;
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(*port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    scan_port(sock, &addr, *port);

    close(sock);
}

int main(int argc, char *argv[]) {
    int i, num_threads;
    pthread_t threads[MAX_THREADS];

    if (argc < 3) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    num_threads = atoi(argv[2]) - atoi(argv[1]) + 1;

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_scan, &argv[1]);
        argv[1] += 2;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}