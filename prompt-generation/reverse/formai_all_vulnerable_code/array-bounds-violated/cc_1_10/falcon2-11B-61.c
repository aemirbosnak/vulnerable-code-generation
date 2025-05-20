//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char message[256];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address struct
    memset((char *) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    while (1) {
        // Accept incoming connection
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Receive data from client
        bzero(buffer, 256);
        n = recv(sockfd, buffer, 255, 0);
        if (n < 0) {
            perror("ERROR receiving data");
            exit(1);
        }
        buffer[n] = '\0';

        // Process data
        printf("Received: %s\n", buffer);

        // Send reply to client
        sprintf(message, "Thank you for your email!");
        send(sockfd, message, strlen(message), 0);

        // Close socket
        close(sockfd);
    }
}