//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void print_menu() {
    printf("Welcome to the Silly FTP Client!\n");
    printf("How may I tickle your FTP needs?\n");
    printf("1. Connect to FTP Server\n");
    printf("2. List Files\n");
    printf("3. Download a File\n");
    printf("4. Upload a File\n");
    printf("5. Exit\n");
}

void error_handling(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void connect_to_server(int *sockfd, const char *server_ip, int port) {
    struct sockaddr_in server_addr;

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error_handling("Socket creation failed! Did the socket get lost in the ether?");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Connection to server failed! Did the FTP server go on vacation?!");
    }

    printf("Yay! Successfully connected to the FTP server at %s:%d!\n", server_ip, port);
}

void list_files(int sockfd) {
    char buffer[BUFFER_SIZE];
    send(sockfd, "LIST\n", strlen("LIST\n"), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Here are the files on the FTP server:\n%s\n", buffer);
}

void download_file(int sockfd) {
    char filename[BUFFER_SIZE];
    printf("Enter the file name to download: ");
    scanf("%s", filename);
    
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\n", filename);
    send(sockfd, command, strlen(command), 0);
    
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        error_handling("Could not create file! Did you bring your magic wand?");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, file);
    }
    
    fclose(file);
    printf("File '%s' has been downloaded successfully! Go check it out!\n", filename);
}

void upload_file(int sockfd) {
    char filename[BUFFER_SIZE];
    printf("Enter the file name to upload: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        error_handling("Could not open file! Did it run away?");
    }

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "STOR %s\n", filename);
    send(sockfd, command, strlen(command), 0);
    
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        send(sockfd, buffer, bytes_read, 0);
    }
    
    fclose(file);
    printf("File '%s' has been successfully uploaded! You’re a digital magician!\n", filename);
}

int main() {
    int sockfd;
    char server_ip[BUFFER_SIZE];
    int port;

    print_menu();
    
    printf("What is the IP address of the FTP server? ");
    scanf("%s", server_ip);
    printf("What is the port number? (default 21): ");
    scanf("%d", &port);

    connect_to_server(&sockfd, server_ip, port);

    int choice;
    while (1) {
        print_menu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You are already connected! Nice job staying on topic!\n");
                break;
            case 2:
                list_files(sockfd);
                break;
            case 3:
                download_file(sockfd);
                break;
            case 4:
                upload_file(sockfd);
                break;
            case 5:
                close(sockfd);
                printf("Exiting... Maybe we'll meet again in cyberspace! Byeee!\n");
                return 0;
            default:
                printf("Oops! That’s not an option! Did you mean the option of eating pizza instead?\n");
        }
    }
    return 0;
}