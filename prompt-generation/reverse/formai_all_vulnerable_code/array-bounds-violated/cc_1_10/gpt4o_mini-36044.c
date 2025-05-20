//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
}

char* receive_response(int sockfd) {
    static char response[BUFFER_SIZE];
    int bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }
    response[bytes_received] = '\0';
    return response;
}

void list_emails(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    printf("%s", receive_response(sockfd));
}

void retrieve_email(int sockfd, int email_number) {
    char command[BUFFER_SIZE];
    sprintf(command, "RETR %d\r\n", email_number);
    send_command(sockfd, command);
    printf("%s", receive_response(sockfd));
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server = "your.pop3.server"; // Replace with your POP3 server
    char username[50], password[50];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110); // Port for POP3
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    printf("Connected to POP3 server. Response: %s\n", receive_response(sockfd));

    // User login
    printf("Enter your email username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    char command[BUFFER_SIZE];
    sprintf(command, "USER %s\r\n", username);
    send_command(sockfd, command);
    printf("%s", receive_response(sockfd));

    sprintf(command, "PASS %s\r\n", password);
    send_command(sockfd, command);
    printf("%s", receive_response(sockfd));

    list_emails(sockfd);
    
    int email_number;
    printf("Enter email number to read: ");
    scanf("%d", &email_number);

    retrieve_email(sockfd, email_number);

    // Logout
    send_command(sockfd, "QUIT\r\n");
    printf("%s", receive_response(sockfd));

    close(sockfd);
    return 0;
}