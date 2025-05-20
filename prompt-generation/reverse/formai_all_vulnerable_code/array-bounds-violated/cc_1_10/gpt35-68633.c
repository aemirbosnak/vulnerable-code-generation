//FormAI DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

bool authenticate(int sockfd) {
    char username[100], password[100], buffer[1024];
    memset(buffer, 0, sizeof buffer);

    // Prompt the user for the username
    write(sockfd, "Enter username: ", sizeof "Enter username: ");
    read(sockfd, username, sizeof username);
    username[strcspn(username, "\n")] = 0;

    // Prompt the user for the password
    write(sockfd, "Enter password: ", sizeof "Enter password: ");
    read(sockfd, password, sizeof password);
    password[strcspn(password, "\n")] = 0;

    // Send the message to the server
    sprintf(buffer, "authenticate %s %s", username, password);
    write(sockfd, buffer, strlen(buffer));

    // Wait for the response from the server
    read(sockfd, buffer, sizeof buffer);
    if (strcmp(buffer, "success") != 0) {
        write(sockfd, "Authentication failed. Try again.\n", sizeof "Authentication failed. Try again.\n");
        return false;
    }

    write(sockfd, "Authentication successful.\n", sizeof "Authentication successful.\n");
    return true;
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof servaddr);

    // Assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof servaddr)) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }

    while(1) {
        socklen_t len = sizeof(cli);

        // Accept the data packet from client and verification
        connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
        if (connfd < 0) {
            printf("server acccept failed...\n");
            exit(0);
        }

        if (!authenticate(connfd)) {
            close(connfd);
            continue;
        }

        char buffer[1024];
        while (1) {
            memset(buffer, 0, sizeof buffer);

            // Read the message from client and copy it to buffer
            read(connfd, buffer, sizeof buffer);

            // Print the message received from client
            printf("Client: %s\n", buffer);

            // If the received message is "exit" then break
            if (strcmp(buffer, "exit") == 0) {
                break;
            }

            // Send the message to the client
            char response[1024];
            sprintf(response, "Server: %s", buffer);
            write(connfd, response, strlen(response));
        }

        // After chatting close the socket
        close(connfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}