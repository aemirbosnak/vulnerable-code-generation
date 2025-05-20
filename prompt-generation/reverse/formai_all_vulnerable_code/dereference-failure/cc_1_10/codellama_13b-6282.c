//Code Llama-13B DATASET v1.0 Category: Networking ; Style: invasive
// Networking Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main() {
    int sockfd, n;
    char buffer[256];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // set up connection information
    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("Error resolving host");
        exit(1);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // send message to server
    n = write(sockfd, "Hello, server!\n", 14);
    if (n < 0) {
        perror("Error writing to server");
        exit(1);
    }

    // receive message from server
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    buffer[n] = '\0';

    // print received message
    printf("Received message: %s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}