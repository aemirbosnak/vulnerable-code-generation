//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    // Initialize variables
    int sockfd, port;
    struct sockaddr_in servaddr;
    char buffer[1024], username[100], password[100], cmd[100], filename[100];

    // Get the FTP server IP address
    printf("Enter the FTP server IP address: ");
    scanf("%s", buffer);

    // Get the FTP server port
    printf("Enter the FTP server port: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(buffer);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive the welcome message
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the username
    printf("Enter your username: ");
    scanf("%s", username);
    send(sockfd, username, strlen(username), 0);

    // Receive the password prompt
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send the password
    printf("Enter your password: ");
    scanf("%s", password);
    send(sockfd, password, strlen(password), 0);

    // Receive the successful login message
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Enter the FTP command loop
    while (1) {
        // Get the command
        printf("Enter an FTP command (list, get, put, quit): ");
        scanf("%s", cmd);

        // Send the command to the server
        send(sockfd, cmd, strlen(cmd), 0);

        // Receive the command response
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("%s", buffer);

        // Handle the command
        if (strcmp(cmd, "list") == 0) {
            // List the files on the server
            recv(sockfd, buffer, sizeof(buffer), 0);
            printf("%s", buffer);
        } else if (strcmp(cmd, "get") == 0) {
            // Get a file from the server
            printf("Enter the name of the file to get: ");
            scanf("%s", filename);
            send(sockfd, filename, strlen(filename), 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            printf("%s", buffer);
            if (strcmp(buffer, "File not found") == 0) {
                continue;
            }
            FILE *fp = fopen(filename, "wb");
            while (1) {
                recv(sockfd, buffer, sizeof(buffer), 0);
                if (strcmp(buffer, "EOF") == 0) {
                    break;
                }
                fwrite(buffer, 1, sizeof(buffer), fp);
            }
            fclose(fp);
        } else if (strcmp(cmd, "put") == 0) {
            // Put a file on the server
            printf("Enter the name of the file to put: ");
            scanf("%s", filename);
            send(sockfd, filename, strlen(filename), 0);
            FILE *fp = fopen(filename, "rb");
            while (1) {
                fread(buffer, 1, sizeof(buffer), fp);
                if (feof(fp)) {
                    break;
                }
                send(sockfd, buffer, sizeof(buffer), 0);
            }
            fclose(fp);
            send(sockfd, "EOF", 3, 0);
        } else if (strcmp(cmd, "quit") == 0) {
            // Quit the FTP session
            send(sockfd, "quit", 4, 0);
            break;
        } else {
            // Invalid command
            printf("Invalid command. Please try again.\n");
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}