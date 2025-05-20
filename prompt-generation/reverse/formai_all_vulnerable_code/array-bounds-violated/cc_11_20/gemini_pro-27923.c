//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

int main()
{
    // Create a socket for the FTP connection.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the FTP server.
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive the welcome message from the FTP server.
    char buffer[BUFFER_SIZE];
    int n = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (n == -1) {
        perror("recv");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the username to the FTP server.
    const char *username = "user";
    n = send(sock, username, strlen(username), 0);
    if (n == -1) {
        perror("send");
        exit(1);
    }

    // Receive the username response from the FTP server.
    n = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (n == -1) {
        perror("recv");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the password to the FTP server.
    const char *password = "password";
    n = send(sock, password, strlen(password), 0);
    if (n == -1) {
        perror("send");
        exit(1);
    }

    // Receive the password response from the FTP server.
    n = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (n == -1) {
        perror("recv");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // List the files in the current directory.
    const char *command = "LIST";
    n = send(sock, command, strlen(command), 0);
    if (n == -1) {
        perror("send");
        exit(1);
    }

    // Receive the file list from the FTP server.
    n = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (n == -1) {
        perror("recv");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Close the FTP connection.
    close(sock);

    return 0;
}