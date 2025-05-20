//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 65536

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server address> <port number> <email address>\n", argv[0]);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int sock;

    // Create a socket for connecting to the server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Setup the server address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive the server greeting
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send the user information
    sprintf(buffer, "USER %s\r\n", argv[3]);
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send the password information
    char password[255];
    printf("Enter your password: ");
    fgets(password, 255, stdin);
    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sock, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send the command to list the emails
    if (send(sock, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read the response header
    if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the emails and their sizes
    int email_count;
    while (1) {
        if (recv(sock, buffer, BUFFER_SIZE, 0) == -1) {
            perror("recv");
            exit(1);
        }
        if (strcmp(buffer, ".\r\n") == 0) {
            break;
        }
        int email_number, email_size;
        sscanf(buffer, "%d %d\r\n", &email_number, &email_size);
        printf("%d %d\n", email_number, email_size);
        email_count++;
    }

    // Send the quit command to the server
    if (send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close the connection
    close(sock);

    printf("Total Emails: %d\n", email_count);

    return 0;
}