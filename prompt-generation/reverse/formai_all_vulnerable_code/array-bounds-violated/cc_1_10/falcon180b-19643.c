//Falcon-180B DATASET v1.0 Category: Networking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    int n;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    // set up server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("No such host: %s\n", "localhost");
        exit(1);
    }
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    // send data to server
    send(sockfd, "Hello, world!", 13, 0);

    // receive data from server
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Data receive failed: %s\n", strerror(errno));
        exit(1);
    }
    buffer[n] = '\0';
    printf("Received data: %s\n", buffer);

    // close socket
    close(sockfd);
    exit(0);
}