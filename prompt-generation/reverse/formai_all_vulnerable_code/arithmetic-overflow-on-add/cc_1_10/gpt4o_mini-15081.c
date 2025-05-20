//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define SERVER_PORT 21

void error_handling(const char *message) {
    perror(message);
    exit(1);
}

void send_command(int sock, const char *cmd) {
    char buffer[BUF_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", cmd);
    send(sock, buffer, strlen(buffer), 0);
}

void receive_response(int sock) {
    char buffer[BUF_SIZE];
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("%s", buffer);
}

int connect_to_server(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect() error");
    }

    return sock;
}

void login(int sock, const char *username, const char *password) {
    char command[BUF_SIZE];

    receive_response(sock);
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sock, command);
    receive_response(sock);

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sock, command);
    receive_response(sock);
}

void list_files(int sock) {
    send_command(sock, "PASV");
    
    char buffer[BUF_SIZE];
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    
    char *token = strtok(buffer, "(,)");
    int p1, p2;
    while (token != NULL) {
        if (sscanf(token, "%d", &p1) == 1) {
            token = strtok(NULL, "(,)");
            continue;
        }
        if (sscanf(token, "%d", &p2) == 1) {
            break;
        }
        token = strtok(NULL, "(,)");
    }
    
    // Calculate port
    int data_port = p1 * 256 + p2;

    // Open data connection
    int data_sock = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assuming server on localhost for data connection 
    data_addr.sin_port = htons(data_port);

    if (connect(data_sock, (struct sockaddr*)&data_addr, sizeof(data_addr)) == -1) {
        error_handling("Data connection connect() error");
    }

    // List files
    send_command(sock, "LIST");
    receive_response(data_sock);
    receive_response(sock);

    close(data_sock);
}

void download_file(int sock, const char *filename) {
    send_command(sock, "PASV");
    
    char buffer[BUF_SIZE];
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    
    char *token = strtok(buffer, "(,)");
    int p1, p2;
    while (token != NULL) {
        if (sscanf(token, "%d", &p1) == 1) {
            token = strtok(NULL, "(,)");
            continue;
        }
        if (sscanf(token, "%d", &p2) == 1) {
            break;
        }
        token = strtok(NULL, "(,)");
    }
    
    int data_port = p1 * 256 + p2;

    int data_sock = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Assuming server on localhost for data connection 
    data_addr.sin_port = htons(data_port);

    if (connect(data_sock, (struct sockaddr*)&data_addr, sizeof(data_addr)) == -1) {
        error_handling("Data connection connect() error");
    }

    char command[BUF_SIZE];
    snprintf(command, sizeof(command), "RETR %s", filename);
    send_command(sock, command);
    receive_response(data_sock);
    
    FILE *fp = fopen(filename, "wb");
    char file_buffer[BUF_SIZE];
    int bytes_received;

    while ((bytes_received = recv(data_sock, file_buffer, sizeof(file_buffer), 0)) > 0) {
        fwrite(file_buffer, sizeof(char), bytes_received, fp);
    }

    fclose(fp);
    close(data_sock);
    receive_response(sock);
}

int main() {
    const char *server_ip = "127.0.0.1"; // Replace with your FTP server's IP address
    const char *username = "user"; // Replace with your FTP username
    const char *password = "pass"; // Replace with your FTP password

    int sock = connect_to_server(server_ip);
    login(sock, username, password);

    int choice;
    while (1) {
        printf("1. List files\n2. Download file\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                list_files(sock);
                break;
            case 2: {
                char filename[BUF_SIZE];
                printf("Enter filename to download: ");
                scanf("%s", filename);
                download_file(sock, filename);
                break;
            }
            case 3:
                close(sock);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    close(sock);
    return 0;
}