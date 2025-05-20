//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
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

    // Get the IP address of the FTP server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    // Connect to the FTP server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command to the FTP server.
    char user_cmd[100];
    sprintf(user_cmd, "USER anonymous\r\n");
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    char response[100];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the PASS command to the FTP server.
    char pass_cmd[100];
    sprintf(pass_cmd, "PASS anonymous@example.com\r\n");
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the CWD command to the FTP server.
    char cwd_cmd[100];
    sprintf(cwd_cmd, "CWD /pub\r\n");
    if (send(sockfd, cwd_cmd, strlen(cwd_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RETR command to the FTP server.
    char retr_cmd[100];
    sprintf(retr_cmd, "RETR %s\r\n", filename);
    if (send(sockfd, retr_cmd, strlen(retr_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the FTP server.
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Open a file for writing.
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Receive the file data from the FTP server.
    char buffer[1024];
    while (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
    }

    // Close the file.
    fclose(fp);

    // Send the QUIT command to the FTP server.
    char quit_cmd[100] = "QUIT\r\n";
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}