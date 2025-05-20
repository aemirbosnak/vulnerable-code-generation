//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        return 1;
    }

    const char* server_address = argv[1];
    const int port_number = atoi(argv[2]);

    // Create a socket
    const int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Get server address info
    struct hostent* server = gethostbyname(server_address);
    if (server == NULL) {
        perror("Failed to get server address info");
        return 1;
    }

    // Set server info struct
    struct sockaddr_in server_addr;
    bzero((char*) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr,
          (char*) &server_addr.sin_addr.s_addr,
          server->h_length);
    server_addr.sin_port = htons(port_number);

    // Connect to the server
    if (connect(sockfd,
                (struct sockaddr*) &server_addr,
                sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    // Receive initial response from server
    char buf[BUF_SIZE];
    bzero(buf, BUF_SIZE);
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Server Response: %s\n", buf);

    // Send LOGIN command to server
    const char* login_cmd = "a1 LOGIN test@test.com password\r\n";
    if (send(sockfd, login_cmd, strlen(login_cmd), 0) < 0) {
        perror("Failed to send LOGIN command to server");
        return 1;
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Server Response: %s\n", buf);

    // Send LIST command to server
    const char* list_cmd = "a2 LIST \"\" *\r\n";
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) < 0) {
        perror("Failed to send LIST command to server");
        return 1;
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Server Response: %s\n", buf);

    // Send SELECT command to server
    const char* select_cmd = "a3 SELECT INBOX\r\n";
    if (send(sockfd, select_cmd, strlen(select_cmd), 0) < 0) {
        perror("Failed to send SELECT command to server");
        return 1;
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Server Response: %s\n", buf);

    // Send FETCH command to server
    const char* fetch_cmd = "a4 FETCH 1 BODY[HEADER]\r\n";
    if (send(sockfd, fetch_cmd, strlen(fetch_cmd), 0) < 0) {
        perror("Failed to send FETCH command to server");
        return 1;
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Server Response: %s\n", buf);

    // Send LOGOUT command to server
    const char* logout_cmd = "a5 LOGOUT\r\n";
    if (send(sockfd, logout_cmd, strlen(logout_cmd), 0) < 0) {
        perror("Failed to send LOGOUT command to server");
        return 1;
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        perror("Failed to receive response from server");
        return 1;
    }
    printf("Server Response: %s\n", buf);

    // Close socket
    close(sockfd);

    return 0;
}