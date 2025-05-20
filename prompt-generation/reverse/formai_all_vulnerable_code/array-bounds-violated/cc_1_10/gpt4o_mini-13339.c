//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    } else {
        error("ERROR reading response");
    }
}

void list_files(int sockfd) {
    send_command(sockfd, "USER anonymous");
    receive_response(sockfd);
    send_command(sockfd, "PASS guest@example.com");
    receive_response(sockfd);
    send_command(sockfd, "PASV");
    receive_response(sockfd);
    send_command(sockfd, "LIST");
    receive_response(sockfd);
    send_command(sockfd, "QUIT");
    receive_response(sockfd);
}

void upload_file(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        error("ERROR opening file");
    }

    send_command(sockfd, "USER anonymous");
    receive_response(sockfd);
    send_command(sockfd, "PASS guest@example.com");
    receive_response(sockfd);
    
    send_command(sockfd, "PASV");
    receive_response(sockfd); // Simplified, you would need to get port from response

    // Sending the STOR command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "STOR %s", filename);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Read and send the file
    char buffer[BUFFER_SIZE];
    int n;
    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(sockfd, buffer, n, 0);
    }

    fclose(file);
    send_command(sockfd, "QUIT");
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *filename = argv[2];

    int sockfd = connect_to_server(hostname);
    
    printf("Connected to FTP server %s...\n", hostname);
    printf("Listing Files:\n");
    list_files(sockfd);

    printf("Uploading file: %s...\n", filename);
    upload_file(sockfd, filename);

    close(sockfd);
    return 0;
}