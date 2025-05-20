//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 143
#define BUFFER_SIZE 1024

// Function to create a TCP socket
int create_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to connect to IMAP server
void connect_to_server(int sockfd, const char *server_ip) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
}

// Function to send command to the IMAP server
void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

// Function to receive response from the server
void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE] = {0};
    ssize_t valread = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (valread < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    buffer[valread] = '\0';
    printf("Response from server: %s\n", buffer);
}

// Function to login to the IMAP server
void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

// Function to list mailboxes
void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"\r\n");
    receive_response(sockfd);
}

// Function to select a mailbox
void select_mailbox(int sockfd, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 SELECT \"%s\"\r\n", mailbox);
    send_command(sockfd, command);
    receive_response(sockfd);
}

// Function to fetch messages from a mailbox
void fetch_messages(int sockfd, int message_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A004 FETCH %d BODY[]\r\n", message_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

// Function to logout from the IMAP server
void logout(int sockfd) {
    send_command(sockfd, "A005 LOGOUT\r\n");
    receive_response(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket();
    connect_to_server(sockfd, server_ip);

    receive_response(sockfd); // Initial greeting from the server
    login(sockfd, username, password);
    list_mailboxes(sockfd);

    const char *mailbox = "INBOX"; // Select the INBOX
    select_mailbox(sockfd, mailbox);
    fetch_messages(sockfd, 1); // Fetch the first message

    logout(sockfd);
    
    close(sockfd);
    return EXIT_SUCCESS;
}