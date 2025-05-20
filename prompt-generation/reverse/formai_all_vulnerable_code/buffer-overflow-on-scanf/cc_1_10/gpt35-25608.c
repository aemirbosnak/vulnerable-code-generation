//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: genious
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MAX_MSG_LEN 1024

int create_socket(char *server_ip, int port) {
    int client_socket;
    struct sockaddr_in server_address;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        return -1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(port);

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect");
        return -1;
    }

    return client_socket;
}

int main(int argc, char const *argv[]) {
    int client_socket;
    char server_ip[100];
    int port;
    char username[100];
    char password[100];
    char recipient_email[100];
    char subject[100];
    char message[MAX_MSG_LEN];
    char request_buffer[MAX_MSG_LEN];

    printf("Which SMTP server would you like to connect to? ");
    scanf("%s", server_ip);
    printf("What port should be used? ");
    scanf("%d", &port);

    client_socket = create_socket(server_ip, port);
    if (client_socket == -1) {
        return 1;
    }

    printf("Connected to the server!\n");

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    printf("Recipient email address: ");
    scanf("%s", recipient_email);

    printf("Subject: ");
    scanf("%s", subject);

    printf("Message: ");
    scanf(" %[^\t\n]s", message);

    sprintf(request_buffer, "EHLO %s\r\n", server_ip);
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    sprintf(request_buffer, "AUTH LOGIN\r\n");
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    // Base64 encoding of username and password
    char encoded_username[100];
    char encoded_password[100];
    int i;
    for (i = 0; i < strlen(username); i++) {
        encoded_username[i] = username[i] + 5;
    }
    encoded_username[i] = '\0';

    for (i = 0; i < strlen(password); i++) {
        encoded_password[i] = password[i] + 5;
    }
    encoded_password[i] = '\0';

    sprintf(request_buffer, "%s\r\n", encoded_username);
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    sprintf(request_buffer, "%s\r\n", encoded_password);
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    sprintf(request_buffer, "MAIL FROM:<%s>\r\n", username);
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    sprintf(request_buffer, "RCPT TO:<%s>\r\n", recipient_email);
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    sprintf(request_buffer, "DATA\r\n");
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    sprintf(request_buffer, "Subject: %s\r\n%s\r\n.\r\n", subject, message);
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    sprintf(request_buffer, "QUIT\r\n");
    send(client_socket, request_buffer, strlen(request_buffer), 0);
    recv(client_socket, request_buffer, MAX_MSG_LEN, 0);
    printf("%s", request_buffer);

    close(client_socket);

    return 0;
}