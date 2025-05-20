//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

struct timestamp {
    time_t sec;
    long nsec;
};

void get_timestamp(struct timestamp *ts) {
    clock_gettime(CLOCK_MONOTONIC, ts);
}

double get_elapsed_time(struct timestamp *start, struct timestamp *end) {
    return (double)(end->sec - start->sec) + (double)(end->nsec - start->nsec) / 1000000000.0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server_ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    int optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buf[BUF_SIZE];
    struct timestamp start, end;

    while (1) {
        get_timestamp(&start);

        int nbytes = send(sock, buf, BUF_SIZE, 0);
        if (nbytes == -1) {
            perror("send");
            break;
        }

        nbytes = recv(sock, buf, BUF_SIZE, 0);
        if (nbytes == -1) {
            perror("recv");
            break;
        }

        get_timestamp(&end);

        double elapsed_time = get_elapsed_time(&start, &end);
        printf("RTT: %.6f ms\n", elapsed_time * 1000.0);
    }

    close(sock);

    return EXIT_SUCCESS;
}