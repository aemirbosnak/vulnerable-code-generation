//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s [POP3 server address] [POP3 server port]\n", argv[0]);
        exit(1);
    }

    const char *server_address = argv[1];
    const char *server_port = argv[2];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    // Fill in the server's address and port
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(server_port));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    // Read the greeting from the server
    char buf[BUF_SIZE];
    bzero(buf, BUF_SIZE);
    if (read(sockfd, buf, BUF_SIZE - 1) == -1) {
        perror("read failed");
        exit(1);
    }
    printf("Greeting from server: %s\n", buf);

    // Send the user's name and password to authenticate
    char username[100];
    char password[100];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    char auth[200];
    sprintf(auth, "USER %s\r\nPASS %s\r\n", username, password);
    if (send(sockfd, auth, strlen(auth), 0) == -1) {
        perror("send failed");
        exit(1);
    }

    // Read the response from the server and check if authenticated
    bzero(buf, BUF_SIZE);
    if (read(sockfd, buf, BUF_SIZE - 1) == -1) {
        perror("read failed");
        exit(1);
    }
    printf("Authentication response from server: %s\n", buf);
    if (strstr(buf, "+OK") == NULL) {
        printf("Authentication failed\n");
        exit(1);
    }

    // Send the LIST command to get the list of messages
    if (send(sockfd, "LIST\r\n", 6, 0) == -1) {
        perror("send failed");
        exit(1);
    }

    // Read the response from the server and print the list
    bzero(buf, BUF_SIZE);
    if (read(sockfd, buf, BUF_SIZE - 1) == -1) {
        perror("read failed");
        exit(1);
    }
    printf("Message list from server:\n%s\n", buf);

    // Send the RETR command to retrieve a message
    printf("Enter the message number you want to retrieve: ");
    int msg_number;
    scanf("%d", &msg_number);

    char retr[100];
    sprintf(retr, "RETR %d\r\n", msg_number);
    if (send(sockfd, retr, strlen(retr), 0) == -1) {
        perror("send failed");
        exit(1);
    }

    // Read the response from the server and print the message
    bzero(buf, BUF_SIZE);
    if (read(sockfd, buf, BUF_SIZE - 1) == -1) {
        perror("read failed");
        exit(1);
    }
    printf("Message from server:\n%s\n", buf);

    // Send the QUIT command to end the session
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("send failed");
        exit(1);
    }

    // Read the response from the server and close the socket
    bzero(buf, BUF_SIZE);
    if (read(sockfd, buf, BUF_SIZE - 1) == -1) {
        perror("read failed");
        exit(1);
    }
    printf("Closing connection to server: %s\n", buf);

    close(sockfd);

    return 0;
}