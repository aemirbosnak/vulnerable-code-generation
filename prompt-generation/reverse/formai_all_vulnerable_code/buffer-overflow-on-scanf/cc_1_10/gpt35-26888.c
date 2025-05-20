//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server_ip> <username>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    char *username = argv[2];

    // Create a TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the POP3 server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Receive the server greeting
    char buffer[BUFFER_SIZE] = {0};
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send USER command
    char user_cmd[BUFFER_SIZE] = {0};
    sprintf(user_cmd, "USER %s\r\n", username);
    send(sock, user_cmd, strlen(user_cmd), 0);

    // Receive USER command response
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send PASS command
    char password[BUFFER_SIZE] = {0};
    printf("Enter password: ");
    scanf("%s", password);
    char pass_cmd[BUFFER_SIZE] = {0};
    sprintf(pass_cmd, "PASS %s\r\n", password);
    send(sock, pass_cmd, strlen(pass_cmd), 0);

    // Receive PASS command response
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send STAT command
    char stat_cmd[BUFFER_SIZE] = {0};
    sprintf(stat_cmd, "STAT\r\n");
    send(sock, stat_cmd, strlen(stat_cmd), 0);

    // Receive STAT command response
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send LIST command
    char list_cmd[BUFFER_SIZE] = {0};
    sprintf(list_cmd, "LIST\r\n");
    send(sock, list_cmd, strlen(list_cmd), 0);

    // Receive LIST command response
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Close the socket
    close(sock);

    return 0;
}