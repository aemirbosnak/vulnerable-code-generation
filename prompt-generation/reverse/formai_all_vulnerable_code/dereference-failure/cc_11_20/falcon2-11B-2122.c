//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[1024];
    char *cmd;

    if ( (server = gethostbyname("smtp.gmail.com")) == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    portno = htons(25);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(0);
    }
    cmd = "HELO localhost\r\n";
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(0);
    }
    cmd = "MAIL FROM:<your_email_address>@gmail.com\r\n";
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(0);
    }
    cmd = "RCPT TO:<recipient_email_address>@gmail.com\r\n";
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(0);
    }
    cmd = "DATA\r\n";
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(0);
    }
    cmd = "Subject: test mail\r\n";
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(0);
    }
    cmd = "This is a test mail.\r\n.\r\n";
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(0);
    }
    cmd = "QUIT\r\n";
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(0);
    }
    close(sockfd);
    return 0;
}