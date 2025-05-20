//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define IMAP_PORT 143
#define IMAP_HOSTNAME "imap.gmail.com"

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char buf[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(IMAP_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(IMAP_HOSTNAME);

    // Connect to the server
    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("connect");
        return 1;
    }

    // Send a login request
    sprintf(buf, "LOGIN %s %s\r\n", "username", "password");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        perror("send");
        return 1;
    }

    // Receive the login response
    ret = recv(sockfd, buf, sizeof(buf), 0);
    if (ret < 0) {
        perror("recv");
        return 1;
    }

    // Check if login was successful
    if (strncmp(buf, "+OK", 3) == 0) {
        printf("Login successful\n");
    } else {
        printf("Login failed: %s\n", buf);
        return 1;
    }

    // Send a list mailboxes request
    sprintf(buf, "LIST \"\"\r\n");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        perror("send");
        return 1;
    }

    // Receive the list mailboxes response
    ret = recv(sockfd, buf, sizeof(buf), 0);
    if (ret < 0) {
        perror("recv");
        return 1;
    }

    // Print the list of mailboxes
    printf("Mailboxes:\n");
    char *mailbox;
    for (mailbox = buf; ; ) {
        if (*mailbox == '\0') {
            break;
        }
        printf("%s\n", mailbox);
        mailbox = strchr(mailbox, '\n') + 1;
    }

    // Send a logout request
    sprintf(buf, "LOGOUT\r\n");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        perror("send");
        return 1;
    }

    // Receive the logout response
    ret = recv(sockfd, buf, sizeof(buf), 0);
    if (ret < 0) {
        perror("recv");
        return 1;
    }

    // Check if logout was successful
    if (strncmp(buf, "+OK", 3) == 0) {
        printf("Logout successful\n");
    } else {
        printf("Logout failed: %s\n", buf);
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}