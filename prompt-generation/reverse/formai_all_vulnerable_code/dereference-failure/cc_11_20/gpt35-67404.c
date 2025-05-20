//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

    // Check for command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get server address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve host %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Set socket attributes
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Read greeting message from server
    char greeting[MAX_BUF_SIZE];
    ssize_t num_bytes_read = recv(socket_fd, greeting, MAX_BUF_SIZE, 0);
    if (num_bytes_read == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Server greeting: %.*s", num_bytes_read, greeting);

    // Send user credentials to server
    char username[MAX_BUF_SIZE];
    printf("Username: ");
    fgets(username, MAX_BUF_SIZE, stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove trailing newline
    char password[MAX_BUF_SIZE];
    printf("Password: ");
    fgets(password, MAX_BUF_SIZE, stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove trailing newline
    char auth_string[MAX_BUF_SIZE];
    snprintf(auth_string, sizeof(auth_string), "USER %s\r\nPASS %s\r\n", username, password);
    printf("Sending authentication string: %s", auth_string);
    if (send(socket_fd, auth_string, strlen(auth_string), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read authentication response from server
    char auth_response[MAX_BUF_SIZE];
    num_bytes_read = recv(socket_fd, auth_response, MAX_BUF_SIZE, 0);
    if (num_bytes_read == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Server response to authentication string: %.*s", num_bytes_read, auth_response);

    // Send request to list messages
    char list_string[] = "LIST\r\n";
    printf("Sending list request: %s", list_string);
    if (send(socket_fd, list_string, sizeof(list_string), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read message listing from server
    char list_response[MAX_BUF_SIZE];
    num_bytes_read = recv(socket_fd, list_response, MAX_BUF_SIZE, 0);
    if (num_bytes_read == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Server response to message list request: %.*s", num_bytes_read, list_response);

    // Send request to retrieve message
    printf("Enter message number to retrieve: ");
    char message_number_str[MAX_BUF_SIZE];
    fgets(message_number_str, MAX_BUF_SIZE, stdin);
    message_number_str[strcspn(message_number_str, "\n")] = '\0'; // Remove trailing newline
    char retr_string[MAX_BUF_SIZE];
    snprintf(retr_string, sizeof(retr_string), "RETR %s\r\n", message_number_str);
    printf("Sending message retrieval request: %s", retr_string);
    if (send(socket_fd, retr_string, strlen(retr_string), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read message from server
    char message[MAX_BUF_SIZE];
    num_bytes_read = recv(socket_fd, message, MAX_BUF_SIZE, 0);
    if (num_bytes_read == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Server response to message retrieval request: %.*s", num_bytes_read, message);

    // Send quit command
    char quit_string[] = "QUIT\r\n";
    printf("Sending quit command: %s", quit_string);
    if (send(socket_fd, quit_string, sizeof(quit_string), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read server response to quit command
    char quit_response[MAX_BUF_SIZE];
    num_bytes_read = recv(socket_fd, quit_response, MAX_BUF_SIZE, 0);
    if (num_bytes_read == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Server response to quit command: %.*s", num_bytes_read, quit_response);

    // Close socket
    close(socket_fd);

    return 0;
}