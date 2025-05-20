//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main() {
    char server_address[16], user_name[100], password[100];
    printf("Enter the server address: ");
    scanf("%s", server_address);
    printf("Enter your username: ");
    scanf("%s", user_name);
    printf("Enter your password: ");
    scanf("%s", password);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Create server address struct
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(110);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    // Read server response
    char recv_buf[MAX_BUF_SIZE];
    int recv_len = recv(sock, recv_buf, MAX_BUF_SIZE, 0);
    recv_buf[recv_len] = '\0';
    printf("Server response: %s\n", recv_buf);

    // Send username to server
    char user_buf[MAX_BUF_SIZE] = {0};
    snprintf(user_buf, MAX_BUF_SIZE, "USER %s\r\n", user_name);
    if (send(sock, user_buf, strlen(user_buf), 0) < 0) {
        perror("Error sending username to server");
        return -1;
    }

    // Read server response
    recv_len = recv(sock, recv_buf, MAX_BUF_SIZE, 0);
    recv_buf[recv_len] = '\0';
    printf("Server response: %s\n", recv_buf);

    // Send password to server
    char pass_buf[MAX_BUF_SIZE] = {0};
    snprintf(pass_buf, MAX_BUF_SIZE, "PASS %s\r\n", password);
    if (send(sock, pass_buf, strlen(pass_buf), 0) < 0) {
        perror("Error sending password to server");
        return -1;
    }

    // Read server response
    recv_len = recv(sock, recv_buf, MAX_BUF_SIZE, 0);
    recv_buf[recv_len] = '\0';
    printf("Server response: %s\n", recv_buf);

    // Send list command to server
    char list_buf[MAX_BUF_SIZE] = "LIST\r\n";
    if (send(sock, list_buf, strlen(list_buf), 0) < 0) {
        perror("Error sending list command to server");
        return -1;
    }

    // Read server response
    recv_len = recv(sock, recv_buf, MAX_BUF_SIZE, 0);
    recv_buf[recv_len] = '\0';
    printf("Server response: %s\n", recv_buf);

    // Send quit command to server
    char quit_buf[MAX_BUF_SIZE] = "QUIT\r\n";
    if (send(sock, quit_buf, strlen(quit_buf), 0) < 0) {
        perror("Error sending quit command to server");
        return -1;
    }

    // Read server response
    recv_len = recv(sock, recv_buf, MAX_BUF_SIZE, 0);
    recv_buf[recv_len] = '\0';
    printf("Server response: %s\n", recv_buf);

    // Close socket
    close(sock);

    return 0;
}