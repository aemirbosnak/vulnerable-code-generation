//FormAI DATASET v1.0 Category: Networking ; Style: scientific
/*
 * This program demonstrates a simple client-server communication using socket programming in C language.
 * The client sends a message to the server and the server responds with the length of the message.
 * 
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080
#define MAX_MSG 1024

int main(int argc, char const *argv[]) {
    // Creating the socket file descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Socket created successfully\n");
    }
    
    // Creating the structure to specify the server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Connected to the server successfully\n");
    }

    // Sending message to the server
    char msg[MAX_MSG];
    printf("Enter a message to send to the server: ");
    scanf("%[^\n]", msg);
    getchar();
    write(sockfd, msg, strlen(msg));
    printf("Message sent to the server\n");

    // Reading the message from the server
    char buffer[MAX_MSG];
    int len = read(sockfd, buffer, sizeof(buffer));
    buffer[len] = '\0';
    printf("Message received from the server: %s\n", buffer);

    // Closing the socket
    close(sockfd);
    return 0;
}