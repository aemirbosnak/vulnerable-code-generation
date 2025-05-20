//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    struct addrinfo hints, *result, *rp;
    int sockfd, numbytes;
    char buf[BUF_SIZE];
    struct timeval start, end;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* TCP socket */

    int ret = getaddrinfo(argv[1], "http", &hints, &result);
    if (ret != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(ret));
        exit(EXIT_FAILURE);
    }

    /* Try to connect to any server IP in the result list */
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1)
            continue;

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break; /* Connected successfully */

        close(sockfd);
    }

    if (rp == NULL) { /* No address succeeded */
        fprintf(stderr, "Could not connect to %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result); /* Free hold addrinfo */

    gettimeofday(&start, NULL); /* Record start time*/
    /* Send HTTP GET request */
    if (send(sockfd, "GET / HTTP/1.0\r\n\r\n", 21, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    /* Receive server's response */
    numbytes = recv(sockfd, buf, BUF_SIZE-1, 0);
    gettimeofday(&end, NULL); /* Record end time*/

    if (numbytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    buf[numbytes] = '\0'; /* Null-terminate retrieved data */

    /* Calculate elapsed time and print out download speed */
    double elapsed_time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
    double download_speed = numbytes / elapsed_time / 1024.0 / 1024.0; /* in MB/s */

    printf("Download speed: %.2f MB/s\n", download_speed);

    close(sockfd);

    return 0;
}