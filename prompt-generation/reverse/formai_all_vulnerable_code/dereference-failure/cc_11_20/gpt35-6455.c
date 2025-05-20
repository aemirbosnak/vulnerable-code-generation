//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", argv[1], portno);

    // Login to server
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    write(sockfd, username, strlen(username));
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);
    write(sockfd, password, strlen(password));

    // Wait for welcome message from server
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Main loop for handling commands
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send command to server
        write(sockfd, buffer, strlen(buffer));

        char cmd[BUFFER_SIZE], arg[BUFFER_SIZE];
        sscanf(buffer, "%s %s", cmd, arg);

        // Handle commands
        if (strcmp(cmd, "ls") == 0) {
            // List directory contents
            while (1) {
                memset(buffer, 0, BUFFER_SIZE);
                n = read(sockfd, buffer, BUFFER_SIZE-1);
                if (n < 0) {
                    perror("ERROR reading from socket");
                    exit(EXIT_FAILURE);
                }
                if (n == 0) {
                    break;
                }
                printf("%s", buffer);
            }
        }
        else if (strcmp(cmd, "put") == 0) {
            // Send file from client to server
            FILE *file = fopen(arg, "rb");
            if (file == NULL) {
                printf("ERROR: Could not open file\n");
                continue;
            }
            int count = 0;
            while ((count = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
                write(sockfd, buffer, count);
            }
            fclose(file);
        }
        else if (strcmp(cmd, "get") == 0) {
            // Receive file from server to client
            FILE *file = fopen(arg, "wb");
            if (file == NULL) {
                printf("ERROR: Could not create file\n");
                continue;
            }
            int count = 0;
            while ((count = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
                fwrite(buffer, 1, count, file);
            }
            fclose(file);
        }
        else if (strcmp(cmd, "exit") == 0) {
            // Exit program
            break;
        }
        else {
            // Invalid command
            printf("Invalid command\n");
        }
    }

    // Close socket
    close(sockfd);
    return 0;
}