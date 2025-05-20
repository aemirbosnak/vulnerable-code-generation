//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
// Building a SMTP Client Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s <SMTP Server IP Address> <SMTP Server Port> <Sender Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int client_socket;
    struct sockaddr_in server_address;

    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Creation Failed");
        return EXIT_FAILURE;
    }

    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connect Failed");
        return EXIT_FAILURE;
    }

    char buffer[MAX_BUFFER_SIZE];

    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }

    printf("Message from Server: %s", buffer);

    // Login to SMTP Server
    char auth[50];
    sprintf(auth, "AUTH LOGIN\r\n");
    send(client_socket, auth, strlen(auth), 0);
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }
    printf("Message from Server: %s", buffer);

    // Enter Username
    char username[50];
    printf("Enter Username: ");
    scanf("%s", username);
    send(client_socket, username, strlen(username), 0);
    send(client_socket, "\r\n", strlen("\r\n"), 0);
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }
    printf("Message from Server: %s", buffer);

    // Enter Password
    char password[50];
    printf("Enter Password: ");
    scanf("%s", password);
    send(client_socket, password, strlen(password), 0);
    send(client_socket, "\r\n", strlen("\r\n"), 0);
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }
    printf("Message from Server: %s", buffer);

    // Send Mail
    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[3]);
    send(client_socket, buffer, strlen(buffer), 0);
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }
    printf("Message from Server: %s", buffer);

    // Enter Recipient Address
    char recipient[50];
    printf("Enter Recipient Address: ");
    scanf("%s", recipient);
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    send(client_socket, buffer, strlen(buffer), 0);
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }
    printf("Message from Server: %s", buffer);

    // Enter Subject and Message
    char subject[50], message[MAX_BUFFER_SIZE];
    printf("Enter Subject: ");
    scanf("%s", subject);

    printf("Enter Message: ");
    scanf(" %[^\n]s", message);

    sprintf(buffer, "DATA\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }
    printf("Message from Server: %s", buffer);

    sprintf(buffer, "Subject:%s\r\nFrom:%s\r\nTo:%s\r\n\r\n%s\r\n.\r\n", subject, argv[3], recipient, message);
    send(client_socket, buffer, strlen(buffer), 0);
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }
    printf("Message from Server: %s", buffer);

    // Logout from SMTP Server
    sprintf(buffer, "QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    if(recv(client_socket, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Receive Failed");
        return EXIT_FAILURE;
    }
    printf("Message from Server: %s", buffer);

    close(client_socket);

    return EXIT_SUCCESS;
}