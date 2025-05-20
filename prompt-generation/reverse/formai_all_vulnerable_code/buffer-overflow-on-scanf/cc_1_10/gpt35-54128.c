//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[BUF_SIZE];
    char server_ip[15];
    unsigned short server_port;
    char username[50], password[50];
    int n;

    printf("Welcome to the IMAP client program!\n");

    printf("Please enter the IP address of the IMAP server: ");
    scanf("%s", server_ip);

    printf("Please enter the port number of the IMAP server: ");
    scanf("%hu", &server_port);

    printf("Please enter your email username: ");
    scanf("%s", username);

    printf("Please enter your email password: ");
    scanf("%s", password);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set up server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &servaddr.sin_addr);

    // Connect to server
    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    // Read welcome message from server
    n = read(sockfd, buf, BUF_SIZE-1);
    buf[n] = 0;
    printf("%s\n", buf);

    // Send login information
    send(sockfd, "LOGIN ", 6, 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, " ", 1, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    // Receive response from server
    n = read(sockfd, buf, BUF_SIZE-1);
    buf[n] = 0;
    printf("%s\n", buf);

    // Send command to list emails in inbox
    send(sockfd, "SELECT INBOX\r\n", 15, 0);
    n = read(sockfd, buf, BUF_SIZE-1);
    buf[n] = 0;
    printf("%s\n", buf);

    send(sockfd, "FETCH 1:* FLAGS\r\n", 18, 0);
    n = read(sockfd, buf, BUF_SIZE-1);
    buf[n] = 0;
    printf("%s\n", buf);

    // Close socket
    close(sockfd);

    printf("Thank you for using the IMAP client program!\n");

    return 0;
}