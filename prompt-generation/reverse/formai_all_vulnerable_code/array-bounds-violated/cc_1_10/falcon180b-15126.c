//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    time_t seconds;
    struct tm *tm;
    char timestr[80];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = SERVER_PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret == 0) {
            printf("Connection closed by server\n");
            break;
        }
        buffer[ret] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}