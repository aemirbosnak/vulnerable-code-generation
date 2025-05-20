//Falcon-180B DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int addrlen, bytes_read;

    portno = atoi(argv[1]); // get port number from command line argument

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket creation failed");
    }

    puts("socket created");

    // set up server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // bind server address to socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("bind failed");
    }

    puts("socket bound");

    // listen for incoming connections
    listen(sockfd, 5);

    puts("socket listening");

    // accept incoming connection
    addrlen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);

    if (newsockfd < 0) {
        error_handling("accept failed");
    }

    puts("connection accepted");

    // receive data from client
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = recv(newsockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_read <= 0) {
            break;
        }

        printf("Received message: %s\n", buffer);

        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "Message received, sending response...");

        send(newsockfd, buffer, strlen(buffer), 0);
    }

    // close sockets
    close(sockfd);
    close(newsockfd);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}