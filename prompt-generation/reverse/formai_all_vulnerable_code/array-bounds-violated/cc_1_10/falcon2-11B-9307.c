//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    // Initialize server address structure
    memset((char *) &serv_addr, '\0', sizeof(serv_addr));
    portno = 5000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept connection from client
    int client_fd = accept(sockfd, (struct sockaddr *) NULL, NULL);
    if (client_fd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Receive message from client
    char msg[1024];
    int len = recv(client_fd, msg, sizeof(msg) - 1, 0);
    if (len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    msg[len] = '\0'; // null terminate string

    // Send message back to client
    send(client_fd, msg, strlen(msg), 0);

    // Close connections
    close(client_fd);
    close(sockfd);

    return 0;
}