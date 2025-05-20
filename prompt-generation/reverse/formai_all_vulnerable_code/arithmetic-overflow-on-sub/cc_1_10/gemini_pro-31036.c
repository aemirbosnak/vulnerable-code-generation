//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

#define DEFAULT_PORT 5001
#define DEFAULT_INTERVAL 1
#define DEFAULT_COUNT 10

static volatile int running = 1;

void handle_signal(int sig) {
    running = 0;
}

int main(int argc, char **argv) {
    int sockfd, rc;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    int port;
    int interval;
    int count;
    int i;
    struct timeval start, end;
    double elapsed;
    double avg_elapsed = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname [port] [interval] [count]\n", argv[0]);
        return EXIT_FAILURE;
    }

    hostname = argv[1];
    port = DEFAULT_PORT;
    if (argc >= 3) {
        port = atoi(argv[2]);
    }
    interval = DEFAULT_INTERVAL;
    if (argc >= 4) {
        interval = atoi(argv[3]);
    }
    count = DEFAULT_COUNT;
    if (argc >= 5) {
        count = atoi(argv[4]);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "gethostbyname(%s) failed\n", hostname);
        return EXIT_FAILURE;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    memcpy(&serveraddr.sin_addr.s_addr, server->h_addr, server->h_length);
    serveraddr.sin_port = htons(port);

    rc = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (rc < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    signal(SIGINT, handle_signal);

    for (i = 0; i < count && running; i++) {
        char buf[1] = {0};

        gettimeofday(&start, NULL);
        rc = send(sockfd, buf, 1, 0);
        if (rc < 0) {
            perror("send");
            return EXIT_FAILURE;
        }
        rc = recv(sockfd, buf, 1, 0);
        if (rc < 0) {
            perror("recv");
            return EXIT_FAILURE;
        }
        gettimeofday(&end, NULL);

        elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        avg_elapsed += elapsed / count;

        printf("%d: %f ms\n", i + 1, elapsed);

        sleep(interval);
    }

    close(sockfd);

    printf("Average elapsed time: %f ms\n", avg_elapsed);

    return EXIT_SUCCESS;
}