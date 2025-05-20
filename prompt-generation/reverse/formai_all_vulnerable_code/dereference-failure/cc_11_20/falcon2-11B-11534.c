//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdbool.h>

#define PORT 993
#define MAX_BUFFER_SIZE 1024
#define MAX_MAILBOXES 100

typedef struct mailbox {
    char name[MAX_MAILBOXES][MAX_BUFFER_SIZE];
    int num_messages;
} mailbox;

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];
    int num_mailboxes;
    mailbox mailboxes[MAX_MAILBOXES];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s imap_server\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Socket creation failed\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Connection failed\n");
        exit(1);
    }

    printf("Connected to IMAP server\n");

    numbytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (numbytes < 0) {
        fprintf(stderr, "Error: Reading from socket failed\n");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    numbytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (numbytes < 0) {
        fprintf(stderr, "Error: Reading from socket failed\n");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    num_mailboxes = atoi(buffer);
    if (num_mailboxes < 0) {
        fprintf(stderr, "Error: Invalid mailbox count\n");
        exit(1);
    }

    for (int i = 0; i < num_mailboxes; i++) {
        printf("Fetching mailbox %s...\n", buffer);

        numbytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
        if (numbytes < 0) {
            fprintf(stderr, "Error: Reading from socket failed\n");
            exit(1);
        }

        printf("Server response: %s\n", buffer);

        bzero(mailboxes[i].name, MAX_BUFFER_SIZE);
        bcopy(buffer, mailboxes[i].name, MAX_BUFFER_SIZE);
        mailboxes[i].num_messages = atoi(buffer);
        if (mailboxes[i].num_messages < 0) {
            fprintf(stderr, "Error: Invalid message count\n");
            exit(1);
        }

        printf("Mailbox %s has %d messages\n", mailboxes[i].name, mailboxes[i].num_messages);
    }

    for (int i = 0; i < num_mailboxes; i++) {
        printf("Deleting mailbox %s...\n", mailboxes[i].name);

        numbytes = write(sockfd, "DELETE \"%s\"\n", mailboxes[i].name);
        if (numbytes < 0) {
            fprintf(stderr, "Error: Writing to socket failed\n");
            exit(1);
        }

        numbytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
        if (numbytes < 0) {
            fprintf(stderr, "Error: Reading from socket failed\n");
            exit(1);
        }

        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}