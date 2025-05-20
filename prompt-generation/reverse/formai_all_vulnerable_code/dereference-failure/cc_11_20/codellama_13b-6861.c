//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: active
// ftpclient.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc < 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        perror("inet_pton()");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect()");
        return 1;
    }

    // Send the USER and PASS commands
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", argv[3]);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send()");
        return 1;
    }
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", argv[4]);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send()");
        return 1;
    }

    // Send the RETR command
    snprintf(buffer, sizeof(buffer), "RETR %s\r\n", argv[5]);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send()");
        return 1;
    }

    // Receive the file
    int file_size;
    if (recv(sock, &file_size, sizeof(file_size), 0) < 0) {
        perror("recv()");
        return 1;
    }
    char *file_data = malloc(file_size);
    if (recv(sock, file_data, file_size, 0) < 0) {
        perror("recv()");
        return 1;
    }

    // Save the file to disk
    FILE *file = fopen(argv[6], "wb");
    if (file == NULL) {
        perror("fopen()");
        return 1;
    }
    fwrite(file_data, file_size, 1, file);
    fclose(file);

    // Close the socket
    close(sock);

    return 0;
}