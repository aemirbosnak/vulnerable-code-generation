//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void connect_to_pop3_server(const char *server_address, int *sockfd) {
    struct sockaddr_in server_addr;
    
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        handle_error("Error creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Error connecting to server");
    }

    char buffer[BUFFER_SIZE];
    recv(*sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Response: %s", buffer);
        if (strstr(buffer, "+OK") || strstr(buffer, "-ERR")) {
            break; // Exit loop on response completion
        }
    }
}

void list_messages(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void retrieve_message(int sockfd, const char *msg_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", msg_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void delete_message(int sockfd, const char *msg_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "DELE %s\r\n", msg_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void quit_pop3(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <POP3 Server Address> <Username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *pop3_server = argv[1];
    const char *username = argv[2];
    int sockfd;

    connect_to_pop3_server(pop3_server, &sockfd);

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    printf("Enter your password: ");
    char password[BUFFER_SIZE];
    scanf("%s", password); // Note: Insecure way to read password, for demonstration only.
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);

    list_messages(sockfd);

    // Example usage; should be replaced with logic to handle user input
    char msg_number[BUFFER_SIZE];
    printf("Enter message number to fetch: ");
    scanf("%s", msg_number);
    retrieve_message(sockfd, msg_number);

    printf("Enter message number to delete: ");
    scanf("%s", msg_number);
    delete_message(sockfd, msg_number);

    quit_pop3(sockfd);
    return 0;
}