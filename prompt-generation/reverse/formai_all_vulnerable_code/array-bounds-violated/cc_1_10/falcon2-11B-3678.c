//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: active
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("ERROR with inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send a message to the server
    sprintf(buffer, "GET / HTTP/1.1\r\n\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Read the server's response
    n = read(sockfd, buffer, 256);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    buffer[n] = '\0';

    // Print the server's response
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}