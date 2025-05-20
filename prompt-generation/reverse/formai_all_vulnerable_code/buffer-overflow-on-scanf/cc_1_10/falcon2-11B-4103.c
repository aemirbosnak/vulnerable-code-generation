//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to connect to IMAP server
int connect_to_imap(const char *host, const char *port) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;

    server = gethostbyname(host);
    if (server == NULL) {
        perror("gethostbyname() failed");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        return -1;
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect() failed");
        return -1;
    }

    bzero((char *) &clientaddr, sizeof(clientaddr));
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_addr.s_addr = INADDR_ANY;
    clientaddr.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr *) &clientaddr, sizeof(clientaddr)) < 0) {
        perror("bind() failed");
        return -1;
    }

    return sockfd;
}

// Function to send IMAP command
int send_command(int sockfd, const char *command) {
    int n;
    char buffer[256];
    strcpy(buffer, command);
    buffer[strlen(command)] = '\r';
    buffer[strlen(command) + 1] = '\n';
    n = write(sockfd, buffer, strlen(buffer) + 1);
    if (n <= 0) {
        perror("write() failed");
        return -1;
    }
    return n;
}

// Function to receive IMAP response
int receive_response(int sockfd, char *response) {
    int n;
    char buffer[256];
    n = read(sockfd, buffer, 256);
    if (n <= 0) {
        perror("read() failed");
        return -1;
    }
    response[strlen(response)] = '\0';
    return n;
}

// Function to check if response is OK
int is_ok_response(char *response) {
    if (strcmp(response, "OK") == 0)
        return 1;
    return 0;
}

// Function to check if response is NO
int is_no_response(char *response) {
    if (strcmp(response, "NO") == 0)
        return 1;
    return 0;
}

// Function to check if response is BYE
int is_bye_response(char *response) {
    if (strcmp(response, "BYE") == 0)
        return 1;
    return 0;
}

int main() {
    int sockfd;
    int port = 143;
    char host[256];
    char command[256];

    printf("Enter IMAP hostname: ");
    scanf("%s", host);

    printf("Enter IMAP port: ");
    scanf("%d", &port);

    sockfd = connect_to_imap(host, port);
    if (sockfd < 0) {
        perror("Connection failed");
        return -1;
    }

    printf("Enter IMAP command: ");
    scanf("%s", command);

    if (send_command(sockfd, command) < 0) {
        perror("Command send failed");
        return -1;
    }

    char response[256];
    if (receive_response(sockfd, response) < 0) {
        perror("Response receive failed");
        return -1;
    }

    if (is_ok_response(response))
        printf("OK\n");
    else if (is_no_response(response))
        printf("NO\n");
    else if (is_bye_response(response))
        printf("BYE\n");
    else
        printf("Unknown response\n");

    close(sockfd);
    return 0;
}