//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 110 // Default port for POP3
#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

typedef struct {
    char username[50];
    char password[50];
} UserCredentials;

typedef struct {
    char emails[MAX_EMAILS][BUFFER_SIZE];
    int email_count;
} EmailList;

void handle_server_response(int socket, const char* expected_response) {
    char buffer[BUFFER_SIZE];
    if (recv(socket, buffer, sizeof(buffer), 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);
    if (strstr(buffer, expected_response) == NULL) {
        fprintf(stderr, "Unexpected server response!\n");
        exit(EXIT_FAILURE);
    }
}

void connect_to_pop3_server(const char* server_ip, UserCredentials* creds, EmailList* email_list) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    handle_server_response(sock, "+OK");

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", creds->username);
    send(sock, buffer, strlen(buffer), 0);
    handle_server_response(sock, "+OK");

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", creds->password);
    send(sock, buffer, strlen(buffer), 0);
    handle_server_response(sock, "+OK");

    // Retrieve emails count
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    handle_server_response(sock, "+OK");

    // Read email list
    int received_bytes;
    while ((received_bytes = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[received_bytes] = '\0';
        printf("Emails list: %s", buffer);
        if (strstr(buffer, ".\r\n")) break; // End of list
    }

    close(sock);
}

void display_email(EmailList* email_list) {
    printf("\nYour emails:\n");
    for (int i = 0; i < email_list->email_count; i++) {
        printf("%d: %s\n", i + 1, email_list->emails[i]);
    }
}

int get_user_credentials(UserCredentials* creds) {
    printf("Enter your username: ");
    scanf("%s", creds->username);
    printf("Enter your password: ");
    scanf("%s", creds->password);
    return 1; // Success
}

int main() {
    UserCredentials creds;
    EmailList email_list = { .email_count = 0 };

    if (!get_user_credentials(&creds)) {
        return EXIT_FAILURE;
    }

    char* server_ip = "127.0.0.1"; // Set your POP3 server's IP address

    connect_to_pop3_server(server_ip, &creds, &email_list);
    display_email(&email_list);

    return EXIT_SUCCESS;
}