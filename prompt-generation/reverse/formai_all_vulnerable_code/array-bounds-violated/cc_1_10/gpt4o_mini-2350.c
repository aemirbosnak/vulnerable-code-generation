//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 256

void herald(const char *message) {
    printf(">>> %s\n", message);
}

void summon_socket(int *sockfd) {
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        herald("Alas! The socket could not be summoned!");
        exit(EXIT_FAILURE);
    }
    herald("The socket hath been summoned!");
}

void bind_socket(int sockfd, struct sockaddr_in *address) {
    if (bind(sockfd, (struct sockaddr *)address, sizeof(*address)) < 0) {
        herald("The binding failed, alas!");
        exit(EXIT_FAILURE);
    }
    herald("The socket hath been bound successfully!");
}

void connect_to_server(int sockfd, struct sockaddr_in *server_addr) {
    if (connect(sockfd, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        herald("Hark! Could not connect to the FTP server!");
        exit(EXIT_FAILURE);
    }
    herald("Connected to the FTP server with great success!");
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("<<< %s", buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[MAX_COMMAND_LENGTH];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void ftp_list_files(int sockfd) {
    char command[MAX_COMMAND_LENGTH];

    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
}

void embark_on_ftp_quest(const char *server_ip, const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;

    summon_socket(&sockfd);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    connect_to_server(sockfd, &server_addr);
    
    receive_response(sockfd);
    ftp_login(sockfd, username, password);
    ftp_list_files(sockfd);

    close(sockfd);
    herald("The quest is complete, the FTP client hath closed!");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        herald("Usage: ./ftp_client <server_ip> <username> <password>");
        return 1;
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    herald("Commencing the noble FTP quest!");
    embark_on_ftp_quest(server_ip, username, password);

    return 0;
}