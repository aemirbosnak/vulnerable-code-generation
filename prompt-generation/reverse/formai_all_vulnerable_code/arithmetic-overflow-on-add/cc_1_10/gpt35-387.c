//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void recv_msg(int sock_fd, char buffer[BUFFER_SIZE]) {
    printf("Server response: ");
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./ftp_client <IP address>\n");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_addr;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    inet_pton(AF_INET, argv[1], &(server_addr.sin_addr));
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZE];
    recv_msg(sock_fd, buffer);
    // login
    char username[256], password[256];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    send(sock_fd, "USER ", 5, 0);
    send(sock_fd, username, strlen(username), 0);
    send(sock_fd, "\r\n", 2, 0);
    recv_msg(sock_fd, buffer);
    send(sock_fd, "PASS ", 5, 0);
    send(sock_fd, password, strlen(password), 0);
    send(sock_fd, "\r\n", 2, 0);
    recv_msg(sock_fd, buffer);
    // retrieve file
    send(sock_fd, "TYPE I\r\n", 8, 0);
    recv_msg(sock_fd, buffer);
    send(sock_fd, "PASV\r\n", 6, 0);
    recv_msg(sock_fd, buffer);
    char *str = strstr(buffer, "(");
    int h1, h2, h3, h4, p1, p2;
    sscanf(str, "(%d,%d,%d,%d,%d,%d)", &h1, &h2, &h3, &h4, &p1, &p2);
    char ip[256];
    sprintf(ip, "%d.%d.%d.%d", h1, h2, h3, h4);
    int port = p1 * 256 + p2;
    struct sockaddr_in data_addr;
    int data_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_fd < 0) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &(data_addr.sin_addr));

    if (connect(data_fd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("connect() failed");
        return EXIT_FAILURE;
    }
    send(sock_fd, "RETR file.txt\r\n", 15, 0);
    recv_msg(sock_fd, buffer);
    recv_msg(data_fd, buffer);

    FILE *fp;
    fp = fopen("file.txt", "w+");
    fwrite(buffer, sizeof(buffer[0]), strlen(buffer), fp);
    fclose(fp);

    close(sock_fd);
    close(data_fd);

    return 0;
}