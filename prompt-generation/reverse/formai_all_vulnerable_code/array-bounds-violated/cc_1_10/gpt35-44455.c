//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *server_ip = "pop.example.com"; // Replace with your POP3 server IP
    int port = 110; // POP3 port
    char user[MAX_SIZE];
    char pass[MAX_SIZE];

    printf("Enter username: ");
    fgets(user, MAX_SIZE, stdin);
    user[strlen(user)-1] = '\0'; // Remove the newline character
    printf("Enter password: ");
    fgets(pass, MAX_SIZE, stdin);
    pass[strlen(pass)-1] = '\0'; // Remove the newline character

    // Create TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("Creation of socket failed");
        exit(1);
    }

    printf("Socket created successfully\n");

    server.sin_addr.s_addr = inet_addr(server_ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection to the server failed");
        exit(1);
    }

    printf("Connected to the server successfully\n");

    // Receive the server greeting message
    char server_message[MAX_SIZE];
    recv(sock, server_message, MAX_SIZE, 0);
    printf("%s", server_message);

    // Send the login credentials to the server
    char login_request[MAX_SIZE];
    sprintf(login_request, "USER %s\r\n", user);
    send(sock, login_request, strlen(login_request), 0);
    recv(sock, server_message, MAX_SIZE, 0);
    printf("%s", server_message);

    sprintf(login_request, "PASS %s\r\n", pass);
    send(sock, login_request, strlen(login_request), 0);
    recv(sock, server_message, MAX_SIZE, 0);
    printf("%s", server_message);

    // Send the retrieve message request
    char retrieve_request[MAX_SIZE];
    sprintf(retrieve_request, "LIST\r\n");
    send(sock, retrieve_request, strlen(retrieve_request), 0);
    recv(sock, server_message, MAX_SIZE, 0);
    printf("%s", server_message);

    // Disconnect from server
    char quit_request[MAX_SIZE];
    sprintf(quit_request, "QUIT\r\n");
    send(sock, quit_request, strlen(quit_request), 0);
    close(sock);

    printf("Disconnected from server\n");

    return 0;
}