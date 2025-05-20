//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_SIZE 2048

char* receiveResponse(int sockfd);
int sendRequest(int sockfd, char* command);

int main(int argc, char const *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_SIZE];
    char user[50], pass[50], email[50];
    char* response;

    // Prompt user to enter server details
    printf("Enter server hostname: ");
    scanf("%s", buffer);
    server = gethostbyname(buffer);

    printf("Enter server port number: ");
    scanf("%d", &portno);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set server address and port number
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Receive server greeting
    response = receiveResponse(sockfd);
    printf("%s\n", response);

    // Prompt user to enter login details
    printf("Enter username: ");
    scanf("%s", user);

    printf("Enter password: ");
    scanf("%s", pass);

    // Send login command with user and pass
    sprintf(buffer, "USER %s\r\n", user);
    sendRequest(sockfd, buffer);
    response = receiveResponse(sockfd);
    printf("%s\n", response);

    sprintf(buffer, "PASS %s\r\n", pass);
    sendRequest(sockfd, buffer);
    response = receiveResponse(sockfd);
    printf("%s\n", response);

    // Prompt user to enter email number to retrieve
    printf("Enter email number: ");
    scanf("%s", email);

    // Send RETR command with email number
    sprintf(buffer, "RETR %s\r\n", email);
    sendRequest(sockfd, buffer);

    // Receive email
    response = receiveResponse(sockfd);
    while(strncmp(response, ".", 1) != 0) {
        printf("%s\n", response);
        response = receiveResponse(sockfd);
    }

    // Send QUIT command to logout
    sendRequest(sockfd, "QUIT\r\n");
    response = receiveResponse(sockfd);
    printf("%s\n", response);

    // Close socket
    close(sockfd);
    return 0;
}

/*
 * Sends request to server and returns response.
 */
char* receiveResponse(int sockfd) {
    char* buffer = malloc(sizeof(char) * MAX_SIZE);
    bzero(buffer, MAX_SIZE);
    read(sockfd, buffer, MAX_SIZE-1);
    return buffer;
}

/*
 * Sends request to server and returns 1 on success and -1 on error.
 */
int sendRequest(int sockfd, char* command) {
    int n = write(sockfd, command, strlen(command));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }
    return 1;
}