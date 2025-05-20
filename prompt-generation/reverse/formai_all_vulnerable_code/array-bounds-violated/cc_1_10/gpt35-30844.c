//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Input validation
    if (argc != 4) {
        printf("Usage: %s <Server> <Port> <Username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get server information
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Unable to find server: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Unable to create socket\n");
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Unable to connect to server\n");
        return EXIT_FAILURE;
    }

    // Send username and password
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(socket_fd, buffer, BUFFER_SIZE, 0); // Receive initial greeting
    buffer[bytes_read] = '\0';
    printf("%s", buffer);

    getchar(); // Clear newline character from buffer

    char user_command[BUFFER_SIZE];
    char pass_command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    sprintf(user_command, "USER %s\r\n", argv[3]);
    send(socket_fd, user_command, strlen(user_command), 0);
    bytes_read = recv(socket_fd, response, BUFFER_SIZE, 0); // Receive response to username
    response[bytes_read] = '\0';
    printf("%s", response);

    getchar(); // Clear newline character from buffer

    printf("Please enter password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character from input

    sprintf(pass_command, "PASS %s\r\n", buffer);
    send(socket_fd, pass_command, strlen(pass_command), 0);
    bytes_read = recv(socket_fd, response, BUFFER_SIZE, 0); // Receive response to password
    response[bytes_read] = '\0';
    printf("%s", response);

    // Check if login was successful
    if (response[0] != '+' || response[1] != 'O' || response[2] != 'K') {
        printf("Unable to login\n");
        return EXIT_FAILURE;
    }

    // Send command to retrieve list of emails
    char list_command[] = "LIST\r\n";
    send(socket_fd, list_command, strlen(list_command), 0);
    bytes_read = recv(socket_fd, response, BUFFER_SIZE, 0); // Receive response to list command
    response[bytes_read] = '\0';
    printf("%s", response);

    getchar(); // Clear newline character from buffer

    // Parse number of emails from response
    int num_emails;
    sscanf(response, "+OK %d messages", &num_emails);

    // Display list of emails
    int email_number, email_size;
    for (int i = 0; i < num_emails; i++) {
        bytes_read = recv(socket_fd, response, BUFFER_SIZE, 0);
        response[bytes_read] = '\0';

        sscanf(response, "%d %d", &email_number, &email_size);
        printf("Email %d: %d bytes\n", email_number, email_size);
    }

    // Exit program
    close(socket_fd);
    return EXIT_SUCCESS;
}