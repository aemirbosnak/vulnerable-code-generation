//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <dirent.h>

#define BUFFER_SIZE 1024
#define PORT 21

void list_files(int sock);
void upload_file(int sock);
void download_file(int sock);
void connect_to_ftp(const char *hostname);
void execute_command(int sock, const char *command);

int main() {
    char hostname[100];

    printf("Enter FTP server hostname or IP address: ");
    scanf("%s", hostname);

    connect_to_ftp(hostname);

    return 0;
}

void connect_to_ftp(const char *hostname) {
    int sock;
    struct sockaddr_in server_address;
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    read(sock, response, sizeof(response));
    printf("Server Response: %s\n", response);

    while (1) {
        printf("\nMenu:\n");
        printf("1. List files\n");
        printf("2. Upload file\n");
        printf("3. Download file\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_files(sock);
                break;
            case 2:
                upload_file(sock);
                break;
            case 3:
                download_file(sock);
                break;
            case 4:
                printf("Exiting FTP client.\n");
                close(sock);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
}

void list_files(int sock) {
    printf("Listing files...\n");
    execute_command(sock, "LIST");
}

void upload_file(int sock) {
    FILE *fp;
    char filename[100];
    char buffer[BUFFER_SIZE];

    printf("Enter the filename to upload: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (!fp) {
        perror("File open error");
        return;
    }

    // Send the STOR command
    sprintf(buffer, "STOR %s", filename);
    execute_command(sock, buffer);

    // Send file contents
    while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
        send(sock, buffer, sizeof(buffer), 0);
    }
    printf("File uploaded successfully.\n");
    fclose(fp);
}

void download_file(int sock) {
    FILE *fp;
    char filename[100];
    char buffer[BUFFER_SIZE];

    printf("Enter the filename to download: ");
    scanf("%s", filename);

    fp = fopen(filename, "wb");
    if (!fp) {
        perror("File create error");
        return;
    }

    // Send the RETR command
    sprintf(buffer, "RETR %s", filename);
    execute_command(sock, buffer);

    // Receive file contents
    ssize_t bytes_received;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }
    printf("File downloaded successfully.\n");
    fclose(fp);
}

void execute_command(int sock, const char *command) {
    char buffer[BUFFER_SIZE];

    send(sock, command, strlen(command), 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server Response: %s\n", buffer);
}