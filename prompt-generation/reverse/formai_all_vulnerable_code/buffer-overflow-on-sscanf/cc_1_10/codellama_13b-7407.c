//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
// POP3 Client Example Program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_MESSAGES 10
#define MAX_MESSAGE_SIZE 1024

struct pop3_message {
    char subject[100];
    char from[100];
    char date[50];
    char message[MAX_MESSAGE_SIZE];
};

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the POP3 username and password
    char username[100];
    char password[100];
    printf("Enter POP3 username: ");
    fgets(username, sizeof(username), stdin);
    printf("Enter POP3 password: ");
    fgets(password, sizeof(password), stdin);
    char command[100];
    sprintf(command, "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);
    sprintf(command, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);

    // Receive the POP3 server response
    char response[100];
    recv(sock, response, sizeof(response), 0);
    printf("Server response: %s\n", response);

    // Get the number of messages in the mailbox
    int num_messages;
    sprintf(command, "STAT\r\n");
    send(sock, command, strlen(command), 0);
    recv(sock, response, sizeof(response), 0);
    sscanf(response, "+OK %d messages", &num_messages);
    printf("Number of messages in the mailbox: %d\n", num_messages);

    // Get the message list
    struct pop3_message messages[MAX_MESSAGES];
    for (int i = 0; i < num_messages; i++) {
        sprintf(command, "LIST %d\r\n", i);
        send(sock, command, strlen(command), 0);
        recv(sock, response, sizeof(response), 0);
        sscanf(response, "+OK %s %s %s %s", messages[i].subject, messages[i].from, messages[i].date, messages[i].message);
    }

    // Print the message list
    for (int i = 0; i < num_messages; i++) {
        printf("Subject: %s\nFrom: %s\nDate: %s\nMessage: %s\n\n", messages[i].subject, messages[i].from, messages[i].date, messages[i].message);
    }

    // Close the socket
    close(sock);

    return 0;
}