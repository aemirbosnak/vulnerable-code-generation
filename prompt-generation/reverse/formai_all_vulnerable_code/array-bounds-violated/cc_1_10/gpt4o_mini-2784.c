//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void handle_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char* command) {
    send(sockfd, command, strlen(command), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        handle_error("Error receiving response");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void connect_to_server(const char* hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Could not create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Could not connect to server");
    }

    receive_response(sockfd);
    
    // Insert login details (for anonymous access)
    send_command(sockfd, "USER anonymous\r\n");
    receive_response(sockfd);
    send_command(sockfd, "PASS user@example.com\r\n");
    receive_response(sockfd);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // Placeholder for PASV command response parsing
    // Assume data connection established (in practice, you'd parse the response)

    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void download_file(int sockfd, const char* filename) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void upload_file(int sockfd, const char* filename) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "STOR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Assuming file sending logic occurs here
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ftp_server_ip>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* hostname = argv[1];
    int sockfd;

    connect_to_server(hostname);
    
    // Begin a peaceful session of choices
    printf("Welcome to the FTP client. What would you like to do?\n");
    printf("1. List files\n");
    printf("2. Download a file\n");
    printf("3. Upload a file\n");
    printf("4. Exit\n");

    int choice;
    char filename[BUFFER_SIZE];

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_files(sockfd);
                break;
            case 2:
                printf("Enter the filename to download: ");
                scanf("%s", filename);
                download_file(sockfd, filename);
                break;
            case 3:
                printf("Enter the filename to upload: ");
                scanf("%s", filename);
                upload_file(sockfd, filename);
                break;
            case 4:
                close(sockfd);
                printf("Exiting peacefully. Goodbye!\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}