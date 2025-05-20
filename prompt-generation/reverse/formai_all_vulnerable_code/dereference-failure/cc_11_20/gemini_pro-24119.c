//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = getpass("Enter your password: ");

    // Create a socket for connecting to the POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the server's hostname to an IP address
    struct hostent *hostinfo = gethostbyname(server);
    if (hostinfo == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", server);
        exit(1);
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *(struct in_addr *)hostinfo->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive the welcome message from the POP3 server
    char welcome_msg[MAX_LINE_LENGTH];
    if (recv(sockfd, welcome_msg, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", welcome_msg);

    // Send the USER command to the POP3 server
    char user_cmd[MAX_LINE_LENGTH];
    sprintf(user_cmd, "USER %s\r\n", username);
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the response to the USER command
    char user_response[MAX_LINE_LENGTH];
    if (recv(sockfd, user_response, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", user_response);

    // Send the PASS command to the POP3 server
    char pass_cmd[MAX_LINE_LENGTH];
    sprintf(pass_cmd, "PASS %s\r\n", password);
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the response to the PASS command
    char pass_response[MAX_LINE_LENGTH];
    if (recv(sockfd, pass_response, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", pass_response);

    // Send the STAT command to the POP3 server
    char stat_cmd[MAX_LINE_LENGTH];
    sprintf(stat_cmd, "STAT\r\n");
    if (send(sockfd, stat_cmd, strlen(stat_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the response to the STAT command
    char stat_response[MAX_LINE_LENGTH];
    if (recv(sockfd, stat_response, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", stat_response);

    // Send the LIST command to the POP3 server
    char list_cmd[MAX_LINE_LENGTH];
    sprintf(list_cmd, "LIST\r\n");
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the response to the LIST command
    char list_response[MAX_LINE_LENGTH];
    while (recv(sockfd, list_response, MAX_LINE_LENGTH, 0) > 0) {
        printf("%s", list_response);
    }

    // Send the QUIT command to the POP3 server
    char quit_cmd[MAX_LINE_LENGTH];
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}