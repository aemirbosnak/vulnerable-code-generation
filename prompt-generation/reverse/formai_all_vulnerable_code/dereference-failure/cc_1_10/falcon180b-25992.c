//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char command[MAX_COMMAND_LENGTH];

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_address> <port_number> <command>\n");
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host\n");
        return 1;
    }
    bcopy(server->h_addr, &serv_addr.sin_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send command
    strcpy(command, argv[3]);
    send(sockfd, command, strlen(command), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        printf("Error receiving response\n");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}