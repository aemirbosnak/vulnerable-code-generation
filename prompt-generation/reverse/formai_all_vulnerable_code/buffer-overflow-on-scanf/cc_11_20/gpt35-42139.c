//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
// A POP3 Client program in C 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, read_size;
    struct sockaddr_in server;
    char message[MAX_SIZE], server_reply[MAX_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        exit(1);
    }

    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        exit(1);
    }

    puts("Connected\n");

    // Read the welcome message from the server
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s\n", server_reply);

    // Send the username to the server
    printf("Username: ");
    scanf("%s", message);
    strcat(message, "\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Read the server's response to the username
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s\n", server_reply);

    // Send the password to the server
    printf("Password: ");
    scanf("%s", message);
    strcat(message, "\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Read the server's response to the password
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s\n", server_reply);

    // Retrieve the list of messages on the server
    if (send(sock, "LIST\r\n", strlen("LIST\r\n"), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Read the server's response to the LIST command
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s\n", server_reply);

    // Retrieve the first message on the server
    if (send(sock, "RETR 1\r\n", strlen("RETR 1\r\n"), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Read the server's response to the RETR command
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("%s\n", server_reply);

    // Read the message itself
    while ((read_size = recv(sock, server_reply, MAX_SIZE, 0)) > 0) {
        printf("%s", server_reply);
    }

    puts("");

    close(sock);

    return 0;
}