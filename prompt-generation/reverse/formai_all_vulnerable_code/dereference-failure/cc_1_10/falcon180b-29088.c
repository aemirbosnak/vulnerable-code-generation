//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 1024
#define PORT "80"
#define SA struct sockaddr

int main(int argc, char* argv[]) {

    int sockfd, newsockfd, addrlen, valread, sd;
    char buffer[MAX];
    struct hostent *server;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    printf("Socket created\n");

    // Connect to server
    server = gethostbyname("www.google.com");

    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(PORT));

    // Connect to server
    if (connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Receive data from server
    while ((valread = read(sockfd, buffer, MAX)) > 0) {
        buffer[valread] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}