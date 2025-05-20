//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_RECV_BUF 1024
#define MAX_SEND_BUF 1024
#define SERVER_PORT 21

int main(int argc, char *argv[]) {
    int client_fd, retcode, data_fd, recv_len, bytes_sent;
    char send_buf[MAX_SEND_BUF], recv_buf[MAX_RECV_BUF], username[50], password[50], filename[50];
    struct sockaddr_in server_addr, data_addr;
    socklen_t addr_len = sizeof(data_addr);

    // opening a socket
    client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_fd < 0) {
        perror("Failed to open socket");
        exit(EXIT_FAILURE);
    }

    // setting up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // connecting to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // receiving server greeting
    recv_len = recv(client_fd, recv_buf, MAX_RECV_BUF, 0);
    if (recv_len < 0) {
        perror("Failed to receive server greeting");
        exit(EXIT_FAILURE);
    }
    recv_buf[recv_len] = '\0';
    printf("%s", recv_buf);

    // sending login credentials
    printf("Username: ");
    scanf("%s", username);
    snprintf(send_buf, MAX_SEND_BUF, "USER %s\r\n", username);
    bytes_sent = send(client_fd, send_buf, strlen(send_buf), 0);
    if (bytes_sent < 0) {
        perror("Failed to send username");
        exit(EXIT_FAILURE);
    }

    printf("Password: ");
    scanf("%s", password);
    snprintf(send_buf, MAX_SEND_BUF, "PASS %s\r\n", password);
    bytes_sent = send(client_fd, send_buf, strlen(send_buf), 0);
    if (bytes_sent < 0) {
        perror("Failed to send password");
        exit(EXIT_FAILURE);
    }

    // checking login status
    recv_len = recv(client_fd, recv_buf, MAX_RECV_BUF, 0);
    if (recv_len < 0) {
        perror("Failed to receive login status");
        exit(EXIT_FAILURE);
    }
    recv_buf[recv_len] = '\0';
    if (recv_buf[0] != '2') {
        printf("%s", recv_buf);
        exit(EXIT_FAILURE);
    }

    // starting data transfer mode
    snprintf(send_buf, MAX_SEND_BUF, "PASV\r\n");
    bytes_sent = send(client_fd, send_buf, strlen(send_buf), 0);
    if (bytes_sent < 0) {
        perror("Failed to send PASV command");
        exit(EXIT_FAILURE);
    }

    recv_len = recv(client_fd, recv_buf, MAX_RECV_BUF, 0);
    if (recv_len < 0) {
        perror("Failed to receive PASV response");
        exit(EXIT_FAILURE);
    }
    recv_buf[recv_len] = '\0';
    printf("%s", recv_buf);

    // parsing data connection parameters
    int a, b, c, d, p1, p2;
    sscanf(recv_buf, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\r\n", &a, &b, &c, &d, &p1, &p2);

    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(p1 * 256 + p2);
    char data_ip[MAX_SEND_BUF];
    snprintf(data_ip, MAX_SEND_BUF, "%d.%d.%d.%d", a, b, c, d);
    inet_pton(AF_INET, data_ip, &data_addr.sin_addr);

    // requesting file from server
    printf("Enter filename: ");
    scanf("%s", filename);
    snprintf(send_buf, MAX_SEND_BUF, "RETR %s\r\n", filename);
    bytes_sent = send(client_fd, send_buf, strlen(send_buf), 0);
    if (bytes_sent < 0) {
        perror("Failed to request file");
        exit(EXIT_FAILURE);
    }

    // establishing data connection with server
    data_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (data_fd < 0) {
        perror("Failed to open data socket");
        exit(EXIT_FAILURE);
    }

    if (connect(data_fd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Failed to connect to data port");
        exit(EXIT_FAILURE);
    }

    // receiving file contents and writing to local file
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to create local file");
        exit(EXIT_FAILURE);
    }

    while ((recv_len = recv(data_fd, recv_buf, MAX_RECV_BUF, 0)) > 0) {
        fwrite(recv_buf, sizeof(char), recv_len, file);
    }
    fclose(file);

    // cleanup
    close(data_fd);
    close(client_fd);
    exit(EXIT_SUCCESS);
}