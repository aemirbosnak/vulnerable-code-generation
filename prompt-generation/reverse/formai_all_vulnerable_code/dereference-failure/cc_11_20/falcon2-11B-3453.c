//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

struct email {
    char recipient[1024];
    char sender[1024];
    char subject[1024];
    char body[BUF_SIZE];
};

int main(int argc, char *argv[]) {
    struct email email;
    char buf[BUF_SIZE];

    if (argc!= 5) {
        printf("Usage: %s recipient_1 recipient_2... recipient_n'subject' 'body'\n", argv[0]);
        return 1;
    }

    strcpy(email.recipient, argv[1]);
    strcpy(email.sender, argv[2]);
    strcpy(email.subject, argv[3]);
    strcpy(email.body, argv[4]);

    email.sender[strlen(email.sender) - 1] = '\0';
    email.recipient[strlen(email.recipient) - 1] = '\0';

    int sockfd, portno;
    struct hostent *server;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("ERROR opening socket\n");
        return 1;
    }

    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        printf("ERROR, no such host\n");
        return 1;
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(25);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("ERROR connecting\n");
        return 1;
    }

    printf("Sending HELO command...\n");
    if (send(sockfd, "HELO localhost\r\n", strlen("HELO localhost\r\n"), 0) < 0) {
        printf("ERROR sending HELO command\n");
        return 1;
    }

    printf("Sending MAIL FROM command...\n");
    if (send(sockfd, "MAIL FROM: ", strlen("MAIL FROM: "), 0) < 0) {
        printf("ERROR sending MAIL FROM command\n");
        return 1;
    }
    if (send(sockfd, email.sender, strlen(email.sender), 0) < 0) {
        printf("ERROR sending sender\n");
        return 1;
    }
    if (send(sockfd, "\r\n", 2, 0) < 0) {
        printf("ERROR sending \r\n\n");
        return 1;
    }

    for (int i = 0; i < argc - 4; i++) {
        printf("Sending RCPT TO command...\n");
        if (send(sockfd, "RCPT TO: ", strlen("RCPT TO: "), 0) < 0) {
            printf("ERROR sending RCPT TO command\n");
            return 1;
        }
        if (send(sockfd, email.recipient, strlen(email.recipient), 0) < 0) {
            printf("ERROR sending recipient\n");
            return 1;
        }
        if (send(sockfd, "\r\n", 2, 0) < 0) {
            printf("ERROR sending \r\n\n");
            return 1;
        }
    }

    printf("Sending DATA command...\n");
    if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        printf("ERROR sending DATA command\n");
        return 1;
    }
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        printf("ERROR sending data\n");
        return 1;
    }

    printf("Sending QUIT command...\n");
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        printf("ERROR sending QUIT command\n");
        return 1;
    }

    close(sockfd);

    return 0;
}