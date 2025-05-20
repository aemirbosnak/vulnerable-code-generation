//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Error creating socket");
    }
    return sockfd;
}

void connect_to_server(int sockfd, const char *server_ip, int server_port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address or address not supported");
    }
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "226") || strstr(buffer, "250"))
            break; // Transfer finished
    }
    if (bytes_received < 0) {
        handle_error("Error receiving response");
    }
}

void list_files(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        handle_error("Error opening file for writing");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, file);
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <port> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    const char *filename = argv[3];

    int sockfd = create_socket();
    connect_to_server(sockfd, server_ip, server_port);

    // Receive welcome message
    receive_response(sockfd);

    printf("Listing files:\n");
    list_files(sockfd);

    printf("Downloading file: %s\n", filename);
    download_file(sockfd, filename);

    printf("File downloaded successfully.\n");

    close(sockfd);
    return 0;
}