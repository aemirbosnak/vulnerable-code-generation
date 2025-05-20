//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define IMAP_SERVER "imap.gmail.com"
#define IMAP_PORT 993

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    char response[1024];
    char username[256];
    char password[256];

    // Connect to the IMAP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(IMAP_PORT);

    if (inet_pton(AF_INET, IMAP_SERVER, &servaddr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Login to the IMAP server
    printf("Username: ");
    fflush(stdout);
    fgets(username, sizeof(username), stdin);
    username[strlen(username)-1] = '\0';

    printf("Password: ");
    fflush(stdout);
    fgets(password, sizeof(password), stdin);
    password[strlen(password)-1] = '\0';

    sprintf(response, "LOGIN %s %s\n", username, password);
    if (send(sockfd, response, strlen(response), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Logged in\n");
    }

    // List the available mailboxes
    sprintf(response, "LIST \"\" *\n");
    if (send(sockfd, response, strlen(response), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }

    printf("Available mailboxes:\n");
    while (1) {
        if (recv(sockfd, response, sizeof(response), 0) < 0) {
            perror("recv() failed");
            exit(EXIT_FAILURE);
        }

        if (strstr(response, "OK LIST") != NULL) {
            break;
        }

        printf("%s", response);
        fflush(stdout);
    }

    // Select a mailbox
    printf("Enter the name of the mailbox to select: ");
    fflush(stdout);
    fgets(response, sizeof(response), stdin);
    response[strlen(response)-1] = '\0';

    sprintf(response, "SELECT %s\n", response);
    if (send(sockfd, response, strlen(response), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Mailbox selected\n");
    }

    // Fetch the message headers from the selected mailbox
    sprintf(response, "FETCH 1:* RFC822.HEADER\n");
    if (send(sockfd, response, strlen(response), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (recv(sockfd, response, sizeof(response), 0) < 0) {
            perror("recv() failed");
            exit(EXIT_FAILURE);
        }

        if (strstr(response, "OK FETCH") != NULL) {
            break;
        }

        printf("%s", response);
        fflush(stdout);
    }

    // Logout from the IMAP server
    sprintf(response, "LOGOUT\n");
    if (send(sockfd, response, strlen(response), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Logged out\n");
    }

    // Close the socket
    close(sockfd);

    return 0;
}