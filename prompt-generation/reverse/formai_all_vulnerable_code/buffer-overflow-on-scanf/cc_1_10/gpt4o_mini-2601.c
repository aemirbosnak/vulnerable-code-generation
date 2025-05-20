//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void retrieve_email(int socket) {
    char buffer[MAX_BUFFER];
    char command[MAX_BUFFER];

    // Sending "LIST" command to fetch email list
    snprintf(command, sizeof(command), "LIST\r\n");
    send(socket, command, strlen(command), 0);
    recv(socket, buffer, sizeof(buffer) - 1, 0);
    printf("Server response to LIST: \n%s\n", buffer);

    // Extracting email numbers
    int email_count;
    sscanf(buffer, "+OK %d", &email_count);
    printf("Total emails: %d\n", email_count);

    // Retrieve each email
    for (int i = 1; i <= email_count; i++) {
        snprintf(command, sizeof(command), "RETR %d\r\n", i);
        send(socket, command, strlen(command), 0);
        recv(socket, buffer, sizeof(buffer) - 1, 0);
        printf("Server response to RETR %d: \n%s\n", i, buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    struct sockaddr_in server_addr;
    int sock;
    struct hostent *host;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("Failed to create socket");
    }

    // Resolve hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        die("Failed to get host by name");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(atoi(port));

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Failed to connect to server");
    }

    // Receive initial greeting
    char buffer[MAX_BUFFER];
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Server greeting: %s\n", buffer);

    // Send user credentials
    char username[MAX_BUFFER], password[MAX_BUFFER];
    printf("Enter your username: ");
    scanf("%s", username);
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Response after USER command: %s\n", buffer);

    printf("Enter your password: ");
    scanf("%s", password);
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Response after PASS command: %s\n", buffer);

    // If login successful, retrieve emails
    if (strncmp(buffer, "+OK", 3) == 0) {
        retrieve_email(sock);
    } else {
        printf("Login failed.\n");
    }

    // Send "QUIT" command to finish session
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Response after QUIT command: %s\n", buffer);

    // Close socket
    close(sock);
    return 0;
}