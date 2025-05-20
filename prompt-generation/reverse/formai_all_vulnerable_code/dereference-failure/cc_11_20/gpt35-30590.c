//FormAI DATASET v1.0 Category: Email Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define CRLF "\r\n"
#define MAXLEN 2048

/* function to print error messages */
void err_exit(char *errmsg)
{
    fprintf(stderr, "Error: %s (%s)\n", errmsg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    char sendbuf[MAXLEN], recvbuf[MAXLEN];
    char mailserver[] = "mail.example.com";
    char username[] = "user@example.com";
    char password[] = "1234abcd";
    char hostname[MAXLEN];
    struct hostent *he;
    struct sockaddr_in servaddr;
    
    /* get hostname */
    if(gethostname(hostname, MAXLEN) < 0)
        err_exit("gethostname error");
    
    /* get host address */
    if((he = gethostbyname(hostname)) == NULL)
        err_exit("gethostbyname error");
    
    /* create socket */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_exit("socket error");
    
    /* set server address */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    if((he = gethostbyname(mailserver)) == NULL)
        err_exit("gethostbyname error");
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);
    
    /* connect to server */
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        err_exit("connect error");
    
    /* receive greeting */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send HELO */
    sprintf(sendbuf, "HELO %s" CRLF, hostname);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive welcome */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send AUTH LOGIN */
    sprintf(sendbuf, "AUTH LOGIN" CRLF);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive response */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send username */
    bzero(sendbuf, MAXLEN);
    sprintf(sendbuf, "%s" CRLF, username);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive response */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send password */
    bzero(sendbuf, MAXLEN);
    sprintf(sendbuf, "%s" CRLF, password);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive response */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send MAIL FROM */
    sprintf(sendbuf, "MAIL FROM:<%s>" CRLF, username);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive response */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send RCPT TO */
    sprintf(sendbuf, "RCPT TO:<%s>" CRLF, argv[1]);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive response */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send DATA */
    sprintf(sendbuf, "DATA" CRLF);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive response */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send email content */
    bzero(sendbuf, MAXLEN);
    strcat(sendbuf, "From: ");
    strcat(sendbuf, username);
    strcat(sendbuf, CRLF "To: ");
    strcat(sendbuf, argv[1]);
    strcat(sendbuf, CRLF "Subject: ");
    strcat(sendbuf, argv[2]);
    strcat(sendbuf, CRLF CRLF);
    write(STDOUT_FILENO, sendbuf, strlen(sendbuf));
    write(sockfd, sendbuf, strlen(sendbuf));
    
    /* send PERIOD */
    sprintf(sendbuf, "." CRLF);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive response */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* send QUIT */
    sprintf(sendbuf, "QUIT" CRLF);
    if(write(sockfd, sendbuf, strlen(sendbuf)) < 0)
        err_exit("write error");
    
    /* receive farewell */
    if((n = read(sockfd, recvbuf, MAXLEN - 1)) < 0)
        err_exit("read error");
    recvbuf[n] = '\0';
    printf("%s\n", recvbuf);
    
    /* close socket */
    close(sockfd);
    exit(0);
}