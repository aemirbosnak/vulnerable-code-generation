//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd = 0, port = 21;
    char server_ip[16] = "", username[32] = "", password[32] = "";
    struct sockaddr_in server_addr;
    const char *cmd_user = "USER", *cmd_pass = "PASS", *cmd_quit = "QUIT", *cmd_pwd = "PWD", *cmd_cwd = "CWD", *cmd_pasv = "PASV", *cmd_list = "LIST";
    char buf[MAX_BUF_SIZE] = "";
    ssize_t n_recv = 0;
    bool login_success = false;

    // Get server IP, username and password from user input
    printf("Please input FTP server IP: ");
    scanf("%s", server_ip);
    printf("Please input username: ");
    scanf("%s", username);
    printf("Please input password: ");
    scanf("%s", password);

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Connect to FTP server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) == -1) {
        perror("Failed to convert server IP address");
        exit(EXIT_FAILURE);
    }
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to FTP server");
        exit(EXIT_FAILURE);
    }

    // Read welcome message
    memset(buf, 0, sizeof(buf));
    if ((n_recv = recv(sock_fd, buf, sizeof(buf), 0)) == -1) {
        perror("Failed to read welcome message");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Login to FTP server
    sprintf(buf, "%s %s\r\n", cmd_user, username);
    if (send(sock_fd, buf, strlen(buf), 0) == -1) {
        perror("Failed to send username");
        exit(EXIT_FAILURE);
    }
    memset(buf, 0, sizeof(buf));
    if ((n_recv = recv(sock_fd, buf, sizeof(buf), 0)) == -1) {
        perror("Failed to read response to username");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);
    sprintf(buf, "%s %s\r\n", cmd_pass, password);
    if (send(sock_fd, buf, strlen(buf), 0) == -1) {
        perror("Failed to send password");
        exit(EXIT_FAILURE);
    }
    memset(buf, 0, sizeof(buf));
    if ((n_recv = recv(sock_fd, buf, sizeof(buf), 0)) == -1) {
        perror("Failed to read response to password");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);
    if (buf[0] != '2') {
        printf("Failed to login\n");
        exit(EXIT_FAILURE);
    }
    login_success = true;

    // Enter passive mode
    if (login_success) {
        if (send(sock_fd, cmd_pasv, strlen(cmd_pasv), 0) == -1) {
            perror("Failed to send PASV command");
            exit(EXIT_FAILURE);
        }
        memset(buf, 0, sizeof(buf));
        if ((n_recv = recv(sock_fd, buf, sizeof(buf), 0)) == -1) {
            perror("Failed to read response to PASV command");
            exit(EXIT_FAILURE);
        }
        printf("%s", buf);
    }

    // List files in current directory
    if (login_success) {
        if (send(sock_fd, cmd_list, strlen(cmd_list), 0) == -1) {
            perror("Failed to send LIST command");
            exit(EXIT_FAILURE);
        }
        memset(buf, 0, sizeof(buf));
        if ((n_recv = recv(sock_fd, buf, sizeof(buf), 0)) == -1) {
            perror("Failed to read response to LIST command");
            exit(EXIT_FAILURE);
        }
        printf("%s", buf);
    }

    // Logout
    if (login_success) {
        if (send(sock_fd, cmd_quit, strlen(cmd_quit), 0) == -1) {
            perror("Failed to send QUIT command");
            exit(EXIT_FAILURE);
        }
        memset(buf, 0, sizeof(buf));
        if ((n_recv = recv(sock_fd, buf, sizeof(buf), 0)) == -1) {
            perror("Failed to read response to QUIT command");
            exit(EXIT_FAILURE);
        }
        printf("%s", buf);
    }

    close(sock_fd);

    return 0;
}