//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Welcome message
void welcome() {
    printf(
        "===========================================\n"
        "         Welcome to the Email Client!         \n"
        "             By the one and only,            \n"
        "                   The Coder Cat!                   \n"
        "===========================================\n"
    );
}

// Get input from user
char* get_input(char* prompt) {
    printf("%s", prompt);
    char* input = (char*)malloc(100);
    scanf("%s", input);
    return input;
}

// Connect to the server
int connect_to_server(char* server_ip, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Could not create socket");
        exit(1);
    }

    // Fill in the server's address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: Could not connect to server");
        exit(1);
    }

    return sockfd;
}

// Send data to the server
void send_data(int sockfd, char* data) {
    int n = send(sockfd, data, strlen(data), 0);
    if (n < 0) {
        perror("ERROR: Could not send data");
        exit(1);
    }
}

// Receive data from the server
char* receive_data(int sockfd) {
    char* data = (char*)malloc(100);
    int n = recv(sockfd, data, 99, 0);
    if (n < 0) {
        perror("ERROR: Could not receive data");
        exit(1);
    }
    data[n] = '\0';
    return data;
}

// Close the connection to the server
void close_connection(int sockfd) {
    close(sockfd);
}

// Main function
int main() {
    // Welcome the user
    welcome();

    // Get the server IP address and port
    char* server_ip = get_input("Enter the server IP address: ");
    int port = atoi(get_input("Enter the server port: "));

    // Connect to the server
    int sockfd = connect_to_server(server_ip, port);

    // Send a greeting to the server
    send_data(sockfd, "Hello from the Email Client!");

    // Receive a greeting from the server
    char* greeting = receive_data(sockfd);
    printf("The server says: %s\n", greeting);

    // Send an email
    char* to = get_input("Enter the recipient's email address: ");
    char* from = get_input("Enter your email address: ");
    char* subject = get_input("Enter the email subject: ");
    char* body = get_input("Enter the email body: ");

    char* email = (char*)malloc(300);
    sprintf(email, "TO: %s\nFROM: %s\nSUBJECT: %s\nBODY: %s\n", to, from, subject, body);

    send_data(sockfd, email);

    // Receive a confirmation from the server
    char* confirmation = receive_data(sockfd);
    printf("The server says: %s\n", confirmation);

    // Close the connection to the server
    close_connection(sockfd);

    return 0;
}