//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    printf("Enter the IP address of the SMTP server: ");
    scanf("%s", buffer);
    server = gethostbyname(buffer);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    portno = 25;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR connecting\n");
        exit(0);
    }

    printf("Enter the email address of the recipient: ");
    scanf("%s", buffer);

    n = write(sockfd,"HELO localhost\r\n",strlen("HELO localhost\r\n"));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(0);
    }

    n = write(sockfd,"MAIL FROM: <sender@example.com>\r\n",strlen("MAIL FROM: <sender@example.com>\r\n"));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(0);
    }

    n = write(sockfd,"RCPT TO: <recipient@example.com>\r\n",strlen("RCPT TO: <recipient@example.com>\r\n"));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(0);
    }

    n = write(sockfd,"DATA\r\n",strlen("DATA\r\n"));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(0);
    }

    printf("Enter the body of the email: ");
    scanf("%s", buffer);

    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(0);
    }

    n = write(sockfd,"\r\n.\r\n",strlen("\r\n.\r\n"));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(0);
    }

    n = write(sockfd,"QUIT\r\n",strlen("QUIT\r\n"));
    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(0);
    }

    close(sockfd);
    return 0;
}