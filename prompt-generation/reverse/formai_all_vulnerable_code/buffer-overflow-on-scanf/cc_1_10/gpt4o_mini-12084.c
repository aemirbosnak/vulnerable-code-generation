//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_EMAIL 256
#define MAX_BUFFER 1024

void display_menu() {
    printf("\n===== Simple C Email Client =====\n");
    printf("1. Send Email\n");
    printf("2. Receive Email\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25); // SMTP Port
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sock);
        return;
    }

    // SMTP communication
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // HELO command
    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Message headers and body
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    close(sock);
}

void receive_email(const char *imap_server, const char *username, const char *password) {
    // Placeholder for receiving email logic
    printf("Connecting to IMAP server %s...\n", imap_server);
    printf("Logging in as %s...\n", username);
    printf("Fetching emails...\n");
    // In practice, you'll use a library to handle IMAP protocols
    printf("This feature is yet to be implemented.\n");
}

int main() {
    char smtp_server[MAX_EMAIL];
    char imap_server[MAX_EMAIL];
    char from[MAX_EMAIL];
    char to[MAX_EMAIL];
    char subject[MAX_EMAIL];
    char body[MAX_BUFFER];
    
    printf("Enter your SMTP Server: ");
    fgets(smtp_server, sizeof(smtp_server), stdin);
    smtp_server[strcspn(smtp_server, "\n")] = 0;

    printf("Enter your IMAP Server: ");
    fgets(imap_server, sizeof(imap_server), stdin);
    imap_server[strcspn(imap_server, "\n")] = 0;

    printf("Enter your Email Address: ");
    fgets(from, sizeof(from), stdin);
    from[strcspn(from, "\n")] = 0;

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                printf("Enter recipient's email: ");
                fgets(to, sizeof(to), stdin);
                to[strcspn(to, "\n")] = 0;

                printf("Enter subject: ");
                fgets(subject, sizeof(subject), stdin);
                subject[strcspn(subject, "\n")] = 0;

                printf("Enter body (end with a single dot on a new line):\n");
                fgets(body, sizeof(body), stdin);
                body[strcspn(body, "\n")] = 0; // Allow first line of body

                send_email(smtp_server, from, to, subject, body);
                break;
            case 2:
                printf("Enter your username: ");
                fgets(from, sizeof(from), stdin); // Reusing from for username
                from[strcspn(from, "\n")] = 0;

                printf("Enter your password: ");
                char password[MAX_EMAIL];
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0;

                receive_email(imap_server, from, password);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}