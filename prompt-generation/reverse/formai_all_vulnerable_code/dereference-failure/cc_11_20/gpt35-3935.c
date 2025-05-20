//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
    int sockfd, n;
    char recvBuff[1024];
    char user[100];
    char pass[100];
    struct sockaddr_in serv_addr;
    struct hostent *host;

    // Check if user entered correct number of arguments
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the hostname from the command line argument
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("ERROR: Invalid hostname\n");
        return 1;
    }

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Could not create socket");
        return 1;
    }

    // Set the server address details
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Could not connect to server");
        return 1;
    }

    // Receive server greeting message
    memset(recvBuff, 0, sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff) - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server");
        return 1;
    } else if (strstr(recvBuff, "+OK") == NULL) {
        printf("ERROR: Server did not greet properly\n");
        return 1;
    }
    printf("%s\n", recvBuff);

    // Send username to the server
    printf("Username: ");
    fgets(user, 100, stdin);
    int user_len = strlen(user) - 1;
    user[user_len] = '\0';
    char user_cmd[100] = "USER ";
    strcat(user_cmd, user);
    strcat(user_cmd, "\r\n");
    n = write(sockfd, user_cmd, strlen(user_cmd));
    if (n < 0) {
        perror("ERROR: Could not write to server");
        return 1;
    }

    // Receive the response from the server after sending the username
    memset(recvBuff, 0, sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff) - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server");
        return 1;
    } else if (strstr(recvBuff, "+OK") == NULL) {
        printf("ERROR: Invalid username\n");
        return 1;
    }

    // Send password to the server
    printf("Password: ");
    scanf("%s", pass);
    char pass_cmd[100] = "PASS ";
    strcat(pass_cmd, pass);
    strcat(pass_cmd, "\r\n");
    n = write(sockfd, pass_cmd, strlen(pass_cmd));
    if (n < 0) {
        perror("ERROR: Could not write to server");
        return 1;
    }

    // Receive the response from the server after sending the password
    memset(recvBuff, 0, sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff) - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server");
        return 1;
    } else if (strstr(recvBuff, "+OK") == NULL) {
        printf("ERROR: Invalid password\n");
        return 1;
    }

    // Send a request to list the messages
    n = write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
    if (n < 0) {
        perror("ERROR: Could not write to server");
        return 1;
    }

    // Receive the response from the server after sending the list request
    memset(recvBuff, 0, sizeof(recvBuff));
    n = read(sockfd, recvBuff, sizeof(recvBuff) - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server");
        return 1;
    } else if (strstr(recvBuff, "+OK") == NULL) {
        printf("ERROR: Could not list messages\n");
        return 1;
    }
    printf("%s\n", recvBuff);

    // Exit gracefully
    close(sockfd);
    return 0;
}