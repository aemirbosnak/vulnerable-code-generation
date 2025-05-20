//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

char* get_file_name(char* path) {
    char* file_name = strrchr(path, '/');
    if (file_name == NULL) {
        file_name = path;
    }
    return file_name;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage:./ftp_client <server_ip> <file_path>\n");
        return 1;
    }

    char* server_ip = argv[1];
    char* file_path = argv[2];

    struct hostent* server = gethostbyname(server_ip);
    if (server == NULL) {
        printf("Invalid server IP address\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = *(unsigned long*)server->h_addr;

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    char username[20] = "anonymous";
    char password[20] = "anonymous@example.com";

    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    char command[50] = "USER ";
    strcat(command, username);
    send(sock, command, strlen(command), 0);

    char response[BUFFER_SIZE];
    recv(sock, response, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response);

    char command2[50] = "PASS ";
    strcat(command2, password);
    send(sock, command2, strlen(command2), 0);

    char response2[BUFFER_SIZE];
    recv(sock, response2, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response2);

    char command3[100] = "RETR ";
    strcat(command3, get_file_name(file_path));
    send(sock, command3, strlen(command3), 0);

    char response3[BUFFER_SIZE];
    recv(sock, response3, BUFFER_SIZE, 0);
    printf("Server response: %s\n", response3);

    FILE* file = fopen(file_path, "wb");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);
    close(sock);

    printf("File downloaded successfully\n");

    return 0;
}