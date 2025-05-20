//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: calm
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[1024];

    if (argc!= 2) {
        fprintf(stderr, "usage %s hostname\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (1) {
        time_t current_time;
        time(&current_time);

        if (send(sockfd, "GET / HTTP/1.1\r\nHost: ", 25, 0) < 0) {
            perror("ERROR sending data");
            exit(1);
        }

        if (send(sockfd, "\r\n", 2, 0) < 0) {
            perror("ERROR sending data");
            exit(1);
        }

        if (send(sockfd, "User-Agent: Uptime Monitor\r\nConnection: close\r\n\r\n", 49, 0) < 0) {
            perror("ERROR sending data");
            exit(1);
        }

        if (recv(sockfd, buf, 1024, 0) < 0) {
            perror("ERROR receiving data");
            exit(1);
        }

        if (strstr(buf, "200 OK") == NULL) {
            fprintf(stderr, "Uptime Monitor: Server is down!\n");
            exit(1);
        }

        printf("Uptime Monitor: Server is up!\n");
        sleep(10);
    }

    return 0;
}