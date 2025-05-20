//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MSG_LENGTH 1024

int main(int argc, char** argv) {
    // Check if hostname and port number are passed as arguments
    if(argc != 3) {
        printf("Usage: %s <hostname> <port number>\n", argv[0]);
        return 1;
    }

    // Get server details using getaddrinfo
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // Use IPv4
    hints.ai_socktype = SOCK_STREAM; // Use TCP protocol

    int status = getaddrinfo(argv[1], argv[2], &hints, &result);
    if(status != 0) {
        printf("Error: %s\n", gai_strerror(status));
        return 1;
    }

    // Create socket
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(sockfd == -1) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    // Connect to server
    status = connect(sockfd, result->ai_addr, result->ai_addrlen);
    if(status == -1) {
        printf("Error: Failed to connect\n");
        return 1;
    }

    // Receive connection greeting from server
    char msg[MAX_MSG_LENGTH];
    memset(&msg, 0, sizeof(msg));
    status = recv(sockfd, msg, sizeof(msg), 0);
    if(status == -1) {
        printf("Error: Failed to receive greeting\n");
        return 1;
    }

    printf("%s", msg);

    // Send user details to server
    char user[MAX_MSG_LENGTH];
    printf("User: ");
    fgets(user, sizeof(user), stdin);

    char user_cmd[MAX_MSG_LENGTH];
    sprintf(user_cmd, "USER %s", user);
    status = send(sockfd, user_cmd, strlen(user_cmd), 0);
    if(status == -1) {
        printf("Error: Failed to send user details\n");
        return 1;
    }

    memset(&msg, 0, sizeof(msg));
    status = recv(sockfd, msg, sizeof(msg), 0);
    if(status == -1) {
        printf("Error: Failed to receive response\n");
        return 1;
    }

    printf("%s", msg);

    // Send password to server
    char pass[MAX_MSG_LENGTH];
    printf("Password: ");
    fgets(pass, sizeof(pass), stdin);

    char pass_cmd[MAX_MSG_LENGTH];
    sprintf(pass_cmd, "PASS %s", pass);
    status = send(sockfd, pass_cmd, strlen(pass_cmd), 0);
    if(status == -1) {
        printf("Error: Failed to send password\n");
        return 1;
    }

    memset(&msg, 0, sizeof(msg));
    status = recv(sockfd, msg, sizeof(msg), 0);
    if(status == -1) {
        printf("Error: Failed to receive response\n");
        return 1;
    }

    printf("%s", msg);

    // Send LIST command to server
    char list_cmd[MAX_MSG_LENGTH];
    sprintf(list_cmd, "LIST");
    status = send(sockfd, list_cmd, strlen(list_cmd), 0);
    if(status == -1) {
        printf("Error: Failed to send LIST command\n");
        return 1;
    }

    memset(&msg, 0, sizeof(msg));
    status = recv(sockfd, msg, sizeof(msg), 0);
    if(status == -1) {
        printf("Error: Failed to receive response\n");
        return 1;
    }

    printf("%s", msg);

    // Close socket and free memory
    close(sockfd);
    freeaddrinfo(result);

    return 0;
}