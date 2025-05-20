//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd;
    char buffer[BUFFER_SIZE];

    if(argc < 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        fprintf(stderr, "Error: Unable to open socket.\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "Error: No such host.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Unable to connect to server.\n");
        exit(1);
    }

    printf("Connected to IMAP server %s on port %s.\n", argv[1], argv[2]);

    int n;
    char response_code[BUFFER_SIZE];
    char sent_msg[BUFFER_SIZE];

    // Send login command to server
    memset(sent_msg, 0, sizeof(sent_msg));
    sprintf(sent_msg, "a001 LOGIN my_username my_password\r\n");
    write(sockfd, sent_msg, strlen(sent_msg));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE);
    strncpy(response_code, buffer, 3);
    response_code[3] = '\0';

    if(strcmp(response_code, "a01") != 0) {
        fprintf(stderr, "Error: Login failed. Response code: %s\n", response_code);
        exit(1);
    }

    printf("Logged in successfully.\n");

    // Send command to list mailboxes
    memset(sent_msg, 0, sizeof(sent_msg));
    sprintf(sent_msg, "a002 LIST \"\" *\r\n");
    write(sockfd, sent_msg, strlen(sent_msg));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE);
    strncpy(response_code, buffer, 3);
    response_code[3] = '\0';

    if(strcmp(response_code, "a02") != 0) {
        fprintf(stderr, "Error: Unable to list mailboxes. Response code: %s\n", response_code);
        exit(1);
    }

    printf("Mailboxes:\n%s", buffer);

    // Send command to select mailbox
    memset(sent_msg, 0, sizeof(sent_msg));
    sprintf(sent_msg, "a003 SELECT INBOX\r\n");
    write(sockfd, sent_msg, strlen(sent_msg));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE);
    strncpy(response_code, buffer, 3);
    response_code[3] = '\0';

    if(strcmp(response_code, "a03") != 0) {
        fprintf(stderr, "Error: Unable to select mailbox. Response code: %s\n", response_code);
        exit(1);
    }

    printf("Mailbox selected.\n");

    // Send command to retrieve mailbox status
    memset(sent_msg, 0, sizeof(sent_msg));
    sprintf(sent_msg, "a004 STATUS INBOX (MESSAGES UNSEEN)\r\n");
    write(sockfd, sent_msg, strlen(sent_msg));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE);
    strncpy(response_code, buffer, 3);
    response_code[3] = '\0';

    if(strcmp(response_code, "a04") != 0) {
        fprintf(stderr, "Error: Unable to retrieve mailbox status. Response code: %s\n", response_code);
        exit(1);
    }

    printf("Mailbox status:\n%s", buffer);

    // Send command to retrieve message headers
    memset(sent_msg, 0, sizeof(sent_msg));
    sprintf(sent_msg, "a005 FETCH 1:* (FLAGS ENVELOPE BODY[HEADER.FIELDS (FROM DATE SUBJECT)])\r\n");
    write(sockfd, sent_msg, strlen(sent_msg));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE);
    strncpy(response_code, buffer, 3);
    response_code[3] = '\0';

    if(strcmp(response_code, "a05") != 0) {
        fprintf(stderr, "Error: Unable to retrieve message headers. Response code: %s\n", response_code);
        exit(1);
    }

    printf("Message headers:\n%s", buffer);

    // Send logout command to server
    memset(sent_msg, 0, sizeof(sent_msg));
    sprintf(sent_msg, "a006 LOGOUT\r\n");
    write(sockfd, sent_msg, strlen(sent_msg));

    // Receive server response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, BUFFER_SIZE);
    strncpy(response_code, buffer, 3);
    response_code[3] = '\0';

    if(strcmp(response_code, "a06") != 0) {
        fprintf(stderr, "Error: Logout failed. Response code: %s\n", response_code);
        exit(1);
    }

    printf("Logged out successfully.\n");

    close(sockfd);
    return 0;
}