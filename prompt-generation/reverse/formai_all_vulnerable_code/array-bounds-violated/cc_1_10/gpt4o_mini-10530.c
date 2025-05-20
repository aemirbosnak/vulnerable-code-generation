//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_pop3(const char *hostname) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket.");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0)
        error("Invalid address or address not supported");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Connection to server failed");

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) 
        error("Error receiving response.");
    
    buffer[n] = '\0';
    printf("%s", buffer);
}

void pop3_authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_emails(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void retrieve_email(int sockfd, int email_number) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RETR %d\r\n", email_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void disconnect_pop3(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
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

    int sockfd = connect_to_pop3(hostname);
    receive_response(sockfd);  // Get the server's greeting

    pop3_authenticate(sockfd, username, password);
    
    list_emails(sockfd);
    
    int email_number;
    printf("Enter email number to retrieve: ");
    scanf("%d", &email_number);
    retrieve_email(sockfd, email_number);

    disconnect_pop3(sockfd);

    return 0;
}