//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int check_uptime(struct hostent *host) {
    if (host == NULL) {
        printf("Error: Host not found\n");
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    address.sin_addr.s_addr = *((long *)host->h_addr_list[0]);

    struct sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr("www.example.com");
    sin.sin_port = htons(80);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket");
        return 1;
    }

    int ret = connect(sockfd, (struct sockaddr *)&sin, sizeof(sin));
    if (ret < 0) {
        perror("Error: Could not connect to host");
        close(sockfd);
        return 1;
    }

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    char buffer[1024];
    int n = recv(sockfd, buffer, 1024, 0);
    if (n < 0) {
        perror("Error: Could not receive data");
        close(sockfd);
        return 1;
    }

    gettimeofday(&end_time, NULL);
    long duration = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

    if (duration > 5000) {
        printf("Website is down\n");
        return 1;
    } else {
        printf("Website is up\n");
        return 0;
    }
}

int main() {
    struct hostent *host;
    host = gethostbyname("www.example.com");
    if (host == NULL) {
        printf("Error: Host not found\n");
        return 1;
    }

    int result = check_uptime(host);
    if (result == 1) {
        printf("Website is down\n");
    } else {
        printf("Website is up\n");
    }

    return 0;
}