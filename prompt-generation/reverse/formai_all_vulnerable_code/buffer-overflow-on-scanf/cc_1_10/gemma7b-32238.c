//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <netdb.h>

#define POP3_HOST "pop.mailserver.com"
#define POP3_PORT 110

int main() {
    int sockfd, n, i, blen;
    char buf[1024], mail[1024], username[256], password[256];
    struct sockaddr_in sock_addr;

    printf("Enter username:");
    scanf("%s", username);

    printf("Enter password:");
    scanf("%s", password);

    // Connect to POP3 server
    sockfd = socket(AF_INET, SOCK_STREAM, htons(POP3_PORT));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(POP3_PORT);
    sock_addr.sin_addr.s_addr = inet_addr(POP3_HOST);
    connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

    // Login to POP3 server
    sprintf(buf, "USER %s\r\n", username);
    write(sockfd, buf, strlen(buf));
    read(sockfd, buf, 1024);

    sprintf(buf, "PASS %s\r\n", password);
    write(sockfd, buf, strlen(buf));
    read(sockfd, buf, 1024);

    // List messages
    sprintf(buf, "LIST\r\n");
    write(sockfd, buf, strlen(buf));
    read(sockfd, mail, 1024);

    // Select message
    printf("Enter message number:");
    scanf("%d", &i);

    // Get message
    sprintf(buf, "RETR %d\r\n", i);
    write(sockfd, buf, strlen(buf));
    read(sockfd, mail, 1024);

    // Print message
    printf("Subject: %s\n", mail);
    printf("From: %s\n", mail);
    printf("To: %s\n", mail);
    printf("Message: %s\n", mail);

    // Logout of POP3 server
    sprintf(buf, "QUIT\r\n");
    write(sockfd, buf, strlen(buf));
    read(sockfd, buf, 1024);

    close(sockfd);

    return 0;
}