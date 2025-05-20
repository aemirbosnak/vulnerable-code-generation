//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define MAX_EMAILS 100

// Function declarations
void displayEmailHeaders(char headers[MAX_EMAILS][MAX_BUFFER], int count);
int connectToServer(const char *hostname, int port);
int authenticate(int sock, const char *username, const char *password);
int fetchEmailHeaders(int sock, char headers[MAX_EMAILS][MAX_BUFFER]);

int main() {
    char *hostname = "pop.example.com"; // Replace with your POP3 server
    int port = 110; // Default POP3 port
    char username[50], password[50];
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    int sock = connectToServer(hostname, port);
    if (sock < 0) {
        fprintf(stderr, "Error connecting to server.\n");
        return EXIT_FAILURE;
    }

    if (authenticate(sock, username, password) < 0) {
        close(sock);
        return EXIT_FAILURE;
    }

    char emailHeaders[MAX_EMAILS][MAX_BUFFER];
    int emailCount = fetchEmailHeaders(sock, emailHeaders);
    displayEmailHeaders(emailHeaders, emailCount);

    close(sock);
    return EXIT_SUCCESS;
}

int connectToServer(const char *hostname, int port) {
    int sock;
    struct sockaddr_in serverAddr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serverAddr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        close(sock);
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect() failed");
        close(sock);
        return -1;
    }

    return sock;
}

int authenticate(int sock, const char *username, const char *password) {
    char buffer[MAX_BUFFER];

    // Read server greeting
    recv(sock, buffer, sizeof(buffer)-1, 0);
    printf("Server: %s\n", buffer);

    // USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer)-1, 0);
    printf("Server: %s\n", buffer);

    // PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer)-1, 0);
    printf("Server: %s\n", buffer);

    return 0;
}

int fetchEmailHeaders(int sock, char headers[MAX_EMAILS][MAX_BUFFER]) {
    char buffer[MAX_BUFFER];
    int emailCount = 0;

    // LIST command to get the list of emails
    send(sock, "LIST\r\n", 7, 0);
    while (1) {
        recv(sock, buffer, sizeof(buffer)-1, 0);
        printf("Server: %s\n", buffer);
        if (strstr(buffer, ".") != NULL) {
            break; // End of list
        }
        if (emailCount < MAX_EMAILS) {
            strcpy(headers[emailCount], buffer);
            emailCount++;
        }
    }

    // Terminate the fetching with QUIT command
    send(sock, "QUIT\r\n", 7, 0);
    recv(sock, buffer, sizeof(buffer)-1, 0);
    printf("Server: %s\n", buffer);

    return emailCount;
}

void displayEmailHeaders(char headers[MAX_EMAILS][MAX_BUFFER], int count) {
    printf("\nEmail Headers:\n");
    for (int i = 0; i < count; i++) {
        printf("%s", headers[i]);
    }
}