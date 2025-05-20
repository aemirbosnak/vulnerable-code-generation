//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server hostname> <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_hostname = argv[1];
    const char *port_number = argv[2];

    struct hostent *server;
    struct sockaddr_in server_addr;
    char recv_buf[MAX_BUF_SIZE];

    // Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Get server IP address from hostname
    server = gethostbyname(server_hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host as %s\n", server_hostname);
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(atoi(port_number));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive greeting message
    if (recv(sockfd, recv_buf, MAX_BUF_SIZE, 0) < 0) {
        perror("ERROR receiving greeting message");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server greeting: %s\n", recv_buf);

    // Send username
    const char *username = "USER alice";
    if (send(sockfd, username, strlen(username), 0) < 0) {
        perror("ERROR sending username");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive response to username
    if (recv(sockfd, recv_buf, MAX_BUF_SIZE, 0) < 0) {
        perror("ERROR receiving response to username");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server response to username: %s\n", recv_buf);

    // Send password
    const char *password = "PASS secret";
    if (send(sockfd, password, strlen(password), 0) < 0) {
        perror("ERROR sending password");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive response to password
    if (recv(sockfd, recv_buf, MAX_BUF_SIZE, 0) < 0) {
        perror("ERROR receiving response to password");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server response to password: %s\n", recv_buf);

    // Send command to get number of emails in inbox
    const char *stat_cmd = "STAT\r\n";
    if (send(sockfd, stat_cmd, strlen(stat_cmd), 0) < 0) {
        perror("ERROR sending STAT command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive response to STAT command
    if (recv(sockfd, recv_buf, MAX_BUF_SIZE, 0) < 0) {
        perror("ERROR receiving response to STAT command");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server response to STAT command: %s\n", recv_buf);

    close(sockfd);
    exit(EXIT_SUCCESS);
}