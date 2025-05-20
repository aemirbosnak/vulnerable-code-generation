//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server = "imap.example.com";
    char *user = "username";
    char *passwd = "password";
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket error");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993); // IMAP port
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int len = recv(sock, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("recv error");
        return 1;
    }

    // Send login command
    sprintf(buffer, "LOGIN %s %s\r\n", user, passwd);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        return 1;
    }

    // Receive login response
    len = recv(sock, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("recv error");
        return 1;
    }
    buffer[len] = '\0';
    printf("%s", buffer);

    // Send select command to select inbox
    sprintf(buffer, "SELECT INBOX\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        return 1;
    }

    // Receive select response
    len = recv(sock, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("recv error");
        return 1;
    }
    buffer[len] = '\0';
    printf("%s", buffer);

    // Send search command to find all unread emails
    sprintf(buffer, "SEARCH UNSEEN\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        return 1;
    }

    // Receive search response
    len = recv(sock, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("recv error");
        return 1;
    }
    buffer[len] = '\0';
    printf("%s", buffer);

    // Logout
    sprintf(buffer, "LOGOUT\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        return 1;
    }

    len = recv(sock, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("recv error");
        return 1;
    }
    buffer[len] = '\0';
    printf("%s", buffer);

    if (close(sock) < 0) {
        perror("close error");
        return 1;
    }

    return 0;
}