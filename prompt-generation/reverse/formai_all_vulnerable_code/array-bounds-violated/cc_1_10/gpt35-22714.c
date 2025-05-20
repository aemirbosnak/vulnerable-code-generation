//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAXSIZE 1024 // Maximum buffer size
#define POP3_PORT 110 // POP3 Port number

int main(int argc, char *argv[]) {
    if (argc != 4) { // Check command line arguments
        printf("Usage: ./pop3_client <server_address> <username> <password>\n");
        return 1;
    }

    char* server_address = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket()");
        exit(1);
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_aton(server_address, &server_addr.sin_addr) == 0) {
        perror("inet_aton()");
        exit(1);
    }
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect()");
        exit(1);
    }

    char buffer[MAXSIZE];
    int recv_size;

    // Receive server greeting
    recv_size = recv(sock, buffer, MAXSIZE, 0);
    buffer[recv_size] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("Received invalid response from server.\n");
        printf("%s\n", buffer);
        exit(1);
    }

    // Send user command
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response to user command
    recv_size = recv(sock, buffer, MAXSIZE, 0);
    buffer[recv_size] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("Received invalid response from server.\n");
        printf("%s\n", buffer);
        exit(1);
    }

    // Send password command
    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);

    // Receive response to password command
    recv_size = recv(sock, buffer, MAXSIZE, 0);
    buffer[recv_size] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("Received invalid response from server.\n");
        printf("%s\n", buffer);
        exit(1);
    }

    // Send STAT command
    sprintf(buffer, "STAT\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Receive response to STAT command
    recv_size = recv(sock, buffer, MAXSIZE, 0);
    buffer[recv_size] = '\0';
    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("Received invalid response from server.\n");
        printf("%s\n", buffer);
        exit(1);
    }
    printf("%s", buffer);

    // Close the connection
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    close(sock);

    return 0;
}