//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define BUF_SIZE 1024

char* generate_command(char *command, char* argument) {
    char *result = malloc(strlen(command) + strlen(argument) + 2);
    strcpy(result, command);
    strcat(result, " ");
    strcat(result, argument);
    strcat(result, "\r\n");
    return result;
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];
    char server_reply[BUF_SIZE];
    char username[BUF_SIZE], password[BUF_SIZE];
    char command[BUF_SIZE];

    // Open socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    puts("Socket created");

    // Server connection setup
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);

    // Connect to server
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }
    puts("Connected to server");

    // Get username and password
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Send username to server
    strcpy(command, generate_command("USER", username));
    if(send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to send username");
        return 1;
    }

    // Receive server reply
    if(recv(sock, server_reply, BUF_SIZE, 0) < 0) {
        perror("Failed to receive reply");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send password to server
    strcpy(command, generate_command("PASS", password));
    if(send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to send password");
        return 1;
    }

    // Receive server reply
    if(recv(sock, server_reply, BUF_SIZE, 0) < 0) {
        perror("Failed to receive reply");
        return 1;
    }
    printf("%s\n", server_reply);

    // Retrieve inbox
    strcpy(command, generate_command("LIST", ""));
    if(send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to retrieve inbox");
        return 1;
    }

    // Receive server reply
    if(recv(sock, server_reply, BUF_SIZE, 0) < 0) {
        perror("Failed to receive reply");
        return 1;
    }
    printf("%s\n", server_reply);

    close(sock);
    return 0;
}