//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char *username, *password;
    char *host = "localhost";
    int port = 110;
    int opt = 1;

    // Set the socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect to the POP3 server\n");
        exit(1);
    }

    // Send the USER command
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server Response: %s", buffer);

    // Send the PASS command
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the server response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server Response: %s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}