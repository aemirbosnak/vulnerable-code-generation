//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (buffer[3] == ' ') break; // Exit on response end
    }
}

void connect_to_ftp(char *hostname) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) error("ERROR opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting to FTP server");
    }

    receive_response(sock);
    
    char username[50], password[50];
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sock, command);
    receive_response(sock);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sock, command);
    receive_response(sock);

    // List files in the current directory
    strcpy(command, "LIST\r\n");
    send_command(sock, command);
    receive_response(sock);

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    connect_to_ftp(argv[1]);

    return 0;
}