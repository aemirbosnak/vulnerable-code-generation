//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define HOST "pop.mailserver.com" // Replace with the actual POP3 server
#define PORT 110

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void calculate_statistics(int message_count, int total_size) {
    if (message_count == 0) {
        printf("No messages retrieved.\n");
        return;
    }

    double average_size = (double)total_size / message_count;
    printf("Total Messages: %d\n", message_count);
    printf("Average Message Size: %.2f bytes\n", average_size);
}

int connect_to_server(const char *host, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Unable to create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to the server failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd, char *buffer, int buffer_size) {
    recv(sockfd, buffer, buffer_size - 1, 0);
    buffer[buffer_size - 1] = '\0'; // Ensure null termination
}

int main() {
    int sockfd = connect_to_server(HOST, PORT);
    char buffer[MAX_BUFFER];
    
    // Read the server greeting
    receive_response(sockfd, buffer, MAX_BUFFER);
    printf("Server: %s\n", buffer);

    // Authenticate (USER and PASS commands)
    send_command(sockfd, "USER your_username"); // Replace with your username
    receive_response(sockfd, buffer, MAX_BUFFER);
    printf("Response: %s\n", buffer);

    send_command(sockfd, "PASS your_password"); // Replace with your password
    receive_response(sockfd, buffer, MAX_BUFFER);
    printf("Response: %s\n", buffer);

    // Retrieve the number of messages
    send_command(sockfd, "STAT");
    receive_response(sockfd, buffer, MAX_BUFFER);
    printf("Response: %s\n", buffer);

    // Parse the response for message count and size
    int message_count = 0;
    int total_size = 0;
    sscanf(buffer, "+OK %d %d", &message_count, &total_size);

    // Show statistics
    calculate_statistics(message_count, total_size);
    
    // Retrieve messages
    for(int i = 1; i <= message_count; i++) {
        sprintf(buffer, "RETR %d", i);
        send_command(sockfd, buffer);
        receive_response(sockfd, buffer, MAX_BUFFER);
        printf("Message %d: %s\n", i, buffer);
    }

    // Logout
    send_command(sockfd, "QUIT");
    receive_response(sockfd, buffer, MAX_BUFFER);
    printf("Response: %s\n", buffer);

    close(sockfd);
    return 0;
}