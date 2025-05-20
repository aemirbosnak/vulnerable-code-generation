//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
// FTP client using a decentralized approach
// Written by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

// Function prototypes
void downloadFileFromServer(int sock, char* filename);
void uploadFileToServer(int sock, char* filename);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server_ip_addr> <server_port>\n", argv[0]);
        exit(1);
    }

    // Parse command line arguments
    char* server_ip_addr = argv[1];
    int server_port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Set up server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip_addr);
    server_addr.sin_port = htons(server_port);

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // Command loop
    char command[MAX_BUFFER_SIZE];
    while (1) {
        printf("Enter command (d/u/q): ");
        scanf("%s", command);

        // Download file from server
        if (strcmp(command, "d") == 0) {
            char filename[MAX_BUFFER_SIZE];
            printf("Enter filename to download: ");
            scanf("%s", filename);

            // Send download command to server
            char cmd[MAX_BUFFER_SIZE];
            sprintf(cmd, "d %s\n", filename);
            send(sock, cmd, strlen(cmd), 0);

            // Receive file from server
            downloadFileFromServer(sock, filename);
        }
        // Upload file to server
        else if (strcmp(command, "u") == 0) {
            char filename[MAX_BUFFER_SIZE];
            printf("Enter filename to upload: ");
            scanf("%s", filename);

            // Send upload command to server
            char cmd[MAX_BUFFER_SIZE];
            sprintf(cmd, "u %s\n", filename);
            send(sock, cmd, strlen(cmd), 0);

            // Upload file to server
            uploadFileToServer(sock, filename);
        }
        // Quit
        else if (strcmp(command, "q") == 0) {
            printf("Quitting...\n");
            break;
        }
        // Invalid command
        else {
            printf("Invalid command.\n");
        }
    }

    // Close socket
    close(sock);

    return 0;
}

// Function to download file from server
void downloadFileFromServer(int sock, char* filename) {
    printf("Downloading file %s...\n", filename);

    // Open file for writing
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Receive file contents from server
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }

    // Close file
    fclose(fp);

    printf("File downloaded successfully.\n");
}

// Function to upload file to server
void uploadFileToServer(int sock, char* filename) {
    printf("Uploading file %s...\n", filename);

    // Open file for reading
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Send file contents to server
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {
        send(sock, buffer, bytes_read, 0);
    }

    // Close file
    fclose(fp);

    printf("File uploaded successfully.\n");
}