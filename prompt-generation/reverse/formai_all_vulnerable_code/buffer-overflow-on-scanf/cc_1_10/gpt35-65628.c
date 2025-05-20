//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>

#define MAX_MSG_LENGTH 1024
#define MAX_CMD_LENGTH 128
#define MAX_ARG_LENGTH 256

bool process_command(int socket_fd, char* command, char* argument) {
    // Send command and wait for confirmation
    char msg[MAX_MSG_LENGTH];
    memset(msg, 0, MAX_MSG_LENGTH);
    sprintf(msg, "%s %s\n", command, argument);
    if(send(socket_fd, msg, strlen(msg), 0) == -1) {
        perror("Error sending command");
        return false;
    }

    // Wait for response
    memset(msg, 0, MAX_MSG_LENGTH);
    if(recv(socket_fd, msg, MAX_MSG_LENGTH, 0) == -1) {
        perror("Error receiving response");
        return false;
    }

    // Process response
    printf("%s", msg);
    if(strncmp(msg, "2", 1) == 0) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if(argc != 3) {
        fprintf(stderr, "Usage: ftpclient hostname port\n");
        exit(EXIT_FAILURE);
    }
    char *hostname = argv[1];
    unsigned short port = atoi(argv[2]);

    // Resolve hostname to IP address
    struct hostent *addr_info = gethostbyname(hostname);
    if(!addr_info) {
        fprintf(stderr, "Error resolving hostname\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)addr_info->h_addr);
    if(connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Log in
    char username[MAX_ARG_LENGTH], password[MAX_ARG_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if(!process_command(socket_fd, "USER", username)) {
        perror("Error logging in");
        exit(EXIT_FAILURE);
    }
    if(!process_command(socket_fd, "PASS", password)) {
        perror("Error logging in");
        exit(EXIT_FAILURE);
    }

    // Loop to process commands
    char cmd[MAX_CMD_LENGTH], argument[MAX_ARG_LENGTH];
    while(true) {
        printf("ftp> ");
        scanf("%s", cmd);
        if(strlen(cmd) == 0) {
            continue;
        }
        scanf("%[^\n]", argument);

        if(strcmp(cmd, "quit") == 0) {
            process_command(socket_fd, "QUIT", "");
            break;
        } else if(strcmp(cmd, "get") == 0) {
            process_command(socket_fd, "TYPE", "I");
            process_command(socket_fd, "PASV", "");
            process_command(socket_fd, "RETR", argument);
        } else if(strcmp(cmd, "put") == 0) {
            process_command(socket_fd, "TYPE", "I");
            process_command(socket_fd, "PASV", "");
            process_command(socket_fd, "STOR", argument);
        } else if(strcmp(cmd, "ls") == 0) {
            process_command(socket_fd, "PASV", "");
            process_command(socket_fd, "LIST", "");
        } else {
            printf("Invalid command\n");
        }
    }
    close(socket_fd);
    return EXIT_SUCCESS;
}