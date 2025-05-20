//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *message = "Welcome to the Internet Speed Test Application!";
    int len = strlen(message);
    time_t start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    portno = SERVER_PORT;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(portno);

    ret = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd == -1) {
            perror("accept failed");
            exit(1);
        }

        time(&start_time);
        send(newsockfd, message, len, 0);
        recv(newsockfd, buffer, BUFFER_SIZE, 0);
        time(&end_time);

        double elapsed_time = difftime(end_time, start_time);
        double speed = BUFFER_SIZE / elapsed_time;

        printf("Connection from %s\n", inet_ntoa(cli_addr.sin_addr));
        printf("Download speed: %.2f bytes/s\n", speed);

        close(newsockfd);
    }

    return 0;
}