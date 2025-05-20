//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

void print_menu() {
    printf("----- Simple POP3 Client -----\n");
    printf("1. Connect to POP3 Server\n");
    printf("2. Retrieve Emails\n");
    printf("3. Quit\n");
    printf("------------------------------\n");
}

int connect_server(const char *server_address, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0';
    printf("Server Response: %s\n", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char login_command[BUFFER_SIZE];

    // Send USER command
    snprintf(login_command, sizeof(login_command), "USER %s\r\n", username);
    send_command(sockfd, login_command);
    receive_response(sockfd);

    // Send PASS command
    snprintf(login_command, sizeof(login_command), "PASS %s\r\n", password);
    send_command(sockfd, login_command);
    receive_response(sockfd);
}

void list_emails(int sockfd) {
    char command[] = "LIST\r\n";
    send_command(sockfd, command);
    receive_response(sockfd);
}

void quit_client(int sockfd) {
    char command[] = "QUIT\r\n";
    send_command(sockfd, command);
    receive_response(sockfd);
    close(sockfd);
}

int main() {
    const char *server_address = "127.0.0.1";
    int port = 110; // Standard POP3 port
    int sockfd = -1;
    char username[50], password[50];

    print_menu();
    int choice;

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                sockfd = connect_server(server_address, port);

                printf("Enter your username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove newline

                printf("Enter your password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline

                login(sockfd, username, password);
                break;

            case 2:
                if (sockfd < 0) {
                    printf("You need to connect to the server first!\n");
                } else {
                    list_emails(sockfd);
                }
                break;

            case 3:
                if (sockfd >= 0) {
                    quit_client(sockfd);
                }
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }
}