//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/select.h>

#define MAXLINE 1024
#define PORT 143

int main(int argc, char *argv[]) {
    int socket_fd, ch, status;
    struct sockaddr_in server_addr;
    struct hostent *server;
    struct sockaddr_in from_addr;
    int fromlen = sizeof(from_addr);
    char recvline[MAXLINE], command[MAXLINE], sendline[MAXLINE];
    char *newline = "\r\n";

    // Step 1: Initialize socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        fprintf(stderr, "ERROR: Failed to create socket\n");
        exit(1);
    }

    // Step 2: Set up server address
    server = gethostbyname("imap.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR: Failed to get address for imap.example.com\n");
        exit(1);
    }
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    // Step 3: Connect to server
    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "ERROR: Failed to connect to server\n");
        exit(1);
    }

    // Step 4: Authentication
    printf("Username: ");
    fgets(command, MAXLINE, stdin);
    sendline[0] = 'a';
    sendline[1] = '\0';
    if (send(socket_fd, sendline, strlen(sendline), 0) == -1) {
        fprintf(stderr, "ERROR: Failed to send authentication command\n");
        exit(1);
    }
    fgets(recvline, MAXLINE, stdin);

    // Step 5: Start the IMAP session
    printf("Enter 'l' to list folders or 'e' to exit: ");
    fgets(command, MAXLINE, stdin);
    if (strcmp(command, "l") == 0) {
        // Step 6: List folders
        sendline[0] = 'l';
        sendline[1] = '\0';
        if (send(socket_fd, sendline, strlen(sendline), 0) == -1) {
            fprintf(stderr, "ERROR: Failed to send list command\n");
            exit(1);
        }
        while (1) {
            if (recv(socket_fd, recvline, MAXLINE, 0) == -1) {
                fprintf(stderr, "ERROR: Failed to receive data\n");
                exit(1);
            }
            if (strcmp(recvline, "a") == 0) {
                printf("Folder: %s\n", recvline);
                sendline[0] = 'l';
                sendline[1] = '\0';
                if (send(socket_fd, sendline, strlen(sendline), 0) == -1) {
                    fprintf(stderr, "ERROR: Failed to send list command\n");
                    exit(1);
                }
            } else if (strcmp(recvline, "d") == 0) {
                break;
            } else {
                printf("ERROR: Invalid response\n");
                exit(1);
            }
        }
    } else if (strcmp(command, "e") == 0) {
        // Step 7: Exit the IMAP session
        sendline[0] = 'e';
        sendline[1] = '\0';
        if (send(socket_fd, sendline, strlen(sendline), 0) == -1) {
            fprintf(stderr, "ERROR: Failed to send exit command\n");
            exit(1);
        }
        close(socket_fd);
        return 0;
    } else {
        printf("ERROR: Invalid command\n");
        exit(1);
    }
}