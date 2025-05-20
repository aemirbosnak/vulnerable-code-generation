//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main() {

    int sockfd, port, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];
    char domain[MAXLINE], sender[MAXLINE], recipient[MAXLINE], header[MAXLINE];

    printf("Enter the server IP: ");
    fgets(domain, MAXLINE, stdin);
    printf("Enter the server port: ");
    scanf("%d", &port);
    getchar();

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Assigning IP and Port
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if(inet_pton(AF_INET, domain, &servaddr.sin_addr) <= 0) {
        perror("inet_pton error!");
        exit(EXIT_FAILURE);
    }

    // Connecting to the server
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Connection Failed!");
        exit(EXIT_FAILURE);
    }

    // Getting the sender and recipient email addresses
    printf("Enter the sender email address: ");
    fgets(sender, MAXLINE, stdin);
    printf("Enter the recipient email address: ");
    fgets(recipient, MAXLINE, stdin);

    // Building the email header
    sprintf(header, "From: %sTo: %sSubject: SMTP Client Example\n", sender, recipient);

    // Getting the message
    printf("Enter the message:\n");
    fgets(sendline, MAXLINE, stdin);

    // Sending the header
    n = write(sockfd, header, strlen(header));
    if(n < 0) {
        perror("Write Failed!");
        exit(EXIT_FAILURE);
    }

    // Sending the message
    n = write(sockfd, sendline, strlen(sendline));
    if(n < 0) {
        perror("Write Failed!");
        exit(EXIT_FAILURE);
    }

    // Receiving the response
    n = read(sockfd, recvline, MAXLINE);
    if(n < 0) {
        perror("Read Failed!");
        exit(EXIT_FAILURE);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    close(sockfd);
    return 0;
}