//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char const *argv[]) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        error("Error opening socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    int addr_status = inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (addr_status <= 0) {
        error("Error address not supported");
    }

    int status = connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (status < 0) {
        error("Error connecting to FTP server");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    char user[50], password[50];
    printf("User: ");
    scanf("%s", user);
    char* user_command = strcat(user, "\r\n");
    send(sock_fd, user_command, strlen(user_command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    printf("Password: ");
    scanf("%s", password);
    char* password_command = strcat(password, "\r\n");
    send(sock_fd, password_command, strlen(password_command), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    char* pasv = "PASV\r\n";
    send(sock_fd, pasv, strlen(pasv), 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock_fd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);

    char* get = "RETR hello.txt\r\n";
    send(sock_fd, get, strlen(get), 0);
    memset(buffer, 0, BUFFER_SIZE);

    int data_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock_fd < 0) {
        error("Error opening data socket");
    }

    int left, right, value;
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", &left, &right, &value, &value, &value, &value);

    int port = left * 256 + right;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    status = connect(data_sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (status < 0) {
        error("Error connecting to data socket");
    }

    ssize_t nbytes;
    FILE* fp = fopen("hello.txt", "w");

    if (!fp) {
        error("Error opening file");
    }

    while ((nbytes = recv(data_sock_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, nbytes, 1, fp);
    }

    memset(buffer, 0, BUFFER_SIZE);
    nbytes = recv(sock_fd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    fclose(fp);

    close(sock_fd);
    close(data_sock_fd);

    return 0;
}