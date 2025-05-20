//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    char buf[BUF_SIZE];
    struct sockaddr_in server_addr;
    int port = 110;  // Default POP3 port

    if (argc < 2) {
        printf("Usage: %s <server-address> [port]\n", argv[0]);
        return 1;
    }

    if (argc == 3) {
        port = atoi(argv[2]);
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read welcome message from server
    memset(buf, 0, sizeof(buf));
    if (read(sock, buf, sizeof(buf)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s\n", buf);

    // Send user command
    const char *username = "username";
    char user_cmd[BUF_SIZE];
    snprintf(user_cmd, sizeof(user_cmd), "USER %s\r\n", username);
    if (write(sock, user_cmd, strlen(user_cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read response
    memset(buf, 0, sizeof(buf));
    if (read(sock, buf, sizeof(buf)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s\n", buf);

    // Send password command
    const char *password = "password";
    char pass_cmd[BUF_SIZE];
    snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s\r\n", password);
    if (write(sock, pass_cmd, strlen(pass_cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read response
    memset(buf, 0, sizeof(buf));
    if (read(sock, buf, sizeof(buf)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s\n", buf);

    // Send list command
    if (write(sock, "LIST\r\n", strlen("LIST\r\n")) < 0) {
        perror("write");
        return 1;
    }

    // Read response
    memset(buf, 0, sizeof(buf));
    if (read(sock, buf, sizeof(buf)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s\n", buf);

    // Send quit command
    if (write(sock, "QUIT\r\n", strlen("QUIT\r\n")) < 0) {
        perror("write");
        return 1;
    }

    // Read response
    memset(buf, 0, sizeof(buf));
    if (read(sock, buf, sizeof(buf)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s\n", buf);

    // Close socket
    close(sock);

    return 0;
}