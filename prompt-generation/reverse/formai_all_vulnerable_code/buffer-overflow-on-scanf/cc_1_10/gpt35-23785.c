//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Function for handling FTP commands
void handle_command(int sock_fd, char* cmd) {
    char buffer[1024];
    int bytes;

    // Send command to server
    send(sock_fd, cmd, strlen(cmd), 0);

    // Receive response from server
    bytes = recv(sock_fd, buffer, 1024, 0);
    buffer[bytes] = '\0';

    // Print response from server
    printf("%s", buffer);
}

int main(int argc, char* argv[]) {
    int sock_fd, bytes;
    struct sockaddr_in server_addr;

    char username[100], password[100], command[100], filename[100];
    char buffer[1024];

    // Get username and password from user
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(21);

    // Connect to server
    connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Receive welcome message from server
    bytes = recv(sock_fd, buffer, 1024, 0);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // Send username to server
    sprintf(command, "USER %s\r\n", username);
    handle_command(sock_fd, command);

    // Send password to server
    sprintf(command, "PASS %s\r\n", password);
    handle_command(sock_fd, command);

    // Enter passive mode
    handle_command(sock_fd, "PASV\r\n");

    // Send LIST command to server
    handle_command(sock_fd, "LIST\r\n");

    // Receive directory listing from server
    bytes = recv(sock_fd, buffer, 1024, 0);
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // Download file from server
    printf("Enter filename to download: ");
    scanf("%s", filename);

    // Enter passive mode
    handle_command(sock_fd, "PASV\r\n");

    // Send RETR command to server
    sprintf(command, "RETR %s\r\n", filename);
    handle_command(sock_fd, command);

    // Create file to save downloaded content to
    FILE* file = fopen(filename, "w");

    // Receive data from server and save it to file
    while ((bytes = recv(sock_fd, buffer, 1024, 0)) > 0) {
        fwrite(buffer, 1, bytes, file);
    }

    // Close file
    fclose(file);

    // Disconnect from server
    handle_command(sock_fd, "QUIT\r\n");

    return 0;
}