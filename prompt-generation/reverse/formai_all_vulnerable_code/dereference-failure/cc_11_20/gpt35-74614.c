//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define MAX_MSG_LEN 2048

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket()");
        return 1;
    }

    // Get server address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host as %s\n", argv[1]);
        return 1;
    }

    // Configure server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect()");
        return 1;
    }

    // Receive server response
    char msg[MAX_MSG_LEN];
    memset(msg, 0, sizeof(msg));
    if (recv(sockfd, msg, MAX_MSG_LEN, 0) < 0) {
        perror("recv()");
        return 1;
    }

    printf("%s", msg);

    // Send USER command
    char user_cmd[MAX_MSG_LEN];
    memset(user_cmd, 0, sizeof(user_cmd));
    printf("Username: ");
    fgets(user_cmd, MAX_MSG_LEN, stdin);
    sprintf(user_cmd, "USER %s", strtok(user_cmd, "\n"));
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
        perror("send()");
        return 1;
    }

    // Receive server response
    memset(msg, 0, sizeof(msg));
    if (recv(sockfd, msg, MAX_MSG_LEN, 0) < 0) {
        perror("recv()");
        return 1;
    }

    printf("%s", msg);

    // Send PASS command
    char pass_cmd[MAX_MSG_LEN];
    memset(pass_cmd, 0, sizeof(pass_cmd));
    printf("Password: ");
    fgets(pass_cmd, MAX_MSG_LEN, stdin);
    sprintf(pass_cmd, "PASS %s", strtok(pass_cmd, "\n"));
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0) {
        perror("send()");
        return 1;
    }

    // Receive server response
    memset(msg, 0, sizeof(msg));
    if (recv(sockfd, msg, MAX_MSG_LEN, 0) < 0) {
        perror("recv()");
        return 1;
    }

    printf("%s", msg);

    // Send LIST command
    char list_cmd[MAX_MSG_LEN];
    memset(list_cmd, 0, sizeof(list_cmd));
    sprintf(list_cmd, "LIST");
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) < 0) {
        perror("send()");
        return 1;
    }

    // Receive server response
    memset(msg, 0, sizeof(msg));
    if (recv(sockfd, msg, MAX_MSG_LEN, 0) < 0) {
        perror("recv()");
        return 1;
    }

    printf("%s", msg);

    // Send QUIT command
    char quit_cmd[MAX_MSG_LEN];
    memset(quit_cmd, 0, sizeof(quit_cmd));
    sprintf(quit_cmd, "QUIT");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0) {
        perror("send()");
        return 1;
    }

    // Receive server response
    memset(msg, 0, sizeof(msg));
    if (recv(sockfd, msg, MAX_MSG_LEN, 0) < 0) {
        perror("recv()");
        return 1;
    }

    printf("%s", msg);

    // Close socket
    close(sockfd);

    return 0;
}