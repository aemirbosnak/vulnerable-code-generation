//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    char *server = "localhost";
    int sockfd;
    struct addrinfo hints, *serverinfo;

    // Initialize hints structure
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address information for server
    if (getaddrinfo(server, "110", &hints, &serverinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(gai_error()));
        return 1;
    }

    // Create socket
    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to server
    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    // Send USER command
    char username[50];
    printf("Enter username: ");
    scanf("%s", username);
    char user_cmd[100] = "USER ";
    strcat(user_cmd, username);
    send(sockfd, user_cmd, strlen(user_cmd), 0);

    // Send PASS command
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);
    char pass_cmd[100] = "PASS ";
    strcat(pass_cmd, password);
    send(sockfd, pass_cmd, strlen(pass_cmd), 0);

    // Send STAT command
    char stat_cmd[100] = "STAT ";
    send(sockfd, stat_cmd, strlen(stat_cmd), 0);

    // Receive response
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        perror("recv");
        close(sockfd);
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);
    return 0;
}