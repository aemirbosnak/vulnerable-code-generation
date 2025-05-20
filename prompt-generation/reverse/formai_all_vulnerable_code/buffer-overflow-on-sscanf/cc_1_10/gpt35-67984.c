//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUF_SIZE 2048

void send_file(int sock_fd, char file_path[]) {
    char file_name[BUF_SIZE];
    int file_fd, count;
    ssize_t sent;
    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);
    strcpy(file_name, strrchr(file_path, '/') + 1);
    file_fd = open(file_path, O_RDONLY);
    if (file_fd == -1) {
        perror("Error opening file");
        return;
    }
    sent = send(sock_fd, file_name, sizeof(file_name), 0);
    if (sent == -1) {
        perror("Error sending file name");
        return;
    }
    do {
        count = read(file_fd, buffer, BUF_SIZE);
        if (count == -1) {
            perror("Error reading file");
            return;
        }
        sent = send(sock_fd, buffer, count, 0);
        if (sent == -1) {
            perror("Error sending data");
            return;
        }
    } while (count > 0);
    printf("File sent successfully!\n");
    close(file_fd);
}

void receive_file(int sock_fd) {
    char file_name[BUF_SIZE];
    int file_fd;
    ssize_t received;
    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);
    received = recv(sock_fd, file_name, sizeof(file_name), 0);
    if (received == -1) {
        perror("Error receiving file name");
        return;
    }
    file_fd = open(file_name, O_WRONLY | O_CREAT, 0644);
    if (file_fd == -1) {
        perror("Error creating file");
        return;
    }
    do {
        received = recv(sock_fd, buffer, BUF_SIZE, 0);
        if (received == -1) {
            perror("Error receiving data");
            return;
        }
        write(file_fd, buffer, received);
    } while (received > 0);
    printf("File received successfully!\n");
    close(file_fd);
}

int main(int argc, char *argv[]) {
    int sock_fd, port;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUF_SIZE], command[BUF_SIZE], file_path[BUF_SIZE];
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }
    sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }
    port = atoi(argv[2]);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting");
        exit(1);
    }
    printf("Connected to server %s:%d\n", argv[1], port);
    while (1) {
        printf("Enter command: ");
        fgets(buffer, BUF_SIZE, stdin);
        sscanf(buffer, "%s %s", command, file_path);
        if (strcmp(command, "send") == 0) {
            send_file(sock_fd, file_path);
        } else if (strcmp(command, "receive") == 0) {
            send(sock_fd, command, sizeof(command), 0);
            receive_file(sock_fd);
        } else if (strcmp(command, "quit") == 0) {
            send(sock_fd, command, sizeof(command), 0);
            close(sock_fd);
            printf("Disconnected from server\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}