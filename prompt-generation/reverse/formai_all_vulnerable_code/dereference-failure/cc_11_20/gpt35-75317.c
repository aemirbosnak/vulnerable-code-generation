//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if(argc != 4) {
        printf("Usage: ./smtp_client [IP Address] [Port] [Recipient Email Address]\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1) {
        printf("Error: Unable to create socket!\n");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        printf("Error: Unable to connect to remote host!\n");
        exit(1);
    }

    char buf[1024];
    int numbytes;

    if((numbytes = recv(sockfd, buf, 1023, 0)) == -1) {
        printf("Error: Unable to receive data from remote host!\n");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("%s", buf);

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "EHLO localhost\r\n");

    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        printf("Error: Unable to send data to remote host!\n");
        exit(1);
    }

    memset(buf, 0, sizeof(buf));

    if((numbytes = recv(sockfd, buf, 1023, 0)) == -1) {
        printf("Error: Unable to receive data from remote host!\n");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("%s", buf);

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "MAIL FROM:<%s>\r\n", "johndoe@gmail.com");

    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        printf("Error: Unable to send data to remote host!\n");
        exit(1);
    }

    memset(buf, 0, sizeof(buf));

    if((numbytes = recv(sockfd, buf, 1023, 0)) == -1) {
        printf("Error: Unable to receive data from remote host!\n");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("%s", buf);

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "RCPT TO:<%s>\r\n", argv[3]);

    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        printf("Error: Unable to send data to remote host!\n");
        exit(1);
    }

    memset(buf, 0, sizeof(buf));

    if((numbytes = recv(sockfd, buf, 1023, 0)) == -1) {
        printf("Error: Unable to receive data from remote host!\n");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("%s", buf);

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "DATA\r\n");

    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        printf("Error: Unable to send data to remote host!\n");
        exit(1);
    }

    memset(buf, 0, sizeof(buf));

    if((numbytes = recv(sockfd, buf, 1023, 0)) == -1) {
        printf("Error: Unable to receive data from remote host!\n");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("%s", buf);

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "Subject: Test Email\r\n\r\nHello World!\r\n.\r\n");

    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        printf("Error: Unable to send data to remote host!\n");
        exit(1);
    }

    memset(buf, 0, sizeof(buf));

    if((numbytes = recv(sockfd, buf, 1023, 0)) == -1) {
        printf("Error: Unable to receive data from remote host!\n");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("%s", buf);

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "QUIT\r\n");

    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        printf("Error: Unable to send data to remote host!\n");
        exit(1);
    }

    memset(buf, 0, sizeof(buf));

    if((numbytes = recv(sockfd, buf, 1023, 0)) == -1) {
        printf("Error: Unable to receive data from remote host!\n");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("%s", buf);

    close(sockfd);

    return 0;
}