//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *port = argv[2];
    struct hostent *he;
    struct in_addr **addr_list;
    struct sockaddr_in server_addr;
    int sockfd;

    // get the host information
    if ((he = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "error: could not resolve hostname\n");
        exit(1);
    }
    addr_list = (struct in_addr**) he->h_addr_list;

    // create a socket for the client
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("error");
        exit(1);
    }
    // set up the server information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *addr_list[0];
    server_addr.sin_port = htons(atoi(port));

    // connect to the server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("error");
        exit(1);
    }

    char username[MAX_LINE], password[MAX_LINE];
    printf("Enter your username: ");
    fgets(username, MAX_LINE, stdin);
    printf("Enter your password: ");
    fgets(password, MAX_LINE, stdin);

    // send the USER command
    char command[MAX_LINE];
    sprintf(command, "USER %s", username);
    send(sockfd, command, strlen(command), 0);

    // receive the response for the USER command
    char response[MAX_LINE];
    recv(sockfd, response, MAX_LINE, 0);
    printf("%s", response);

    // send the PASS command
    sprintf(command, "PASS %s", password);
    send(sockfd, command, strlen(command), 0);

    // receive the response for the PASS command
    recv(sockfd, response, MAX_LINE, 0);
    printf("%s", response);

    // send the STAT command
    sprintf(command, "STAT");
    send(sockfd, command, strlen(command), 0);

    // receive the response for the STAT command
    recv(sockfd, response, MAX_LINE, 0);
    printf("%s", response);

    // send the LIST command
    sprintf(command, "LIST");
    send(sockfd, command, strlen(command), 0);

    // receive the response for the LIST command
    recv(sockfd, response, MAX_LINE, 0);
    printf("%s", response);

    // send the RETR command
    int mail_num;
    printf("Enter the mail number to retrieve: ");
    scanf("%d", &mail_num);
    sprintf(command, "RETR %d", mail_num);
    send(sockfd, command, strlen(command), 0);

    // receive the response for the RETR command
    recv(sockfd, response, MAX_LINE, 0);
    printf("%s", response);

    // receive the mail content
    char mail_content[MAX_LINE];
    while (1) {
        recv(sockfd, mail_content, MAX_LINE, 0);
        printf("%s", mail_content);
        if (strstr(mail_content, ".\r\n") != NULL) {
            break;
        }
    }

    // send the QUIT command
    sprintf(command, "QUIT");
    send(sockfd, command, strlen(command), 0);

    // receive the response for the QUIT command
    recv(sockfd, response, MAX_LINE, 0);
    printf("%s", response);

    // close the socket
    close(sockfd);

    return 0;
}