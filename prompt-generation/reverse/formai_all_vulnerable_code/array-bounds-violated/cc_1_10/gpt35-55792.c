//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int client_sockfd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: ./ftp_client <IP address> <port number>\n");
        return -1;
    }

    // Create a socket
    if ((client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Configure server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(client_sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return -1;
    }

    // Receive welcome message
    bzero(buffer, BUFFER_SIZE);
    if (recv(client_sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving welcome message from server");
        return -1;
    }

    printf("%s", buffer);

    while (1) {
        printf("ftp> ");
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer)-1] = '\0';

        // Send user command to server
        if (send(client_sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending command to server");
            return -1;
        }

        // Receive response from server
        bzero(buffer, BUFFER_SIZE);
        if (recv(client_sockfd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error receiving message from server");
            return -1;
        }

        printf("%s", buffer);

        if (strncmp(buffer, "221", 3) == 0) {
            break;
        }
    }

    // Close the socket
    close(client_sockfd);

    return 0;
}