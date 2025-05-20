//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        error("Error receiving response");
    }
    buffer[n] = '\0';
    printf("%s", buffer);
}

int connect_ftp(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("No such host");
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    receive_response(sockfd);  // Receive initial response
    return sockfd;
}

void list_files(int sockfd) {
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);
}

void download_file(int sockfd, const char *filename) {
    char command[30];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *filename = argv[2];

    int sockfd = connect_ftp(hostname);
    
    // Additional commands to authenticate/aquire information as needed
    // To be done here, if necessary...
    
    printf("Fetching file list...\n");
    list_files(sockfd);
    
    printf("Downloading file: %s\n", filename);
    download_file(sockfd, filename);

    close(sockfd);
    return 0;
}