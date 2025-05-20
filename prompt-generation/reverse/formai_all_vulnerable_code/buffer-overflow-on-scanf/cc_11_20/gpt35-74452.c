//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        return 1;
    }

    char *server_address = argv[1];
    int port_number = atoi(argv[2]);

    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    server_addr.sin_port = htons(port_number);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server %s:%d\n", server_address, port_number);

    char username[MAX_MSG_SIZE];
    char password[MAX_MSG_SIZE];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    char authentication_msg[MAX_MSG_SIZE];
    sprintf(authentication_msg, "AUTH %s %s\n", username, password);

    int bytes_sent = send(client_socket, authentication_msg, strlen(authentication_msg), 0);
    if (bytes_sent != strlen(authentication_msg)) {
        printf("Error sending message\n");
        return 1;
    }

    char server_response[MAX_MSG_SIZE];
    int bytes_received = recv(client_socket, server_response, MAX_MSG_SIZE - 1, 0);
    if (bytes_received == -1) {
        printf("Error receiving message\n");
        return 1;
    }

    server_response[bytes_received] = '\0';
    if (strcmp(server_response, "OK\n") != 0) {
        printf("Authentication failed\n");
        return 1;
    }

    printf("Authentication successful. You can now send emails.\n");

    while (1) {
        char recipient[MAX_MSG_SIZE];
        char subject[MAX_MSG_SIZE];
        char message[MAX_MSG_SIZE];

        printf("Recipient: ");
        scanf("%s", recipient);
        printf("Subject: ");
        scanf("%s", subject);
        printf("Message: ");
        scanf("%s", message);

        char email_msg[MAX_MSG_SIZE];
        sprintf(email_msg, "EMAIL %s %s %s\n", recipient, subject, message);

        int bytes_sent = send(client_socket, email_msg, strlen(email_msg), 0);
        if (bytes_sent != strlen(email_msg)) {
            printf("Error sending message\n");
            return 1;
        }

        char server_response[MAX_MSG_SIZE];
        int bytes_received = recv(client_socket, server_response, MAX_MSG_SIZE - 1, 0);
        if (bytes_received == -1) {
            printf("Error receiving message\n");
            return 1;
        }

        server_response[bytes_received] = '\0';
        if (strcmp(server_response, "EMAIL_SENT\n") != 0) {
            printf("Error sending email\n");
            return 1;
        }

        printf("Email sent successfully\n");
        sleep(1);
    }

    close(client_socket);
    return 0;
}