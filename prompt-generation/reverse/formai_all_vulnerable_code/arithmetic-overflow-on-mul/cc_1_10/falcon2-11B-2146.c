//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <string.h>
#include <netdb.h>

int main() {
    struct sockaddr_in server;
    int sockfd, n, bytes_sent;
    int time_elapsed, i;
    struct timeval start_time, end_time;
    struct hostent *server_host;
    struct sockaddr_in remote_host;

    if (gethostname(server.sin_addr.s_addr, sizeof(server.sin_addr.s_addr)) < 0) {
        perror("gethostname()");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket()");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect()");
        exit(1);
    }

    gettimeofday(&start_time, NULL);

    for (i = 0; i < 100; i++) {
        memset(&remote_host, 0, sizeof(remote_host));
        remote_host.sin_family = AF_INET;
        remote_host.sin_port = htons(8080);
        remote_host.sin_addr.s_addr = htonl(INADDR_ANY);
        n = sizeof(remote_host);

        if ((n = sendto(sockfd, "Hello World!", sizeof("Hello World!"), 0, (struct sockaddr *)&remote_host, n)) < 0) {
            perror("sendto()");
            exit(1);
        }

        gettimeofday(&end_time, NULL);
        time_elapsed = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

        if (i % 10 == 0) {
            printf("%d: %ld bytes sent in %ld microseconds\n", i, n, time_elapsed);
        }
    }

    close(sockfd);

    return 0;
}