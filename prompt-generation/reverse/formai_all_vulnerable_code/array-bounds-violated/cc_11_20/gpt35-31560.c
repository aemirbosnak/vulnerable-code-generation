//FormAI DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 25

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock < 0)
    {
        fputs("Failed to create socket\n", stderr);
        exit(1);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(SERVER_PORT);

    if(connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
        fputs("Failed to connect to server\n", stderr);
        exit(1);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }

    printf("%s", buffer);

    char username[256];
    printf("Enter your email username: ");
    fgets(username, sizeof(username), stdin);
    username[strlen(username)-1] = '\0';

    char password[256];
    printf("Enter your email password: ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password)-1] = '\0';

    snprintf(buffer, sizeof(buffer), "AUTH LOGIN\r\n");
    send(sock, buffer, strlen(buffer), 0);
    printf("Sending: %s", buffer);

    bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "%s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    printf("Sending: %s", buffer);

    bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "%s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    printf("Sending: %s", buffer);

    bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }

    printf("%s", buffer);

    char recipient[256];
    printf("Enter recipient email address: ");
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strlen(recipient)-1] = '\0';

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    printf("Sending: %s", buffer);

    bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", recipient);
    send(sock, buffer, strlen(buffer), 0);
    printf("Sending: %s", buffer);

    bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    printf("\nSending: %s", buffer);

    bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }

    printf("%s", buffer);

    char subject[256];
    printf("Enter email subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strlen(subject)-1] = '\0';

    char message[1024];
    printf("Enter email message (max 1024 characters):\n");
    fgets(message, sizeof(message), stdin);
    message[strlen(message)-1] = '\0';

    snprintf(buffer, sizeof(buffer), "From: %s\r\n", username);
    snprintf(buffer+strlen(buffer), sizeof(buffer)-strlen(buffer), "To: %s\r\n", recipient);
    snprintf(buffer+strlen(buffer), sizeof(buffer)-strlen(buffer), "Subject: %s\r\n", subject);
    snprintf(buffer+strlen(buffer), sizeof(buffer)-strlen(buffer), "\r\n");
    snprintf(buffer+strlen(buffer), sizeof(buffer)-strlen(buffer), "%s\r\n", message);
    snprintf(buffer+strlen(buffer), sizeof(buffer)-strlen(buffer), ".\r\n");

    send(sock, buffer, strlen(buffer), 0);
    printf("\nSending email...\n\n%s", buffer);

    bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    printf("Sending: %s", buffer);

    bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    if(bytes < 0)
    {
        fputs("Failed to read data from server\n", stderr);
        exit(1);
    }

    printf("%s", buffer);

    close(sock);
    return 0;
}