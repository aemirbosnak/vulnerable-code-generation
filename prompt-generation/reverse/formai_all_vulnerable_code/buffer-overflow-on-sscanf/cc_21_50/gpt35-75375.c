//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110 // the default port for POP3 communication
#define MAX_MSG_LEN 4096 // the maximum size of an email message

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[MAX_MSG_LEN];
    char username[256], password[256]; // email credentials

    if (argc != 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    // initialize the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connection error");
        exit(EXIT_FAILURE);
    }

    // receive the welcome message
    if ((n = recv(sockfd, buf, MAX_MSG_LEN, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // send the user login command
    printf("username: ");
    scanf("%s", username);
    snprintf(buf, MAX_MSG_LEN, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    // receive the response to the user login command
    if ((n = recv(sockfd, buf, MAX_MSG_LEN, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // send the password command
    printf("password: ");
    scanf("%s", password);
    snprintf(buf, MAX_MSG_LEN, "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    // receive the response to the password command
    if ((n = recv(sockfd, buf, MAX_MSG_LEN, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // send the list command to get the number of messages in the mailbox
    snprintf(buf, MAX_MSG_LEN, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    // receive the response to the list command
    if ((n = recv(sockfd, buf, MAX_MSG_LEN, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // parse the number of messages in the mailbox
    int num_messages;
    sscanf(buf, "+OK %d messages\r\n", &num_messages);

    // loop over the list of messages and download each one
    for (int i = 1; i <= num_messages; i++) {
        // send the retrieve command to download the message
        snprintf(buf, MAX_MSG_LEN, "RETR %d\r\n", i);
        if (send(sockfd, buf, strlen(buf), 0) < 0) {
            perror("send error");
            exit(EXIT_FAILURE);
        }

        // receive the response to the retrieve command
        if ((n = recv(sockfd, buf, MAX_MSG_LEN, 0)) < 0) {
            perror("recv error");
            exit(EXIT_FAILURE);
        }
        buf[n] = '\0';
        printf("%s", buf);

        // receive the actual message
        char msg[MAX_MSG_LEN];
        int msg_len = 0;
        while ((n = recv(sockfd, buf, MAX_MSG_LEN, 0)) > 0) {
            memcpy(&msg[msg_len], buf, n);
            msg_len += n;
            if (msg_len >= MAX_MSG_LEN) break;
        }
        msg[msg_len] = '\0';
        printf("%s", msg);

        // send the delete command to mark the message for deletion
        snprintf(buf, MAX_MSG_LEN, "DELE %d\r\n", i);
        if (send(sockfd, buf, strlen(buf), 0) < 0) {
            perror("send error");
            exit(EXIT_FAILURE);
        }

        // receive the response to the delete command
        if ((n = recv(sockfd, buf, MAX_MSG_LEN, 0)) < 0) {
            perror("recv error");
            exit(EXIT_FAILURE);
        }
        buf[n] = '\0';
        printf("%s", buf);
    }

    // send the quit command to exit gracefully
    snprintf(buf, MAX_MSG_LEN, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    // receive the response to the quit command
    if ((n = recv(sockfd, buf, MAX_MSG_LEN, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // close the socket
    close(sockfd);

    return 0;
}