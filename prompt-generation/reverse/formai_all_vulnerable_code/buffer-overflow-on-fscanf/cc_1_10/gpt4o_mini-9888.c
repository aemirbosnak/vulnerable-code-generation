//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAXLINE 1024
#define MAX_EMAILS 100
#define IMAP_PORT 143

typedef struct {
    char username[100];
    char password[100];
    char server[100];
} Config;

typedef struct {
    char subject[256];
    char from[256];
    char date[256];
} Email;

Config load_config() {
    Config config;
    FILE *file = fopen("config.txt", "r");
    if (!file) {
        perror("Could not open config.txt");
        exit(EXIT_FAILURE);
    }
    
    fscanf(file, "%s %s %s", config.server, config.username, config.password);
    fclose(file);
    return config;
}

void error_handling(int ret, const char *msg) {
    if (ret < 0) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    write(sockfd, "\r\n", 2);
}

void receive_response(int sockfd, char *buffer) {
    read(sockfd, buffer, MAXLINE);
    printf("Response: %s\n", buffer);
}

int main() {
    // Load the configuration from a file
    Config config = load_config();

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    error_handling(sockfd, "Socket creation failed");

    // Connect to the IMAP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(config.server);

    error_handling(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)), "Connection to server failed");

    char buffer[MAXLINE];
    receive_response(sockfd, buffer);

    // Login to the IMAP server
    char login_command[MAXLINE];
    snprintf(login_command, sizeof(login_command), "A001 LOGIN %s %s", config.username, config.password);
    send_command(sockfd, login_command);
    receive_response(sockfd, buffer);

    // Select the INBOX
    send_command(sockfd, "A002 SELECT INBOX");
    receive_response(sockfd, buffer);

    // Fetch email count
    send_command(sockfd, "A003 SEARCH ALL");
    receive_response(sockfd, buffer);

    // Parse email IDs
    const char *delimiter = " ";
    char *token = strtok(buffer, delimiter);
    int email_ids[MAX_EMAILS];
    int count = 0;

    while (token != NULL && count < MAX_EMAILS) {
        email_ids[count++] = atoi(token);
        token = strtok(NULL, delimiter);
    }

    // Fetch each email's subject and from
    for (int i = 0; i < count; i++) {
        char fetch_command[MAXLINE];
        snprintf(fetch_command, sizeof(fetch_command), "A004 FETCH %d BODY[HEADER.FIELDS (FROM SUBJECT DATE)]", email_ids[i]);
        send_command(sockfd, fetch_command);
        receive_response(sockfd, buffer);
        printf("Fetched Email %d:\n%s\n", email_ids[i], buffer);
    }

    // Logout from the IMAP server
    send_command(sockfd, "A005 LOGOUT");
    receive_response(sockfd, buffer);

    // Close the socket and exit
    close(sockfd);
    return 0;
}