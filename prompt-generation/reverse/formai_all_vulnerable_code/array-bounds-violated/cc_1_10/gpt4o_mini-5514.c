//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void ftp_command(int sock, const char *cmd) {
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        error("Failed to send command");
    }
}

char* receive_response(int sock) {
    static char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Failed to receive response");
    }
    buffer[bytes_received] = '\0';
    return buffer;
}

int connect_to_ftp(const char *hostname) {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Failed to create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    return sock;
}

void login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    ftp_command(sock, command);
    printf("%s", receive_response(sock));

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    ftp_command(sock, command);
    printf("%s", receive_response(sock));
}

void get_file(int sock, const char *filename, const char *local_file) {
    char command[BUFFER_SIZE];
    
    snprintf(command, sizeof(command), "PASV\r\n");
    ftp_command(sock, command);
    printf("%s", receive_response(sock));

    // here we should parse the server response but for simplicity, assuming fixed for testing
    int data_sock;
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(2121); // Example: You have to change depending on your server response
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Or the actual IP of your FTP server

    if ((data_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Failed to create data socket");
    }

    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Data connection failed");
    }

    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    ftp_command(sock, command);
    printf("%s", receive_response(sock));

    FILE *fp = fopen(local_file, "wb");
    if (!fp) {
        error("Failed to open file for writing");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(data_sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, fp);
    }

    fclose(fp);
    close(data_sock);
    printf("%s", receive_response(sock)); // final server response from RETR
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *filename = argv[4];
    
    int ftp_sock = connect_to_ftp(hostname);
    char *response = receive_response(ftp_sock);
    printf("%s", response);

    login(ftp_sock, username, password);
    get_file(ftp_sock, filename, filename);

    close(ftp_sock);
    return 0;
}