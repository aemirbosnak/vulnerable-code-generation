//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080
#define SERVER "192.168.1.1"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *date = "Fri, 20 Apr 2018 00:00:00 GMT";
    char *content_type = "text/html";
    char *response = "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/html\r\n"
                      "Content-Length: 0\r\n"
                      "Connection: close\r\n"
                      "Date: ";
    int n;
    FILE *fp;
    char ch;
    int count = 0;
    int total = 0;
    double speed = 0.0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);
    serv_addr.sin_port = htons(PORT);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret == 0) {
            printf("Server disconnected\n");
            break;
        }
        total += ret;
        count++;
        if (count == 10) {
            speed = (double)total / 10.0;
            printf("Speed: %.2f kbps\n", speed);
            count = 0;
            total = 0;
        }
    }

    close(sockfd);
    return 0;
}