//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    send(socket, "\r\n", 2, 0);
}

void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0'; // Null terminate the string
    printf("%s", buffer);
}

int main() {
    char server[100], email[100], subject[100], body[500];
    struct sockaddr_in smtp_server;
    int socket_desc;
    
    while (1) {
        printf("Enter SMTP server (or 'exit' to quit): ");
        scanf("%s", server);
        if (strcmp(server, "exit") == 0) break;

        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1) {
            perror("Could not create socket");
            continue;
        }

        smtp_server.sin_addr.s_addr = inet_addr(server);
        smtp_server.sin_family = AF_INET;
        smtp_server.sin_port = htons(SMTP_PORT);

        if (connect(socket_desc, (struct sockaddr *)&smtp_server, sizeof(smtp_server)) < 0) {
            perror("Connection failed");
            close(socket_desc);
            continue;
        }
        
        read_response(socket_desc);

        send_command(socket_desc, "HELO localhost");
        read_response(socket_desc);

        printf("Enter your email address: ");
        scanf("%s", email);
        send_command(socket_desc, "MAIL FROM: <");
        send(socket_desc, email, strlen(email), 0);
        send_command(socket_desc, ">");

        read_response(socket_desc);
        
        printf("Enter recipient email address: ");
        char recipient[100];
        scanf("%s", recipient);
        send_command(socket_desc, "RCPT TO: <");
        send(socket_desc, recipient, strlen(recipient), 0);
        send_command(socket_desc, ">");

        read_response(socket_desc);

        send_command(socket_desc, "DATA");
        read_response(socket_desc);

        printf("Enter email subject: ");
        scanf(" %[^\n]", subject);
        printf("Enter email body (end with a single dot on a new line):\n");
        strcpy(body, subject);
        strcat(body, "\n");
        char line[100];
        while (1) {
            scanf(" %[^\n]", line);
            if (strcmp(line, ".") == 0) break;
            strcat(body, line);
            strcat(body, "\n");
        }

        send(socket_desc, body, strlen(body), 0);
        send_command(socket_desc, ".");
        read_response(socket_desc);

        send_command(socket_desc, "QUIT");
        read_response(socket_desc);
        
        close(socket_desc);
    }
    
    return 0;
}