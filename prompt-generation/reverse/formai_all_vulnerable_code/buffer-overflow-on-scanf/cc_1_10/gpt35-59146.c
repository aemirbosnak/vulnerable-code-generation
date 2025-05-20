//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 110 // Port number for POP3 server
#define MAX_BUFFER_SIZE 1024 // Maximum buffer size for messages

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide the server hostname or IP address.\n");
        exit(1);
    }
    
    // Create a TCP socket for POP3 client
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Failed to create a socket.\n");
        exit(1);
    }

    struct sockaddr_in server;
    char server_reply[MAX_BUFFER_SIZE] = {0};
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(PORT);

    // Connect to POP3 server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed.\n");
        exit(1);
    }

    // Receive server response
    recv(sock, server_reply, MAX_BUFFER_SIZE, 0); 
    printf("%s", server_reply);

    // Authenticate user
    char username[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE];
    printf("Enter username: ");
    scanf("%s", username);
    send(sock, username, strlen(username), 0);
    recv(sock, server_reply, MAX_BUFFER_SIZE, 0); 
    printf("%s", server_reply);

    printf("Enter password: ");
    scanf("%s", password);
    send(sock, password, strlen(password), 0);
    recv(sock, server_reply, MAX_BUFFER_SIZE, 0); 
    printf("%s", server_reply);

    // List mailbox
    send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
    recv(sock, server_reply, MAX_BUFFER_SIZE, 0); 
    printf("%s", server_reply);

    // Retrieve message
    char message_num[MAX_BUFFER_SIZE];
    printf("Enter message number: ");
    scanf("%s", message_num);
    char retrieve_command[MAX_BUFFER_SIZE];
    sprintf(retrieve_command, "RETR %s\r\n", message_num);
    send(sock, retrieve_command, strlen(retrieve_command), 0);
    recv(sock, server_reply, MAX_BUFFER_SIZE, 0); 
    printf("%s", server_reply);

    // Quit session
    send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(sock, server_reply, MAX_BUFFER_SIZE, 0); 
    printf("%s", server_reply);

    // Close socket and exit
    close(sock);
    return 0;
}