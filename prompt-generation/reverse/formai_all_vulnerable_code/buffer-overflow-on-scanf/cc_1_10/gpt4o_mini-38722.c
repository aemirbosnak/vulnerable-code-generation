//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *server_ip) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "226 Transfer complete.") != NULL ||
            strstr(buffer, "221 Goodbye.") != NULL) {
            break;
        }
    }
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);
    // Further code to handle PASV response and list files
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];

    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);
    // Further code to handle PASV response and download file
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void upload_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];

    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);
    // Further code to handle PASV response and upload file
    snprintf(command, sizeof(command), "STOR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);
}

int main() {
    char server_ip[16];
    char username[32];
    char password[32];
    char command[BUFFER_SIZE];
    int sockfd;

    printf("Enter FTP Server IP: ");
    scanf("%s", server_ip);

    sockfd = connect_to_server(server_ip);
    receive_response(sockfd);

    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    login(sockfd, username, password);

    while (1) {
        printf("\nAvailable commands: LIST, GET <file>, PUT <file>, QUIT\n");
        printf("Enter command: ");
        scanf(" %[^\n]", command);

        if (strncmp(command, "LIST", 4) == 0) {
            list_files(sockfd);
        } else if (strncmp(command, "GET ", 4) == 0) {
            download_file(sockfd, command + 4);
        } else if (strncmp(command, "PUT ", 4) == 0) {
            upload_file(sockfd, command + 4);
        } else if (strncmp(command, "QUIT", 4) == 0) {
            send_command(sockfd, "QUIT\r\n");
            receive_response(sockfd);
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    close(sockfd);
    return 0;
}