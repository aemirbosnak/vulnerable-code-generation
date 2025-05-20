//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>

#define PORT 21
#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int socketfd;
    struct sockaddr_in server_address;
    char buffer[MAXSIZE], username[MAXSIZE], password[MAXSIZE];
    char *host = argv[1];
    char *file_name = argv[2];
    int len, bytes_received;

    // Create socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Fill server details
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(host);

    // Connect to server
    if (connect(socketfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s\n", host);

    // Receive welcome message
    bytes_received = recv(socketfd, buffer, MAXSIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send username
    printf("Enter username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    send(socketfd, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(socketfd, buffer, MAXSIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Send password
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    send(socketfd, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(socketfd, buffer, MAXSIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Set transfer mode to binary
    sprintf(buffer, "TYPE I\r\n");
    send(socketfd, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(socketfd, buffer, MAXSIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Set transfer mode to passive
    sprintf(buffer, "pasv\r\n");
    send(socketfd, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(socketfd, buffer, MAXSIZE, 0);
    buffer[bytes_received] = '\0';
    printf("PASV response: %s", buffer);

    // Extract port number and IP address
    char *ip_address_str, *port_num_str;
    char *start = strstr(buffer, "(");
    char *end = strstr(buffer, ")");
    *end = '\0';
    char *comma = strrchr(start, ',');
    comma++;
    asprintf(&port_num_str, "%d", atoi(comma) * 256);
    *comma = '\0';
    asprintf(&ip_address_str, "%s%c%c%c%s", start + 1, '.', '.', '.', comma - 3);

    // Connect to data channel
    struct sockaddr_in data_address;
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(atoi(port_num_str));
    data_address.sin_addr.s_addr = inet_addr(ip_address_str);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    if (connect(fd, (struct sockaddr *)&data_address, sizeof(data_address)) < 0) {
        perror("Error connecting to data channel");
        exit(EXIT_FAILURE);
    }

    printf("Connected to data channel\n");

    // Download file
    sprintf(buffer, "RETR %s\r\n", file_name);
    send(socketfd, buffer, strlen(buffer), 0);

    // Receive response
    bytes_received = recv(socketfd, buffer, MAXSIZE, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Read data from data channel and write to file
    int file_fd = open(file_name, O_WRONLY | O_CREAT, 0666);
    while ((len = recv(fd, buffer, MAXSIZE, 0)) > 0) {
        write(file_fd, buffer, len);
    }

    // Close data channel, file and socket
    close(fd);
    close(file_fd);
    close(socketfd);

    printf("Downloaded file %s\n", file_name);

    return 0;
}