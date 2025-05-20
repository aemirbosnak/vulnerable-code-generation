//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

int main() {
    char buffer[1024];
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char* host_name = "www.google.com";
    int port = 80;

    struct timeval start, end;
    struct timezone tz;
    gettimeofday(&start, &tz);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(host_name);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    gettimeofday(&end, &tz);

    printf("Time taken: %ld.%06ld seconds\n", (long) (end.tv_sec - start.tv_sec), (long) (end.tv_usec - start.tv_usec));

    close(sockfd);

    return 0;
}