//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char server_ip[20];
    int server_port, sockfd, n, option, filename_len;
    char buffer[BUFFER_SIZE], filename[BUFFER_SIZE], server_response[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // Take input of server IP address and port number
    printf("Enter server IP address: ");
    scanf("%s", server_ip);
    printf("Enter server port number: ");
    scanf("%d", &server_port);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address and port 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(server_port); 
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not connect to server.\n");
        exit(1);
    }

    // Display menu of options
    printf("\n\n");
    printf("1. Upload file to server\n");
    printf("2. Download file from server\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    if (option == 1) {
        // Upload file to server
        printf("Enter file name to upload: ");
        scanf("%s", filename);
        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Could not open file.\n");
            exit(1);
        }
        // Send file name to server
        filename_len = strlen(filename);
        write(sockfd, &filename_len, sizeof(int));
        write(sockfd, filename, filename_len);
        // Send file contents to server
        while ((n = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
            write(sockfd, buffer, n);
        }
        fclose(fp);
        // Receive response from server
        memset(server_response, 0, BUFFER_SIZE);
        read(sockfd, server_response, BUFFER_SIZE);
        printf("%s", server_response);
    } else if (option == 2) {
        // Download file from server
        printf("Enter file name to download: ");
        scanf("%s", filename);
        // Send file name to server
        filename_len = strlen(filename);
        write(sockfd, &filename_len, sizeof(int));
        write(sockfd, filename, filename_len);
        // Receive file contents from server
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE);
        FILE *fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Could not create file.\n");
            exit(1);
        }
        fwrite(buffer, 1, n, fp);
        fclose(fp);
        printf("File downloaded successfully.\n");
    } else {
        printf("Invalid option.\n");
    }

    // Close socket
    close(sockfd);

    return 0;
}