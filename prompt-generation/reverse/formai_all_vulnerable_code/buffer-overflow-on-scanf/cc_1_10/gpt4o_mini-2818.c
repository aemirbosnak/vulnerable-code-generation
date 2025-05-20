//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command, char *response) {
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, BUFFER_SIZE, 0);
}

void get_email(int sockfd, int msg_num) {
    char command[50];
    char response[BUFFER_SIZE];

    sprintf(command, "RETR %d\r\n", msg_num);
    send_command(sockfd, command, response);
    printf("Email #%d:\n%s", msg_num, response);
}

void list_emails(int sockfd) {
    char command[] = "LIST\r\n";
    char response[BUFFER_SIZE];

    send_command(sockfd, command, response);
    printf("Listing Emails:\n%s", response);
}

void pop3_authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    sprintf(command, "USER %s\r\n", username);
    send_command(sockfd, command, response);
    printf("%s", response);

    sprintf(command, "PASS %s\r\n", password);
    send_command(sockfd, command, response);
    printf("%s", response);
}

void disconnect(int sockfd) {
    char command[] = "QUIT\r\n";
    char response[BUFFER_SIZE];
    send_command(sockfd, command, response);
    printf("%s", response);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    
    // Resolve the hostname
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or address not supported\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    char response[BUFFER_SIZE];
    recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Server: %s", response);

    // Authenticate user
    pop3_authenticate(sockfd, username, password);

    // List emails
    list_emails(sockfd);

    // Get a specific email
    int email_number;
    printf("Enter email number to retrieve: ");
    scanf("%d", &email_number);
    get_email(sockfd, email_number);

    // Clean up and disconnect
    disconnect(sockfd);
    
    return 0;
}