//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/time.h>
#include <time.h>

// Function to send a command to the IMAP server
void send_command(int socket, char *command) {
    int len = strlen(command);
    send(socket, command, len, 0);
}

// Function to receive the response from the IMAP server
int receive_response(int socket) {
    char buffer[256];
    int nbytes = 0;
    while (1) {
        nbytes = recv(socket, buffer, sizeof(buffer), 0);
        if (nbytes < 0) {
            printf("Error receiving data from the server\n");
            return -1;
        } else if (nbytes == 0) {
            break;
        }
        printf("%s", buffer);
    }
    return 0;
}

// Function to initialize the connection to the IMAP server
int connect_to_server(char *hostname, int port) {
    struct hostent *server;
    struct sockaddr_in serv_addr;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }
    return socketfd;
}

// Main function
int main() {
    char hostname[256];
    char command[256];

    printf("Enter the hostname of the IMAP server: ");
    scanf("%s", hostname);

    int port = 143; // Default IMAP port
    printf("Enter the port number of the IMAP server: ");
    scanf("%d", &port);

    int socketfd = connect_to_server(hostname, port);
    if (socketfd < 0) {
        return -1;
    }

    printf("Enter the command you want to send to the server: ");
    scanf("%s", command);

    send_command(socketfd, command);

    receive_response(socketfd);

    return 0;
}