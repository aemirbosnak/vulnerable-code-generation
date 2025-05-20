//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

struct Email {
    int number;
    char subject[100];
};

struct Email emails[MAX_EMAILS];
int email_count = 0;

void parse_response(char *response, int email_num) {
    char *header = strtok(response, "\r\n");
    char *line;

    while (header != NULL) {
        if (strstr(header, "Subject:") != NULL) {
            sscanf(header, "Subject: %99[^\n]", emails[email_num].subject);
            emails[email_num].number = email_num + 1;
        }
        header = strtok(NULL, "\r\n");
    }
}

void fetch_email_list(int sockfd) {
    char buffer[BUFFER_SIZE], fetch_cmd[50];
    
    // Send the LIST command
    strcpy(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Error sending LIST command");
    }
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    
    char *line = strtok(buffer, "\r\n");
    while (line != NULL) {
        if (atoi(line) > 0) {
            sprintf(fetch_cmd, "FETCH %s\r\n", line);
            if (send(sockfd, fetch_cmd, strlen(fetch_cmd), 0) < 0) {
                error("Error sending FETCH command");
            }
            int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
            if (bytes_received < 0) {
                error("Error receiving email data");
            }
            buffer[bytes_received] = '\0';
            parse_response(buffer, email_count);
            email_count++;
        }
        line = strtok(NULL, "\r\n");
    }
}

void print_email_list() {
    printf("Email List:\n");
    for (int i = 0; i < email_count; i++) {
        printf("Email #%d: %s\n", emails[i].number, emails[i].subject);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *hostname = argv[1];
    const char *username = argv[2];
    char password[100];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Setup server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Receive server greeting
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    // Authentication
    printf("Enter password: ");
    scanf("%s", password);

    char auth_cmd[150];
    sprintf(auth_cmd, "USER %s\r\n", username);
    send(sockfd, auth_cmd, strlen(auth_cmd), 0);

    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Auth Response: %s", buffer);

    sprintf(auth_cmd, "PASS %s\r\n", password);
    send(sockfd, auth_cmd, strlen(auth_cmd), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Login Response: %s", buffer);

    // Fetch email list
    fetch_email_list(sockfd);
    print_email_list();

    // Close connection
    send(sockfd, "QUIT\r\n", 6, 0);
    close(sockfd);

    return 0;
}