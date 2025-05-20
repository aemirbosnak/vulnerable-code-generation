//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 25
#define MAXLINE 1024
#define MAXEMAIL 128
#define MAXNAME 128

int main() {
    struct sockaddr_in serverAddr;
    struct hostent *server;
    int sockfd, n;
    char buf[MAXLINE], msg[MAXLINE], line[MAXLINE], name[MAXNAME], email[MAXEMAIL];

    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    memcpy((char *)&serverAddr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serverAddr.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    printf("Enter your email address: ");
    scanf("%s", email);
    strncpy(name, email, MAXNAME);
    name[MAXNAME-1] = '\0';

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your message: ");
    scanf("%s", msg);

    strcat(buf, "From: ");
    strcat(buf, name);
    strcat(buf, "\r\n");
    strcat(buf, "To: ");
    strcat(buf, email);
    strcat(buf, "\r\n");
    strcat(buf, "Subject: ");
    strcat(buf, msg);
    strcat(buf, "\r\n\r\n");
    strcat(buf, msg);

    n = strlen(buf);
    send(sockfd, buf, n, 0);

    if (n <= 0) {
        perror("Error sending message");
        exit(1);
    }

    printf("Message sent!\n");
    return 0;
}