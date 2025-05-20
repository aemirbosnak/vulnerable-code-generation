//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 21

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[1024];
    char response[1024];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(1);
    }

    // Clearing serveraddr variable and filling values in it
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server at port %d...\n", PORT);

    // Receiving and displaying server welcome
    recv(sockfd, response, sizeof(response), 0);
    printf("%s", response);

    // Sending username
    printf("Enter username: ");
    scanf("%s", buffer);

    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receiving and displaying server response
    memset(response, 0, sizeof(response));
    recv(sockfd, response, sizeof(response), 0);
    printf("%s", response);

    // Sending password
    printf("Enter password: ");
    scanf("%s", buffer);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receiving and displaying server response
    memset(response, 0, sizeof(response));
    recv(sockfd, response, sizeof(response), 0);
    printf("%s", response);

    // Sending PASV command to enter passive mode
    send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0);

    // Receiving server's data port number
    memset(response, 0, sizeof(response));
    recv(sockfd, response, sizeof(response), 0);
    printf("%s", response);

    // Parsing the data port number from response string
    char *token;
    char data_port_num[6];
    token = strtok(response, ",");
    int i = 0;
    while (token != NULL) {
        if (i == 4) {
            strcpy(data_port_num, token);
        }
        if (i == 5) {
            strcat(data_port_num, token);
            break;
        }
        token = strtok(NULL, ",");
        i++;
    }

    // Converting data port number to integer and adding 1 to get actual data port
    int d_port = atoi(data_port_num) + 1;

    // Creating data socket file descriptor
    int data_sockfd;
    if ((data_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Data socket creation error");
        exit(1);
    }

    // Clearing serveraddr variable and filling values in it
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(d_port);

    // Connecting to the server at data port
    if (connect(data_sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Data connection failed");
        exit(1);
    }

    printf("Data connection established with server...\n");

    // Sending LIST command to get file listing
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);

    // Receiving file listing and displaying it
    memset(response, 0, sizeof(response));
    recv(data_sockfd, response, sizeof(response), 0);
    printf("%s", response);

    // Closing data socket and terminating program
    close(data_sockfd);
    close(sockfd);
    return 0;
}