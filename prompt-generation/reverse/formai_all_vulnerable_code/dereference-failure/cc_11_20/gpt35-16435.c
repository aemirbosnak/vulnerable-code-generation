//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 1024

int main(int argc, char **argv)
{
    int sockfd, n, port;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *hp;

    // check for required command line arguments
    if (argc != 4) {
        printf("Usage: %s <domain name> <port number> <sender email address>. \n", argv[0]);
        exit(1);
    }

    // get port number
    port = atoi(argv[2]);

    // create socket and initialize server address
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    // get IP address from domain name
    hp = gethostbyname(argv[1]);
    if (hp == NULL) {
        printf("Unknown host: %s\n", argv[1]);
        exit(1);
    }

    // copy IP address to server address structure
    bcopy((char *) hp->h_addr, (char *) &servaddr.sin_addr.s_addr, hp->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // read server greeting
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) <= 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // send HELLO command
    char cmd[MAXLINE];
    bzero(cmd, MAXLINE);
    sprintf(cmd, "HELO %s\r\n", argv[3]);
    write(sockfd, cmd, strlen(cmd));

    // read server response
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) <= 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // send MAIL FROM command
    bzero(cmd, MAXLINE);
    sprintf(cmd, "MAIL FROM:<%s>\r\n", argv[3]);
    write(sockfd, cmd, strlen(cmd));

    // read server response
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) <= 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // send RCPT TO command
    bzero(cmd, MAXLINE);
    printf("Enter the recipient's email address: ");
    char recipient[MAXLINE];
    fgets(recipient, MAXLINE, stdin);
    recipient[strlen(recipient) - 1] = '\0';
    sprintf(cmd, "RCPT TO:<%s>\r\n", recipient);
    write(sockfd, cmd, strlen(cmd));

    // read server response
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) <= 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // send DATA command
    bzero(cmd, MAXLINE);
    sprintf(cmd, "DATA\r\n");
    write(sockfd, cmd, strlen(cmd));

    // read server response
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) <= 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // send email message
    char message[MAXLINE];
    bzero(message, MAXLINE);
    printf("Enter your message, followed by a period on a new line to end the message:\n");
    while (fgets(message, MAXLINE, stdin)) {
        if (strcmp(message, ".\n") == 0)
            break;
        write(sockfd, message, strlen(message));
        bzero(message, MAXLINE);
    }

    // send QUIT command
    bzero(cmd, MAXLINE);
    sprintf(cmd, "QUIT\r\n");
    write(sockfd, cmd, strlen(cmd));

    // read server response
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) <= 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // close socket
    close(sockfd);

    return 0;
}