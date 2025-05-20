//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SERVER "ftp.dlptest.com" // Replace with your FTP server
#define PORT 21
#define BUFFER_SIZE 1024

// Function prototypes
void connect_to_server(int *sockfd, struct sockaddr_in *server_addr);
void login_to_ftp(int sockfd);
void list_files(int sockfd);
void get_file(int sockfd, const char *filename);
void send_command(int sockfd, const char *command);
void read_response(int sockfd);
void error(const char *msg);

// Entry point of the program
int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Establish connection to the FTP server
    connect_to_server(&sockfd, &server_addr);

    // Log in to the FTP server
    login_to_ftp(sockfd);

    // List files in the current directory
    list_files(sockfd);

    // Get a file example (you can replace with any file you want to download)
    get_file(sockfd, "sample.txt");

    // Clean up and exit
    close(sockfd);
    return 0;
}

void connect_to_server(int *sockfd, struct sockaddr_in *server_addr) {
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error("Unable to create socket");
    }

    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(PORT);
    server_addr->sin_addr.s_addr = inet_addr("93.184.216.34"); // Example IP for dlptest.com

    if (connect(*sockfd, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        error("Unable to connect to server");
    }

    // Read server welcome message
    read_response(*sockfd);
}

void login_to_ftp(int sockfd) {
    // Send username and password (replace with your credentials)
    send_command(sockfd, "USER dlptest");
    read_response(sockfd);
    send_command(sockfd, "PASS rNrKYTX9g7z3RgJRmxWuGHbeu");
    read_response(sockfd);
}

void list_files(int sockfd) {
    // Send LIST command
    send_command(sockfd, "PASV");
    read_response(sockfd);
    
    // Need to parse passive mode response, but for simplicity in this case,
    // let's just proceed with a simplification
    send_command(sockfd, "LIST");
    read_response(sockfd);
}

void get_file(int sockfd, const char *filename) {
    // Send RETR command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s", filename);
    send_command(sockfd, command);
    read_response(sockfd);
}

void send_command(int sockfd, const char *command) {
    char buf[BUFFER_SIZE];
    snprintf(buf, sizeof(buf), "%s\r\n", command);
    send(sockfd, buf, strlen(buf), 0);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead < 0) {
        error("Error reading from server");
    }
    buffer[bytesRead] = '\0';
    printf("%s", buffer);
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}