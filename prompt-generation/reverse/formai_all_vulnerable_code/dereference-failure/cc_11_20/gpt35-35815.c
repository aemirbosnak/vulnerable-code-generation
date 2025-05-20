//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 0;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    
    printf("Connecting to %s:%d\n", hostname, port);

    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((rv = getaddrinfo(hostname, argv[2], &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        return 2;
    }

    printf("Connected to %s:%d\n", hostname, port);

    int counter = 0;
    int total_bytes_written = 0;
    int total_bytes_read = 0;
    long total_ms_elapsed = 0;

    while (TRUE) {
        char *message = "Hello, world!\n";
        int len = strlen(message);
        struct timeval start, end;
        gettimeofday(&start, NULL);
        int bytes_written = send(sockfd, message, len, 0);
        if (bytes_written == -1) {
            perror("send");
            break;
        }
        total_bytes_written += bytes_written;

        char buffer[256];
        int bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_read == -1) {
            perror("recv");
            break;
        }
        total_bytes_read += bytes_read;

        gettimeofday(&end, NULL);
        long ms_elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
        total_ms_elapsed += ms_elapsed;

        counter += 1;
        if (counter == 10) {
            printf("10 requests sent/received:\n");
            printf("Average transmission time: %.3f ms\n", (float) total_ms_elapsed / counter);
            printf("Bytes sent: %d\n", total_bytes_written);
            printf("Bytes received: %d\n", total_bytes_read);
            counter = 0;
            total_bytes_written = 0;
            total_bytes_read = 0;
            total_ms_elapsed = 0;
        }

        sleep(1);
    }

    close(sockfd);

    return 0;
}