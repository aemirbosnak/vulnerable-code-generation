//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

typedef struct {
    char server[256];
    char username[256];
    char password[256];
} POP3Config;

void greet_pop3_server(int sockfd) {
    char buffer[BUFFER_SIZE];

    // Read greeting from the server
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0); // POP3 expects commands terminated by CRLF
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);

        // Look for the end of the response
        if (buffer[0] == '.') {
            break;
        }
    }
}

void authenticate_pop3_server(int sockfd, POP3Config config) {
    char command[BUFFER_SIZE];

    sprintf(command, "USER %s", config.username);
    send_command(sockfd, command);
    receive_response(sockfd);

    sprintf(command, "PASS %s", config.password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_messages(int sockfd) {
    send_command(sockfd, "LIST");
    receive_response(sockfd);
}

void retrieve_message(int sockfd, int message_number) {
    char command[BUFFER_SIZE];

    sprintf(command, "RETR %d", message_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void quit_pop3_server(int sockfd) {
    send_command(sockfd, "QUIT");
    receive_response(sockfd);
}

int main() {
    POP3Config config;
    struct sockaddr_in server_addr;
    int sockfd;

    // Configuration for POP3 connection
    strcpy(config.server, "pop.yourserver.com");
    strcpy(config.username, "yourusername");
    strcpy(config.password, "yourpassword");

    // Creating socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Configuring server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, config.server, &server_addr.sin_addr);
    
    // Connecting to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    greet_pop3_server(sockfd);
    authenticate_pop3_server(sockfd, config);
    list_messages(sockfd);
    
    // Retrieving the first message as example
    retrieve_message(sockfd, 1);
    
    // Quit the session
    quit_pop3_server(sockfd);

    // Clean up and close socket
    close(sockfd);
    return EXIT_SUCCESS;
}