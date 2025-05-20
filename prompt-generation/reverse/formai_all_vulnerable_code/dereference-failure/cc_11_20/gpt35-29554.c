//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define POP3_PORT 110 /* POP3 standard port */

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[1024];
    char user[50], pass[50];
    char *msg;

    /* Check for hostname and username/password */
    if(argc < 2) {
        printf("Usage: popclient <hostname> <username> <password>\n");
        exit(1);
    }

    /* Set server hostname */
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "Error: Cannot resolve hostname %s\n", argv[1]);
        exit(1);
    }

    /* Create socket */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Cannot create socket\n");
        exit(1);
    }

    /* Set server address and port */
    bzero((char *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);

    /* Connect to server */
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error: Cannot connect to server\n");
        exit(1);
    }

    /* Receive server greeting */
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read socket\n");
        exit(1);
    }
    printf("%s", buffer);

    /* Send user login */
    sprintf(user, "USER %s\r\n", argv[2]);
    write(sockfd, user, strlen(user));
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read socket\n");
        exit(1);
    }
    printf("%s", buffer);

    /* Send password */
    sprintf(pass, "PASS %s\r\n", argv[3]);
    write(sockfd, pass, strlen(pass));
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read socket\n");
        exit(1);
    }
    printf("%s", buffer);

    /* Get mailbox status */
    write(sockfd, "STAT\r\n", strlen("STAT\r\n"));
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read socket\n");
        exit(1);
    }
    printf("%s", buffer);

    /* Get list of mailbox messages */
    write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read socket\n");
        exit(1);
    }
    printf("%s", buffer);

    /* Get message count */
    int msg_count = atoi(strchr(buffer, ' ')+1);

    /* Retrieve messages */
    for(int i = 1; i <= msg_count; i++) {
        /* Retrieve message by ID */
        sprintf(buffer, "RETR %d\r\n", i);
        write(sockfd, buffer, strlen(buffer));

        /* Read message */
        bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer)-1);
        if(n < 0) {
            fprintf(stderr, "Error: Cannot read socket\n");
            exit(1);
        }
        printf("%s", buffer);
    }

    /* Quit session */
    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if(n < 0) {
        fprintf(stderr, "Error: Cannot read socket\n");
        exit(1);
    }
    printf("%s", buffer);

    /* Close connection */
    close(sockfd);

    return 0;
}