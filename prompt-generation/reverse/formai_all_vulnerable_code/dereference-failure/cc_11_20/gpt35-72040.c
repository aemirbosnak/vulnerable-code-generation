//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Mathematical Style FTP Client
int main(int argc, char* argv[]) {
    int data_socket, control_socket;
    char buffer[1024];

    // Create a socket for control connection
    if ((control_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in control_address = {0};
    control_address.sin_family = AF_INET;
    control_address.sin_addr.s_addr = inet_addr(argv[1]);
    control_address.sin_port = htons(atoi(argv[2]));

    // Connect to FTP server control port
    if (connect(control_socket, (struct sockaddr*)&control_address,
                sizeof(control_address))) {
        perror("connect");
        close(control_socket);
        exit(EXIT_FAILURE);
    }

    // Get FTP server response
    memset(buffer, 0, sizeof(buffer));
    if (recv(control_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        close(control_socket);
        exit(EXIT_FAILURE);
    }

    // Login to FTP server
    char username[1024], password[1024];
    memset(username, 0, sizeof(username));
    memset(password, 0, sizeof(password));
    printf("Enter username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    send(control_socket, buffer, strlen(buffer), 0);

    // Get FTP server response
    memset(buffer, 0, sizeof(buffer));
    if (recv(control_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        close(control_socket);
        exit(EXIT_FAILURE);
    }

    printf("Enter password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    send(control_socket, buffer, strlen(buffer), 0);

    // Get FTP server response
    memset(buffer, 0, sizeof(buffer));
    if (recv(control_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        close(control_socket);
        exit(EXIT_FAILURE);
    }

    // Get file from FTP server
    char filename[1024];
    printf("Enter filename: ");
    scanf("%s", filename);
    sprintf(buffer, "RETR %s\r\n", filename);
    send(control_socket, buffer, strlen(buffer), 0);

    // Get response from FTP server
    memset(buffer, 0, sizeof(buffer));
    if (recv(control_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        close(control_socket);
        exit(EXIT_FAILURE);
    }

    // Get data port from FTP server response
    int port = 0;
    char* pch = strtok(buffer, ",");
    pch = strtok(NULL, ",");
    pch = strtok(NULL, ",");
    pch = strtok(NULL, ",");
    int h1 = atoi(pch);
    pch = strtok(NULL, ",");
    int h2 = atoi(pch);
    port = h1 * 256 + h2;

    // Connect to FTP server data port
    if ((data_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        close(control_socket);
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in data_address = {0};
    data_address.sin_family = AF_INET;
    data_address.sin_addr.s_addr = inet_addr(argv[1]);
    data_address.sin_port = htons(port);
    if (connect(data_socket, (struct sockaddr*)&data_address,
                sizeof(data_address))) {
        perror("connect");
        close(control_socket);
        exit(EXIT_FAILURE);
    }

    // Open file for writing
    int file = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0600);
    if (file < 0) {
        perror("open");
        close(control_socket);
        close(data_socket);
        exit(EXIT_FAILURE);
    }

    // Get file from FTP server
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytes_received;
    while ((bytes_received = recv(data_socket, buffer, sizeof(buffer), 0)) > 0) {
        if (write(file, buffer, bytes_received) < 0) {
            perror("write");
            close(control_socket);
            close(data_socket);
            close(file);
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, sizeof(buffer));
    }
    close(file);

    // Close FTP server data connection
    close(data_socket);

    // Quit FTP server
    sprintf(buffer, "QUIT\r\n");
    send(control_socket, buffer, strlen(buffer), 0);

    // Get response from FTP server
    memset(buffer, 0, sizeof(buffer));
    if (recv(control_socket, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        close(control_socket);
        exit(EXIT_FAILURE);
    }

    // Close FTP server control connection
    close(control_socket);
    return 0;
}