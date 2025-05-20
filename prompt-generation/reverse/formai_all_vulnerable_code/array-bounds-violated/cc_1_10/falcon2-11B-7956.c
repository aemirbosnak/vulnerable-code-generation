//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 12345
#define MAXLINE 256
#define MAX_MESSAGE 1024
#define MAX_NAME 256

void sendMessage(int sockfd, char *msg) {
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send():");
        exit(1);
    }
}

char *getMessage(int sockfd) {
    char buffer[MAXLINE];
    int bytes_read;

    if ((bytes_read = recv(sockfd, buffer, MAXLINE - 1, 0)) < 0) {
        perror("recv():");
        exit(1);
    }
    buffer[bytes_read] = '\0';
    return buffer;
}

int main() {
    int sockfd, portno, new_socket;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAXLINE], msg[MAX_MESSAGE], name[MAX_NAME];

    // Creating a socket
    if ((new_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket():");
        exit(1);
    }

    // Getting the server name and port number
    if (gethostname(name, MAX_NAME) < 0) {
        perror("gethostname():");
        exit(1);
    }
    portno = PORT;

    // Setting up server address
    server = gethostbyname(name);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }
    memcpy((char *)&server_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);

    // Connecting to the server
    if (connect(new_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect():");
        exit(1);
    }

    // Receiving message from the server
    printf("Enter your name: ");
    fgets(msg, MAX_MESSAGE, stdin);
    strcpy(name, msg);
    printf("Enter your message: ");
    fgets(msg, MAX_MESSAGE, stdin);

    // Sending message to the server
    sendMessage(new_socket, msg);

    // Getting the message from the server
    char *response = getMessage(new_socket);
    printf("Server's response: %s\n", response);

    close(new_socket);
    return 0;
}