//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21 // FTP port
#define BUFFERSIZE 1024 // buffer size for data transfer
#define MAX_COMMAND_LENGTH 1024 // maximum command length

void error_handling(char *message); // function for error handling

int main(int argc, char *argv[]) {

    // check if the number of arguments is correct
    if (argc!= 4) {
        printf("Usage:./ftp_client <IP address> <username> <password>\n");
        return 1;
    }

    // set up the command line arguments
    char *ip_address = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // initialize the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("Error creating socket");
    }

    // connect to the FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("Error connecting to server");
    }

    // send the username and password
    char *command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);
    free(command);

    command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);
    free(command);

    // receive the welcome message
    char buffer[BUFFERSIZE];
    memset(buffer, 0, BUFFERSIZE);
    int bytes_received = recv(sockfd, buffer, BUFFERSIZE, 0);
    if (bytes_received <= 0) {
        error_handling("Error receiving welcome message");
    }

    // display the welcome message
    printf("Welcome message: %s\n", buffer);

    // close the socket
    close(sockfd);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}