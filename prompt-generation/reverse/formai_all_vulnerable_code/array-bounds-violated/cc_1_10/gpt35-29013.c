//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void extract_response(char *response, char *output) {
    char *header = strtok(response, "\r\n");
    while(header != NULL) {
        if (!strncmp(header, "Subject: ", 9)) {
            strcpy(output, &header[9]);
            return;
        }
        header = strtok(NULL, "\r\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_ip> <server_port> <username>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *username = argv[3];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive greeting message
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Send username to server
    char command[BUFFER_SIZE];
    sprintf(command, "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // Prompt for password and send to server
    printf("Password: ");
    char password[BUFFER_SIZE];
    fgets(password, BUFFER_SIZE, stdin);
    password[strlen(password) - 1] = 0;  // Remove newline character

    sprintf(command, "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    // List messages
    sprintf(command, "LIST\r\n");
    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    while (strncmp(buffer, ".\r\n", 3)) {
        recv(sock, buffer, BUFFER_SIZE, 0);
        printf("%s\n", buffer);
    }

    // Prompt for message number and retrieve it
    printf("Message #: ");
    char message_num[BUFFER_SIZE];
    fgets(message_num, BUFFER_SIZE, stdin);
    message_num[strlen(message_num) - 1] = 0;

    sprintf(command, "RETR %s\r\n", message_num);
    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    // Extract subject line from response
    char subject[BUFFER_SIZE];
    extract_response(buffer, subject);
    printf("Subject: %s\n", subject);

    // Quit and disconnect
    sprintf(command, "QUIT\r\n");
    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    close(sock);
    return 0;
}