//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LINE_SIZE 1000
#define MAX_HOST_SIZE 50
#define MAX_USERNAME_SIZE 50
#define MAX_PASSWORD_SIZE 50
#define MAX_SUBJECT_SIZE 50
#define MAX_BODY_SIZE 1000
#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char host[MAX_HOST_SIZE];
    char username[MAX_USERNAME_SIZE];
    char password[MAX_PASSWORD_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
    char line[MAX_LINE_SIZE];
    char buffer[MAX_LINE_SIZE + 1];
    int bytes_sent, bytes_received;

    if (argc < 2) {
        printf("Usage: %s <SMTP Server>\n", argv[0]);
        return -1;
    }

    // Get server hostname
    printf("Enter server hostname: ");
    fgets(host, MAX_HOST_SIZE, stdin);
    host[strcspn(host, "\n")] = '\0';

    // Get credentials
    printf("Enter username: ");
    fgets(username, MAX_USERNAME_SIZE, stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_SIZE, stdin);
    password[strcspn(password, "\n")] = '\0';

    // Get email subject
    printf("Enter email subject: ");
    fgets(subject, MAX_SUBJECT_SIZE, stdin);
    subject[strcspn(subject, "\n")] = '\0';

    // Get email body
    printf("Enter email body: ");
    fgets(body, MAX_BODY_SIZE, stdin);
    body[strcspn(body, "\n")] = '\0';

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Error: socket() failed");
        return -1;
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        struct hostent *he;
        he = gethostbyname(argv[1]);
        if (he == NULL) {
            perror("Error: gethostbyname() failed");
            return -1;
        }
        memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: connect() failed");
        close(sock);
        return -1;
    }

    // Receive greeting
    bytes_received = recv(sock, buffer, MAX_LINE_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error: recv() failed");
        close(sock);
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send username
    sprintf(line, "USER %s\r\n", username);
    bytes_sent = send(sock, line, strlen(line), 0);
    if (bytes_sent == -1) {
        perror("Error: send() failed");
        close(sock);
        return -1;
    }

    // Receive confirmation
    bytes_received = recv(sock, buffer, MAX_LINE_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error: recv() failed");
        close(sock);
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send password
    sprintf(line, "PASS %s\r\n", password);
    bytes_sent = send(sock, line, strlen(line), 0);
    if (bytes_sent == -1) {
        perror("Error: send() failed");
        close(sock);
        return -1;
    }

    // Receive confirmation
    bytes_received = recv(sock, buffer, MAX_LINE_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error: recv() failed");
        close(sock);
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send sender
    sprintf(line, "MAIL FROM:<%s%s>\r\n", username, host);
    bytes_sent = send(sock, line, strlen(line), 0);
    if (bytes_sent == -1) {
        perror("Error: send() failed");
        close(sock);
        return -1;
    }

    // Receive confirmation
    bytes_received = recv(sock, buffer, MAX_LINE_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error: recv() failed");
        close(sock);
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send recipient
    printf("Enter recipient email: ");
    fgets(line, MAX_LINE_SIZE, stdin);
    line[strcspn(line, "\n")] = '\0';
    sprintf(line, "RCPT TO:<%s>\r\n", line);
    bytes_sent = send(sock, line, strlen(line), 0);
    if (bytes_sent == -1) {
        perror("Error: send() failed");
        close(sock);
        return -1;
    }

    // Receive confirmation
    bytes_received = recv(sock, buffer, MAX_LINE_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error: recv() failed");
        close(sock);
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send data marker
    sprintf(line, "DATA\r\n");
    bytes_sent = send(sock, line, strlen(line), 0);
    if (bytes_sent == -1) {
        perror("Error: send() failed");
        close(sock);
        return -1;
    }

    // Receive confirmation
    bytes_received = recv(sock, buffer, MAX_LINE_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error: recv() failed");
        close(sock);
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send email
    sprintf(line, "From: %s%s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", username, host, line, subject, body);
    bytes_sent = send(sock, line, strlen(line), 0);
    if (bytes_sent == -1) {
        perror("Error: send() failed");
        close(sock);
        return -1;
    }

    // Receive confirmation
    bytes_received = recv(sock, buffer, MAX_LINE_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error: recv() failed");
        close(sock);
        return -1;
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Disconnect from server
    sprintf(line, "QUIT\r\n");
    bytes_sent = send(sock, line, strlen(line), 0);
    if (bytes_sent == -1) {
        perror("Error: send() failed");
        close(sock);
        return -1;
    }
    close(sock);

    return 0;
}