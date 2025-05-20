//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 1024

int main(void)
{
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int sockfd;
    struct hostent *server;
    char buffer[BUFFSIZE];
    char message[BUFFSIZE];
    char recipient_address[] = "recipient@example.com";
    char sender_address[] = "sender@example.com";
    char subject[] = "Test Email";
    char body[] = "This is a test email.";

    // Initialize the addrinfo structure
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve the server name to an address
    if ((rv = getaddrinfo(NULL, "25", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // Loop through all the results and connect to the first we can
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("client: connect");
            continue;
        }

        break;
    }

    // If we failed to connect, clean up and exit
    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        freeaddrinfo(servinfo);
        return 1;
    }

    // Send HELO command to the server
    memset(buffer, 0, BUFFSIZE);
    strcpy(buffer, "HELO example.com\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("client: send");
        freeaddrinfo(servinfo);
        return 1;
    }

    // Send MAIL FROM command to the server
    memset(buffer, 0, BUFFSIZE);
    strcpy(buffer, "MAIL FROM: <");
    strcat(buffer, sender_address);
    strcat(buffer, ">\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("client: send");
        freeaddrinfo(servinfo);
        return 1;
    }

    // Send RCPT TO command to the server
    memset(buffer, 0, BUFFSIZE);
    strcpy(buffer, "RCPT TO: <");
    strcat(buffer, recipient_address);
    strcat(buffer, ">\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("client: send");
        freeaddrinfo(servinfo);
        return 1;
    }

    // Send DATA command to the server
    memset(buffer, 0, BUFFSIZE);
    strcpy(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("client: send");
        freeaddrinfo(servinfo);
        return 1;
    }

    // Send the message body
    strcpy(buffer, "From: ");
    strcat(buffer, sender_address);
    strcat(buffer, "\r\n");
    strcat(buffer, "To: ");
    strcat(buffer, recipient_address);
    strcat(buffer, "\r\n");
    strcat(buffer, "Subject: ");
    strcat(buffer, subject);
    strcat(buffer, "\r\n");
    strcat(buffer, "\r\n");
    strcat(buffer, body);
    strcat(buffer, "\r\n.\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("client: send");
        freeaddrinfo(servinfo);
        return 1;
    }

    // Send QUIT command to the server
    memset(buffer, 0, BUFFSIZE);
    strcpy(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("client: send");
        freeaddrinfo(servinfo);
        return 1;
    }

    // Receive server response and close the socket
    memset(buffer, 0, BUFFSIZE);
    if (recv(sockfd, buffer, BUFFSIZE, 0) < 0) {
        perror("client: receive");
        freeaddrinfo(servinfo);
        return 1;
    }
    printf("Server response: %s\n", buffer);
    close(sockfd);

    // Clean up
    freeaddrinfo(servinfo);
    return 0;
}