//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: ./pop3_client <ip-address> <port-number> <username>\n");
        exit(EXIT_FAILURE);
    }

    int sock;
    struct sockaddr_in server_addr;
    char recv_buffer[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("\n Invalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("\n Connection Failed \n");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message
    memset(recv_buffer, 0, BUFFER_SIZE);
    if (recv(sock, recv_buffer, BUFFER_SIZE, 0) == -1) {
        printf("\n Error in receiving data \n");
        exit(EXIT_FAILURE);
    }

    // Enter Username
    char* username = argv[3];
    char user_msg[BUFFER_SIZE];
    sprintf(user_msg, "USER %s\r\n", username);
    if (send(sock, user_msg, strlen(user_msg), 0) == -1) {
        printf("\n Error in sending data \n");
        exit(EXIT_FAILURE);
    }

    memset(recv_buffer, 0, BUFFER_SIZE);
    if (recv(sock, recv_buffer, BUFFER_SIZE, 0) == -1) {
        printf("\n Error in receiving data \n");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buffer);

    // Enter Password
    char password[BUFFER_SIZE];
    printf("Enter Password: ");
    scanf("%s", password);
    char pass_msg[BUFFER_SIZE];
    sprintf(pass_msg, "PASS %s\r\n", password);
    if (send(sock, pass_msg, strlen(pass_msg), 0) == -1) {
        printf("\n Error in sending data \n");
        exit(EXIT_FAILURE);
    }

    memset(recv_buffer, 0, BUFFER_SIZE);
    if (recv(sock, recv_buffer, BUFFER_SIZE, 0) == -1) {
        printf("\n Error in receiving data \n");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buffer);

    // List mails
    if (send(sock, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        printf("\n Error in sending data \n");
        exit(EXIT_FAILURE);
    }

    memset(recv_buffer, 0, BUFFER_SIZE);
    if (recv(sock, recv_buffer, BUFFER_SIZE, 0) == -1) {
        printf("\n Error in receiving data \n");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buffer);

    // Quit
    if (send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        printf("\n Error in sending data \n");
        exit(EXIT_FAILURE);
    }

    memset(recv_buffer, 0, BUFFER_SIZE);
    if (recv(sock, recv_buffer, BUFFER_SIZE, 0) == -1) {
        printf("\n Error in receiving data \n");
        exit(EXIT_FAILURE);
    }
    printf("%s", recv_buffer);

    close(sock);
    return 0;
}