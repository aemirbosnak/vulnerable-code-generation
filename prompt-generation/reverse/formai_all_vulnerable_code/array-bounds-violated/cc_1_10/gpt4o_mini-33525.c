//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 993
#define BUFFER_SIZE 1024

void log_message(const char *message) {
    printf("* * * * *\nLOG: %s\n* * * * *\n", message);
}

int create_socket(const char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd;

    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        log_message("Could not resolve hostname.");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        log_message("Error creating socket.");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        log_message("Connection failed.");
        close(sockfd);
        return -1;
    }

    log_message("Connection established.");
    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    log_message(command);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';  // Null-terminate the string
        printf("Response: %s\n", buffer);
    }

    log_message("Finished reading response.");
}

void authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(sockfd, command);
    read_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"\r\n");
    read_response(sockfd);
}

void fetch_email(int sockfd, int email_id) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A003 FETCH %d BODY[]\r\n", email_id);
    send_command(sockfd, command);
    read_response(sockfd);
}

int main() {
    const char *hostname = "imap.example.com";  // IMAP server
    const char *username = "your_email@example.com";  // Your email
    const char *password = "your_password";  // Your password
    int sockfd;

    log_message("Sherlock Holmes IMAP Client is starting...");

    sockfd = create_socket(hostname);
    if (sockfd < 0) {
        exit(EXIT_FAILURE);
    }

    authenticate(sockfd, username, password);
    list_mailboxes(sockfd);
    fetch_email(sockfd, 1); // Fetch the first email, as an example

    close(sockfd);
    log_message("Closing the connection and ending the client.");
    return 0;
}