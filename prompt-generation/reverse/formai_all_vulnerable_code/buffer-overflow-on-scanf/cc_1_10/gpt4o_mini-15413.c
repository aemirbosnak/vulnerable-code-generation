//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 21
#define BUFFER_SIZE 1024

void print_menu() {
    printf("\n🎉 Welcome to the Cheerful FTP Client! 🎉\n");
    printf("Choose an action:\n");
    printf("1. Connect to FTP Server\n");
    printf("2. List Files\n");
    printf("3. Download a File\n");
    printf("4. Upload a File\n");
    printf("5. Exit\n");
}

int connect_to_server(char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed!");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed!");
        close(sockfd);
        return -1;
    }
    printf("🎉 Connected to %s on port %d 🎉\n", hostname, PORT);
    return sockfd;
}

void list_files(int sockfd) {
    // Example request to LIST files
    char *request = "LIST\r\n";
    send(sockfd, request, strlen(request), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }
}

void download_file(int sockfd, char *filename) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "RETR %s\r\n", filename);
    send(sockfd, request, strlen(request), 0);

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("File creation failed!");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        fwrite(buffer, sizeof(char), bytes_received, fp);
    }
    fclose(fp);
    printf("🎉 Successfully downloaded %s! 🎉\n", filename);
}

void upload_file(int sockfd, char *filename) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "STOR %s\r\n", filename);
    send(sockfd, request, strlen(request), 0);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("File opening failed!");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (!feof(fp)) {
        int bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp);
        send(sockfd, buffer, bytes_read, 0);
    }
    fclose(fp);
    printf("🎉 Successfully uploaded %s! 🎉\n", filename);
}

int main() {
    char hostname[100];
    int sockfd = -1;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter server hostname or IP: ");
                scanf("%s", hostname);
                sockfd = connect_to_server(hostname);
                break;
                
            case 2:
                if (sockfd >= 0) {
                    list_files(sockfd);
                } else {
                    printf("😢 Please connect to a server first!\n");
                }
                break;

            case 3:
                if (sockfd >= 0) {
                    char filename[100];
                    printf("Enter file name to download: ");
                    scanf("%s", filename);
                    download_file(sockfd, filename);
                } else {
                    printf("😢 Please connect to a server first!\n");
                }
                break;

            case 4:
                if (sockfd >= 0) {
                    char filename[100];
                    printf("Enter file name to upload: ");
                    scanf("%s", filename);
                    upload_file(sockfd, filename);
                } else {
                    printf("😢 Please connect to a server first!\n");
                }
                break;

            case 5:
                if (sockfd >= 0) {
                    close(sockfd);
                    printf("👋 Exiting the FTP Client. Goodbye! 👋\n");
                }
                exit(0);

            default:
                printf("😕 Invalid choice, please try again!\n");
        }
    }
    return 0;
}