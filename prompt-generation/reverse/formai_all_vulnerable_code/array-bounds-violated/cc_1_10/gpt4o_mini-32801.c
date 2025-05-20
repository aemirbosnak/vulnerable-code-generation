//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void ftp_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("ERROR: Failed to send command");
    }
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if (n < 0) {
        error("ERROR: Failed to read response");
    }
    buffer[n] = '\0';
    printf("Server Response: %s", buffer);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username); 
    ftp_command(sockfd, command);
    read_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password); 
    ftp_command(sockfd, command);
    read_response(sockfd);
}

void ftp_list(int sockfd) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "PASV\r\n"); 
    ftp_command(sockfd, command);
    read_response(sockfd);

    // In practice, you'd have to parse response for the data port here
    snprintf(command, sizeof(command), "LIST\r\n"); 
    ftp_command(sockfd, command);
    read_response(sockfd);
}

void ftp_download_file(int sockfd, const char *filename) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename); 
    ftp_command(sockfd, command);
    read_response(sockfd);

    // Here you would handle downloading and saving the file
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(FTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    read_response(sockfd);
    ftp_login(sockfd, username, password);
    ftp_list(sockfd);

    // Uncomment the following line to download a specific file
    // ftp_download_file(sockfd, "<filename>");

    close(sockfd);
    return 0;
}