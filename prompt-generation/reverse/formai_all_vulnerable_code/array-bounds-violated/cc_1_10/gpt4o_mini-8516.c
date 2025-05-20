//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define IMAP_PORT 993

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname) {
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;
    
    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        die("getaddrinfo failed");
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        die("socket creation failed");
    }

    // Use SSL for secure connection (port 993 for IMAP)
    struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
    addr->sin_port = htons(IMAP_PORT);
    
    if (connect(sockfd, (struct sockaddr *)res->ai_addr, res->ai_addrlen) < 0) {
        die("connect failed");
    }
    
    freeaddrinfo(res);
    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        die("send failed");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        die("recv failed");
    }

    buffer[bytes_received] = '\0';
    printf("Server Response: %s\n", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char login_cmd[BUFFER_SIZE];
    snprintf(login_cmd, sizeof(login_cmd), "A001 LOGIN \"%s\" \"%s\"\r\n", username, password);
    send_command(sockfd, login_cmd);
    receive_response(sockfd);
}

void list_mailboxes(int sockfd) {
    const char *list_cmd = "A002 LIST \"\" \"*\"\r\n";
    send_command(sockfd, list_cmd);
    receive_response(sockfd);
}

void logout(int sockfd) {
    const char *logout_cmd = "A003 LOGOUT\r\n";
    send_command(sockfd, logout_cmd);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket(hostname);

    // Read server's greeting
    receive_response(sockfd);

    // Login to the IMAP server
    login(sockfd, username, password);

    // List mailboxes
    list_mailboxes(sockfd);

    // Logout
    logout(sockfd);

    close(sockfd);
    return 0;
}