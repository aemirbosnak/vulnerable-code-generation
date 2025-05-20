//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argv[1] == NULL) {
        printf("Please provide a server hostname as an argument.\n");
        return 0;
    }
    
    // Resolve Server IP
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Could not resolve hostname %s.\n", argv[1]);
        return 0;
    }

    // Create Socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket.\n");
        return 0;
    }

    // Connect to Server
    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to server.\n");
        return 0;
    }

    // Read Server Response
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    if (bytes_received < 0) {
        printf("Error: Could not receive server response.\n");
        return 0;
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s\n", buffer);

    // Send User Credentials
    char username[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    char login_buffer[MAX_BUFFER_SIZE];
    snprintf(login_buffer, MAX_BUFFER_SIZE, "USER %s\r\nPASS %s\r\n", username, password);
    int bytes_sent = send(sockfd, login_buffer, strlen(login_buffer), 0);
    if (bytes_sent < 0) {
        printf("Error: Could not send user credentials.\n");
        return 0;
    }

    // Read OK Response
    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Server Response: %s\n", buffer);

    // List Emails
    int email_count = 0;
    bytes_sent = send(sockfd, "LIST\r\n", 6, 0);
    if (bytes_sent < 0) {
        printf("Error: Could not send LIST command.\n");
        return 0;
    }
    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Server Response: %s\n", buffer);
    char *line = strtok(buffer, "\r\n");
    while ((line = strtok(NULL, "\r\n")) != NULL) {
        printf("%s\n", line);
        email_count++;
    }

    // Read Email
    if (email_count > 0) {
        int email_id;
        printf("Enter email number to read: ");
        scanf("%d", &email_id);
        char read_buffer[MAX_BUFFER_SIZE];
        snprintf(read_buffer, MAX_BUFFER_SIZE, "RETR %d\r\n", email_id);
        bytes_sent = send(sockfd, read_buffer, strlen(read_buffer), 0);
        if (bytes_sent < 0) {
            printf("Error: Could not send RETR command.\n");
            return 0;
        }
        bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
        buffer[bytes_received] = '\0';
        printf("Server Response: %s\n", buffer);
        while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("%s", buffer);
            if (strstr(buffer, "\r\n.\r\n") != NULL) {
                break;
            }
        }
    }

    // Quit
    bytes_sent = send(sockfd, "QUIT\r\n", 6, 0);
    if (bytes_sent < 0) {
        printf("Error: Could not send QUIT command.\n");
    }
    bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[bytes_received] = '\0';
    printf("Server Response: %s\n", buffer);
    close(sockfd);

    return 0;
}