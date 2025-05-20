//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    send(sock, "\r\n", 2, 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void ftp_login(int sock, const char *user, const char *pass) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", user);
    send_command(sock, command);
    receive_response(sock);

    snprintf(command, sizeof(command), "PASS %s", pass);
    send_command(sock, command);
    receive_response(sock);
}

void ftp_list(int sock) {
    send_command(sock, "PASV");
    receive_response(sock);

    // In a real implementation, you would parse the response to find the data connection.
    // Here we will keep it simple and assume we can connect to localhost for demo purposes.

    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        handle_error("ERROR opening data socket");
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(2021); // Dummy data port
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(data_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        handle_error("ERROR connecting to data socket");
    }

    send_command(sock, "LIST");
    receive_response(sock);

    char buffer[BUFFER_SIZE];
    while (recv(data_sock, buffer, sizeof(buffer) - 1, 0) > 0) {
        printf("%s", buffer);
    }

    close(data_sock);
}

void ftp_download(int sock, const char *filename) {
    send_command(sock, "RETR filename.txt"); // Replace 'filename.txt' with the actual parameter

    // In a real implementation, you would again set up a data connection.
    // Here we assume a data connection is established.

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        handle_error("ERROR opening file");
    }

    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("ERROR opening socket");
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(FTP_PORT);
    server.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        handle_error("ERROR connecting to server");
    }
    
    receive_response(sock);
    ftp_login(sock, username, password);
    ftp_list(sock);
    ftp_download(sock, "filename.txt"); // Modify with actual usage
    close(sock);
    
    return 0;
}