//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to print error message and exit
void error_exit(char *error_msg) {
    fprintf(stderr, "%s\n", error_msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        error_exit("Invalid arguments. Usage: ./smtp_client <IP address> <port>");
    }

    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        error_exit("Failed to create socket.");
    }

    // Set server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error_exit("Failed to connect to server.");
    }

    // Receive server greeting
    char server_response[1024];
    memset(server_response, 0, sizeof(server_response));
    if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
        error_exit("Failed to receive server response.");
    }
    printf("%s\n", server_response);

    // Send HELO command
    char helo_command[50];
    sprintf(helo_command, "HELO %s\r\n", argv[1]);
    if (send(client_socket, helo_command, strlen(helo_command), 0) < 0) {
        error_exit("Failed to send HELO command.");
    }

    // Receive server response
    memset(server_response, 0, sizeof(server_response));
    if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
        error_exit("Failed to receive server response.");
    }
    printf("%s\n", server_response);

    // Send MAIL FROM command
    char mail_from_command[50];
    printf("From: ");
    fgets(mail_from_command, sizeof(mail_from_command), stdin);
    char *new_line_char = strchr(mail_from_command, '\n');
    if (new_line_char) {
        *new_line_char = '\0';
    }
    char mail_from_full_command[100];
    sprintf(mail_from_full_command, "MAIL FROM:%s\r\n", mail_from_command);
    if (send(client_socket, mail_from_full_command, strlen(mail_from_full_command), 0) < 0) {
        error_exit("Failed to send MAIL FROM command.");
    }

    // Receive server response
    memset(server_response, 0, sizeof(server_response));
    if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
        error_exit("Failed to receive server response.");
    }
    printf("%s\n", server_response);

    // Send RCPT TO command
    char rcpt_to_command[50];
    printf("To: ");
    fgets(rcpt_to_command, sizeof(rcpt_to_command), stdin);
    new_line_char = strchr(rcpt_to_command, '\n');
    if (new_line_char) {
        *new_line_char = '\0';
    }
    char rcpt_to_full_command[100];
    sprintf(rcpt_to_full_command, "RCPT TO:%s\r\n", rcpt_to_command);
    if (send(client_socket, rcpt_to_full_command, strlen(rcpt_to_full_command), 0) < 0) {
        error_exit("Failed to send RCPT TO command.");
    }

    // Receive server response
    memset(server_response, 0, sizeof(server_response));
    if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
        error_exit("Failed to receive server response.");
    }
    printf("%s\n", server_response);

    // Send DATA command
    char data_command[10];
    sprintf(data_command, "DATA\r\n");
    if (send(client_socket, data_command, strlen(data_command), 0) < 0) {
        error_exit("Failed to send DATA command.");
    }

    // Receive server response
    memset(server_response, 0, sizeof(server_response));
    if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
        error_exit("Failed to receive server response.");
    }
    printf("%s\n", server_response);

    // Send email content
    printf("Subject: ");
    char subject[50];
    fgets(subject, sizeof(subject), stdin);
    new_line_char = strchr(subject, '\n');
    if (new_line_char) {
        *new_line_char = '\0';
    }
    printf("Message: ");
    char message[500];
    fgets(message, sizeof(message), stdin);
    new_line_char = strchr(message, '\n');
    if (new_line_char) {
        *new_line_char = '\0';
    }
    char email_body[600];
    sprintf(email_body, "From: %s\r\nTo:%s\r\nSubject:%s\r\n%s\r\n.\r\n", mail_from_command, rcpt_to_command, subject, message);
    if (send(client_socket, email_body, strlen(email_body), 0) < 0) {
        error_exit("Failed to send email content.");
    }

    // Receive server response
    memset(server_response, 0, sizeof(server_response));
    if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
        error_exit("Failed to receive server response.");
    }
    printf("%s\n", server_response);

    // Send QUIT command
    char quit_command[10];
    sprintf(quit_command, "QUIT\r\n");
    if (send(client_socket, quit_command, strlen(quit_command), 0) < 0) {
        error_exit("Failed to send QUIT command.");
    }

    // Receive server response
    memset(server_response, 0, sizeof(server_response));
    if (recv(client_socket, server_response, sizeof(server_response), 0) < 0) {
        error_exit("Failed to receive server response.");
    }
    printf("%s\n", server_response);

    // Close socket
    close(client_socket);

    return 0;
}