//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21
#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
    // Check if the correct number of arguments have been provided.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and filename from the command line arguments.
    char *hostname = argv[1];
    char *filename = argv[2];

    // Create a socket for connecting to the FTP server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Specify the address of the FTP server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command to the FTP server.
    char user_cmd[MAX_BUFFER_SIZE];
    snprintf(user_cmd, MAX_BUFFER_SIZE, "USER anonymous\r\n");
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    char user_resp[MAX_BUFFER_SIZE];
    if (recv(sockfd, user_resp, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the PASS command to the FTP server.
    char pass_cmd[MAX_BUFFER_SIZE];
    snprintf(pass_cmd, MAX_BUFFER_SIZE, "PASS anonymous@example.com\r\n");
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    char pass_resp[MAX_BUFFER_SIZE];
    if (recv(sockfd, pass_resp, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the TYPE command to the FTP server.
    char type_cmd[MAX_BUFFER_SIZE];
    snprintf(type_cmd, MAX_BUFFER_SIZE, "TYPE I\r\n");
    if (send(sockfd, type_cmd, strlen(type_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    char type_resp[MAX_BUFFER_SIZE];
    if (recv(sockfd, type_resp, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RETR command to the FTP server.
    char retr_cmd[MAX_BUFFER_SIZE];
    snprintf(retr_cmd, MAX_BUFFER_SIZE, "RETR %s\r\n", filename);
    if (send(sockfd, retr_cmd, strlen(retr_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    char retr_resp[MAX_BUFFER_SIZE];
    if (recv(sockfd, retr_resp, MAX_BUFFER_SIZE, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Open a file for writing the downloaded data.
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Receive the data from the FTP server and write it to the file.
    char buffer[MAX_BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            return EXIT_FAILURE;
        } else if (bytes_received == 0) {
            break;
        }

        fwrite(buffer, 1, bytes_received, fp);
    }

    // Close the file.
    fclose(fp);

    // Send the QUIT command to the FTP server.
    char quit_cmd[MAX_BUFFER_SIZE];
    snprintf(quit_cmd, MAX_BUFFER_SIZE, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}