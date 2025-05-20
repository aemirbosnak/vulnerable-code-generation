//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char ip[INET_ADDRSTRLEN];
    struct hostent *he;

    he = gethostbyname(argv[1]);
    if (he == NULL) {
        printf("Error: Invalid IP address\n");
        return 1;
    }

    struct sockaddr_in dest_addr;
    bzero((char *)&dest_addr, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    bcopy((char *)he->h_addr, (char *)&dest_addr.sin_addr.s_addr, he->h_length);
    dest_addr.sin_port = htons(80);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    int result = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (result < 0) {
        printf("Error: Failed to connect to server\n");
        return 1;
    }

    struct timeval start_time, end_time;
    double response_time;

    gettimeofday(&start_time, NULL);
    send(sockfd, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1], BUFFER_SIZE);
    recv(sockfd, BUFFER_SIZE, 0, 0);

    gettimeofday(&end_time, NULL);
    response_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

    printf("Ping to %s: %f ms\n", argv[1], response_time);

    close(sockfd);
    return 0;
}