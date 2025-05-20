//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 80
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE] = {0};
    double total_time;
    time_t start, end;

    if (argc != 2) {
        printf("Usage: %s <host name>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    //send http request to the server
    char http_request[BUFSIZE];
    sprintf(http_request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send(sockfd, http_request, strlen(http_request), 0);

    //start timer
    start = time(NULL);

    //receive response from server
    int n;
    while((n = recv(sockfd, buffer, BUFSIZE-1, 0)) > 0) {
        bzero(buffer, BUFSIZE);
    }

    //end timer
    end = time(NULL);
    total_time = difftime(end, start);

    //calculate internet speed
    double speed = BUFSIZE / total_time;

    printf("Download Speed: %.2f B/sec\n", speed);
 
    return 0;
}