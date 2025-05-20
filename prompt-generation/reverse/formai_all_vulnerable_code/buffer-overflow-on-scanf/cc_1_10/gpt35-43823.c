//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void send_email(int client_socket) {
    char message[1000];
    char server_reply[5000];
    char from[100];
    char to[100];
    char subject[200];
    char body[2000];
    
    printf("From: ");
    scanf("%s", from);
    sprintf(message, "MAIL FROM: <%s>\r\n", from);
    send(client_socket, message, strlen(message), 0);
    recv(client_socket, server_reply, 5000, 0);
    printf("%s", server_reply);

    printf("To: ");
    scanf("%s", to);
    sprintf(message, "RCPT TO: <%s>\r\n", to);
    send(client_socket, message, strlen(message), 0);
    recv(client_socket, server_reply, 5000, 0);
    printf("%s", server_reply);
    
    printf("Subject: ");
    scanf("%s", subject);
    printf("Body: ");
    scanf("%s", body);
    sprintf(message, "DATA\r\n"
            "From: <%s>\r\n"
            "To: <%s>\r\n"
            "Subject: %s\r\n\r\n"
            "%s\r\n"
            ".\r\n", from, to, subject, body);
    send(client_socket, message, strlen(message), 0);
    recv(client_socket, server_reply, 5000, 0);
    printf("%s", server_reply);
    
    sprintf(message, "QUIT\r\n");
    send(client_socket, message, strlen(message), 0);
    recv(client_socket, server_reply, 5000, 0);
    printf("%s", server_reply);
}

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char server_reply[5000];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Socket creation error.\n");
        return 1;
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(25);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Connection error.\n");
        return 1;
    }

    // Wait for server greeting
    recv(client_socket, server_reply, 5000, 0);
    printf("%s", server_reply);
    
    send_email(client_socket);

    close(client_socket);
    return 0;
}