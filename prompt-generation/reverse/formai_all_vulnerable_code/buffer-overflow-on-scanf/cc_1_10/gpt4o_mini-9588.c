//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    
    char *hostname = "pop.your-email-provider.com"; // Change to your email provider's POP3 server
    char user[50], pass[50];

    printf("Enter your email username: ");
    fgets(user, 50, stdin);
    user[strcspn(user, "\n")] = 0; // Remove newline character
    
    printf("Enter your email password: ");
    fgets(pass, 50, stdin);
    pass[strcspn(pass, "\n")] = 0; // Remove newline character

    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("Could not create socket");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with actual address resolution for hostname if needed

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }
    
    // Reading initial server response
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // User Authentication
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", user);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", pass);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Fetching message count
    send(sock, "STAT\r\n", 7, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Loop through messages
    char command[BUFFER_SIZE];
    int msg_count = 0; // You need to extract this value from STAT response
    
    printf("Enter the number of emails to fetch: ");
    scanf("%d", &msg_count);

    for (int i = 1; i <= msg_count; i++) {
        snprintf(command, sizeof(command), "RETR %d\r\n", i);
        send(sock, command, strlen(command), 0);
        recv(sock, buffer, BUFFER_SIZE, 0);
        printf("Server Response for Message %d:\n%s", i, buffer);

        // To read until end of message
        while (strstr(buffer, "\r\n.\r\n") == NULL) {
            recv(sock, buffer, BUFFER_SIZE, 0);
            printf("%s", buffer);
        }
    }

    // Quit the session
    send(sock, "QUIT\r\n", 7, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Closing the socket
    close(sock);

    return 0;
}