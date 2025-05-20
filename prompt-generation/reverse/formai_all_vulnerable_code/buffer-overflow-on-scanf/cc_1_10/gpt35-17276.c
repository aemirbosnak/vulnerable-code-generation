//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

#define MAX 1024

void sendMail(int sockfd)
{
    char buffer[MAX];
 
    // Request for User Input
    printf("Enter your email address (From): ");
    scanf("%s", buffer);
    sprintf(buffer, "MAIL FROM: <%s>\r\n", buffer);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAX);
 
    // Request for User Input
    printf("Enter Recipient email address (To): ");
    scanf("%s", buffer);
    sprintf(buffer, "RCPT TO: <%s>\r\n", buffer);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAX);
 
    // Request for User Input
    printf("Enter Subject: ");
    scanf("%s", buffer);
    sprintf(buffer, "Subject: %s\r\n", buffer);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAX);
 
    // Request for User Input
    printf("Enter Message Body: ");
    scanf("%s", buffer);
    sprintf(buffer, "%s\r\n.\r\n", buffer);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, MAX);

    printf("\nEmail Sent Successfully!\n");
}
 
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX];
    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("SMTP Client Program\n\n");

    while(1)
    {
        printf("1. Send Email\n2. Exit\n");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
                sendMail(sockfd);
                break;
            case 2:
                printf("Exiting...");
                close(sockfd);
                exit(0);
            default:
                printf("Invalid Choice. Try Again\n");
                break;
        }
    }

    return 0;
}