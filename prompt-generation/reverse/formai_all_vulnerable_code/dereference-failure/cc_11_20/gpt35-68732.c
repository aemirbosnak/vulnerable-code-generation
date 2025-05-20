//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char const *argv[]) {
    int client_socket, server_port;
    char server_ip[50];
    struct sockaddr_in server_address;
    char buff[MAX_BUFF_SIZE];
    const char *user_name = "ftp_username";
    const char *password = "ftp_password";
    const char *file_name_in = "file_to_upload";
    const char *file_name_out = "file_to_download";

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <Server IP> <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strcpy(server_ip, argv[1]);
    server_port = atoi(argv[2]);

    // Create a socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Login with username and password
    sprintf(buff, "USER %s\r\n", user_name);
    send(client_socket, buff, strlen(buff), 0);
    sprintf(buff, "PASS %s\r\n", password);
    send(client_socket, buff, strlen(buff), 0);

    // Upload file
    sprintf(buff, "STOR %s\r\n", file_name_in);
    send(client_socket, buff, strlen(buff), 0);

    // Open the file to upload
    FILE *file_in;
    if ((file_in = fopen(file_name_in, "rb")) == NULL) {
        perror("Error opening file to upload");
        exit(EXIT_FAILURE);
    }

    // Read file data and send to server
    while (1) {
        size_t read_bytes = fread(buff, 1, MAX_BUFF_SIZE, file_in);
        if (read_bytes == 0)
            break;
        if (send(client_socket, buff, read_bytes, 0) != read_bytes) {
            perror("Error sending file data to server");
            exit(EXIT_FAILURE);
        }
    }

    // Close the file and print upload message
    fclose(file_in);
    printf("File \"%s\" upload completed\n", file_name_in);

    // Download file
    sprintf(buff, "RETR %s\r\n", file_name_out);
    send(client_socket, buff, strlen(buff), 0);

    // Open the file to download
    FILE *file_out;
    if ((file_out = fopen(file_name_out, "wb")) == NULL) {
        perror("Error opening file to download");
        exit(EXIT_FAILURE);
    }

    // Read file data and save to disk
    while (1) {
        ssize_t read_bytes = recv(client_socket, buff, MAX_BUFF_SIZE, 0);
        if (read_bytes == 0)
            break;
        fwrite(buff, 1, read_bytes, file_out);
    }

    // Close the file and print download message
    fclose(file_out);
    printf("File \"%s\" download completed\n", file_name_out);

    // Disconnect
    close(client_socket);

    return 0;
}