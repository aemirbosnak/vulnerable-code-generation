//FormAI DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_LINE 4096
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define MAX_SUBJECT 100
#define MAX_RECIPIENTS 100
#define MAX_CONTENT 2000

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_LINE];

    // prompt user for email client information
    char username[MAX_USERNAME], password[MAX_PASSWORD], subject[MAX_SUBJECT], recipients[MAX_RECIPIENTS], content[MAX_CONTENT];
    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Enter the subject of your email: ");
    scanf("%s", subject);
    printf("Enter the recipients of your email (separate multiple emails with a comma): ");
    scanf("%s", recipients);
    printf("Enter the content of your email: ");
    scanf("%s", content);

    // initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // get server information
    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // set server address information
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 587;
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // read initial server response
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // send initial HELO command
    sprintf(buffer, "HELO %s\r\n", server->h_name);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // read response to HELO command
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // send login command
    sprintf(buffer, "AUTH LOGIN\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // read response to login command
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // send username
    sprintf(buffer, "%s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // read response to username
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // send password
    sprintf(buffer, "%s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // read response to password
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // send mail from command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // read response to mail from command
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // send rcpt to command for each recipient
    char *token = strtok(recipients, ",");
    while (token != NULL) {
        sprintf(buffer, "RCPT TO: <%s>\r\n", token);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) 
            error("ERROR writing to socket");

        // read response to rcpt to command
        bzero(buffer,MAX_LINE);
        n = read(sockfd,buffer,MAX_LINE-1);
        if (n < 0) 
            error("ERROR reading from socket");
        printf("%s",buffer);

        token = strtok(NULL, ",");
    }

    // send data command
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // read response to data command
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // send subject line
    sprintf(buffer, "Subject: %s\r\n", subject);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // send content
    sprintf(buffer, "\r\n%s\r\n.\r\n", content);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // read response to content
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // send quit command
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    // read response to quit command
    bzero(buffer,MAX_LINE);
    n = read(sockfd,buffer,MAX_LINE-1);
    if (n < 0) 
        error("ERROR reading from socket");
    printf("%s",buffer);

    // close socket
    close(sockfd);

    return 0;
}