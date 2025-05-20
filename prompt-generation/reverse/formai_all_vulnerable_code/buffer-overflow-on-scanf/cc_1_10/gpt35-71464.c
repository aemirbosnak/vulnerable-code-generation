//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#define FTP_PORT 21
#define MAX_RESPONSE_LENGTH 1024
#define MAX_COMMAND_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256
#define BUFFER_SIZE 256

void error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, const char* argv[]) {

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        error("Could not create socket");
    }

    // Connect to server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(FTP_PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        error("Could not connect to server");
    }

    // Receive welcome message
    char response[MAX_RESPONSE_LENGTH];
    memset(response, 0, MAX_RESPONSE_LENGTH);

    if (recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0) == -1) {
        error("Could not receive welcome message");
    }

    printf("Connected to server: %s", response);

    // Login
    char username[MAX_COMMAND_LENGTH] = "USER anonymous\r\n";
    char password[MAX_COMMAND_LENGTH] = "PASS anonymous\r\n";

    if (send(socket_fd, username, strlen(username), 0) == -1) {
        error("Could not send username");
    }

    if (recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0) == -1) {
        error("Could not receive response to username");
    }

    if (send(socket_fd, password, strlen(password), 0) == -1) {
        error("Could not send password");
    }

    if (recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0) == -1) {
        error("Could not receive response to password");
    }

    printf("Logged in to server: %s", response);

    // Download file
    char get_command[MAX_COMMAND_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    char buffer[BUFFER_SIZE];
    memset(file_name, 0, MAX_FILE_NAME_LENGTH);

    printf("Enter the name of the file you want to download:\n");
    scanf("%s", file_name);

    sprintf(get_command, "RETR %s\r\n", file_name);

    if (send(socket_fd, get_command, strlen(get_command), 0) == -1) {
        error("Could not send download command");
    }

    // Receive file and save to disk
    int file_fd = open(file_name, O_CREAT | O_WRONLY, 0644);
    int bytes_received;

    while ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        if (write(file_fd, buffer, bytes_received) == -1) {
            error("Could not write file to disk");
        }
    }

    close(file_fd);
    printf("Finished downloading file %s\n", file_name);

    // Cleanup
    close(socket_fd);
    return 0;
}