//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SMTP_SERVER "smtp.example.com" // Replace with your SMTP server
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

typedef struct {
    char email[100];
    char subject[100];
    char body[500];
} Email;

void *send_email(void *arg) {
    Email *email_info = (Email *)arg;
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Fill server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SMTP_SERVER, &server_addr.sin_addr);

    // Connect to SMTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sock);
        return NULL;
    }

    // Receiving the server greeting
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Send HELO command
    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // AUTH login (this is not a secure example)
    // In a real application, replace THIS with actual AUTH
    snprintf(buffer, sizeof(buffer), "AUTH LOGIN\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Send the email
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<your_email@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", email_info->email);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", email_info->subject, email_info->body);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Quit
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Clean up
    close(sock);
    return NULL;
}

int main() {
    int num_players;
    printf("Enter number of email senders (players): ");
    scanf("%d", &num_players);
    pthread_t threads[num_players];
    Email emails[num_players];

    for (int i = 0; i < num_players; i++) {
        printf("Player %d, enter Email, Subject and Body:\n", i + 1);
        printf("Email: ");
        scanf("%s", emails[i].email);
        printf("Subject: ");
        scanf("%s", emails[i].subject);
        printf("Body: ");
        scanf(" %[^\n]", emails[i].body); // Allow spaces in body
        pthread_create(&threads[i], NULL, send_email, (void *)&emails[i]);
    }

    for (int i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All emails sent!\n");
    return 0;
}