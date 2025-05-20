//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("ERROR opening socket\n");
        exit(0);
    }

    puts("Socket created");

    // Initialize server address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind to port
    ret = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("ERROR on binding\n");
        exit(0);
    }

    puts("Socket bound to port");

    // Listen for incoming connections
    listen(sockfd, 5);
    puts("Server is listening");

    while (1) {
        // Accept a connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            printf("ERROR on accept\n");
            exit(0);
        }

        puts("Connection accepted");

        // Receive data from client
        ret = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (ret < 0) {
            printf("ERROR reading from socket\n");
            exit(0);
        }

        buffer[ret] = '\0';
        printf("Received message: %s\n", buffer);

        // Send response to client
        ret = send(newsockfd, "Message received", strlen("Message received"), 0);
        if (ret < 0) {
            printf("ERROR writing to socket\n");
            exit(0);
        }

        puts("Response sent");

        // Close connection
        close(newsockfd);
    }

    return 0;
}