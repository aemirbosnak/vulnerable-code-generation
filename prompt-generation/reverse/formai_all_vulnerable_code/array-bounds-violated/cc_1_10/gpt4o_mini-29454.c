//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0); // End the command with CRLF
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0'; // Null terminate the buffer
        printf("%s", buffer);
        if (strstr(buffer, "226") || strstr(buffer, "250")) break; // Success responses
    }
}

void login(int sockfd, const char *user, const char *pass) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "USER %s", user);
    send_command(sockfd, buffer);
    receive_response(sockfd);

    snprintf(buffer, sizeof(buffer), "PASS %s", pass);
    send_command(sockfd, buffer);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV");
    receive_response(sockfd);
    
    // Here we would need to parse the response to get the data connection parameters
    // For simplicity, we'll omit the full implementation of data connection logic.

    send_command(sockfd, "LIST");
    receive_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    send_command(sockfd, "RETR");
    send_command(sockfd, filename);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <USERNAME> <PASSWORD>\n", argv[0]);
        exit(1);
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_server(server_ip, 21); // FTP default port is 21
    receive_response(sockfd);
    
    login(sockfd, username, password);
    
    printf("\nListing files:\n");
    list_files(sockfd);
    
    // Uncomment to download a specific file
    // download_file(sockfd, "file_to_download.txt");

    close(sockfd);
    return 0;
}