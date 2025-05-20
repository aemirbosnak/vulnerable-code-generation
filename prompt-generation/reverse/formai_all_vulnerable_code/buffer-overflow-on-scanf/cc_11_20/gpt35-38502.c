//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1000

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *host;

    if(argc != 2) {
        printf("usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Resolve hostname
    host = gethostbyname(argv[1]);

    if(host == NULL) {
        printf("Error: Problem in resolving the hostname.\n");
        exit(2);
    }

    // Create socket
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Couldn't create socket.\n");
        exit(3);
    }

    // Initialize server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(host->h_addr);
    servaddr.sin_port = htons(21); // FTP port

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Couldn't connect to server.\n");
        exit(4);
    }

    // Read welcome message from server
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error: Couldn't receive message from server.\n");
        exit(5);
    }

    recvline[n] = '\0'; // null terminate string

    printf("FTP server: %s", recvline); // print welcome message

    // Authenticate with server (username)
    char username[256], password[256];
    printf("Username: ");
    scanf("%s", username);

    char user_command[MAXLINE + 1];
    sprintf(user_command, "USER %s\r\n", username);
    send(sockfd, user_command, strlen(user_command), 0);

    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error: Couldn't receive response from server.\n");
        exit(6);
    }

    recvline[n] = '\0'; // null terminate string

    if(recvline[0] == '2') {
        printf("Successfully authenticated with username %s.\n", username);
    } else {
        printf("Error: Username not recognized by server.\n");
        exit(7);
    }

    // Authenticate with server (password)
    printf("Password: ");
    scanf("%s", password);

    char pass_command[MAXLINE + 1];
    sprintf(pass_command, "PASS %s\r\n", password);
    send(sockfd, pass_command, strlen(pass_command), 0);

    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error: Couldn't receive response from server.\n");
        exit(8);
    }

    recvline[n] = '\0'; // null terminate string

    if(recvline[0] == '2') {
        printf("Successfully authenticated with password %s.\n", password);
    } else {
        printf("Error: Incorrect password.\n");
        exit(9);
    }

    // Request file list from server
    char list_command[MAXLINE];
    strcpy(list_command, "LIST\r\n");
    send(sockfd, list_command, strlen(list_command), 0);

    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error: Couldn't receive response from server.\n");
        exit(10);
    }

    recvline[n] = '\0'; // null terminate string

    printf("%s", recvline); // print file list

    // Terminate connection
    char quit_command[MAXLINE];
    strcpy(quit_command, "QUIT\r\n");
    send(sockfd, quit_command, strlen(quit_command), 0);

    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error: Couldn't receive response from server.\n");
        exit(11);
    }

    recvline[n] = '\0'; // null terminate string

    printf("%s", recvline); // print goodbye message

    // Close socket
    close(sockfd);

    exit(0);
}