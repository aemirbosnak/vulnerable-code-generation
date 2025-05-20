//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define DEFAULT_PORT 21
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host and file name from the command line arguments
    char *host = argv[1];
    char *file = argv[2];

    // Create a socket for communication with the FTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve the host name to an IP address
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure for the FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to the FTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command to the FTP server
    char buf[MAX_BUF_SIZE];
    sprintf(buf, "USER anonymous\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the PASS command to the FTP server
    sprintf(buf, "PASS anonymous@example.com\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the TYPE command to the FTP server
    sprintf(buf, "TYPE I\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RETR command to the FTP server
    sprintf(buf, "RETR %s\r\n", file);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Open a file for writing the data received from the FTP server
    FILE *fp = fopen(file, "wb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the data from the FTP server and write it to the file
    int bytes_received;
    do {
        bytes_received = recv(sock, buf, MAX_BUF_SIZE, 0);
        if (bytes_received < 0) {
            perror("recv");
            return EXIT_FAILURE;
        } else if (bytes_received > 0) {
            fwrite(buf, 1, bytes_received, fp);
        }
    } while (bytes_received > 0);

    // Close the file
    fclose(fp);

    // Send the QUIT command to the FTP server
    sprintf(buf, "QUIT\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}