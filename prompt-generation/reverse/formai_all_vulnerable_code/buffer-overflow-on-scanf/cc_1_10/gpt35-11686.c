//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define SERVER_PORT 25

int main(int argc, char *argv[]){
    struct sockaddr_in serverAddr;
    struct hostent *server;
    char buffer[1024];
    int sockfd, n;
    char username[30], password[30], to[30], cc[30], subject[30], body[500];

    printf("Enter your email address (username@domain.com): ");
    scanf("%s", username);
    printf("Enter your email password: ");
    scanf("%s", password);
    printf("To: ");
    scanf("%s", to);
    printf("Cc: ");
    scanf("%s", cc);
    printf("Subject: ");
    scanf("%s", subject);
    printf("Body: ");
    scanf("%s", body);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("smtp.gmail.com");

    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    bcopy((char *)server->h_addr, (char *)&serverAddr.sin_addr.s_addr, server->h_length);

    if(connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0){
        perror("ERROR connecting");
        exit(1);
    }

    bzero(buffer, 1024);

    // Login
    snprintf(buffer, sizeof(buffer), "EHLO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    // Authenticate
    snprintf(buffer, sizeof(buffer), "AUTH LOGIN\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "%s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "%s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    // Set mail from
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    // Set rcpt to
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    // Set data mode
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    // Send message data
    snprintf(buffer, sizeof(buffer), "From: %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    snprintf(buffer, sizeof(buffer), "To: %s\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    snprintf(buffer, sizeof(buffer), "Cc: %s\r\n", cc);
    send(sockfd, buffer, strlen(buffer), 0);
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n", subject);
    send(sockfd, buffer, strlen(buffer), 0);
    snprintf(buffer, sizeof(buffer), "%s\r\n.\r\n", body);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    // Close connection with server
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}