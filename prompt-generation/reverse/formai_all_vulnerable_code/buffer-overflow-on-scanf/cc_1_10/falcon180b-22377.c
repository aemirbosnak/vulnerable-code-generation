//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define SERVER_PORT 21
#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 80

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char send_buf[MAX_LINE_LENGTH];
    char recv_buf[MAX_LINE_LENGTH];
    char username[MAX_COMMAND_LENGTH];
    char password[MAX_COMMAND_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    int n;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    portno = SERVER_PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(send_buf, "USER %s\r\n", username);
    send(sockfd, send_buf, strlen(send_buf), 0);

    sprintf(send_buf, "PASS %s\r\n", password);
    send(sockfd, send_buf, strlen(send_buf), 0);

    while (1) {
        memset(recv_buf, 0, MAX_LINE_LENGTH);
        n = recv(sockfd, recv_buf, MAX_LINE_LENGTH, 0);
        if (n <= 0) {
            printf("Disconnected from server\n");
            break;
        }
        printf("%s", recv_buf);
    }

    close(sockfd);
    return 0;
}