#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void download_file(int sockfd, const char *filename) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    while ((bytes_read = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytes_read, file);
    }

    fclose(file);
}

int main() {
    struct sockaddr_in server_addr;
    int sockfd;
    char filename[256];

    printf("Enter server IP address: ");
    scanf("%s", server_addr.sin_addr.s_addr);
    printf("Enter server port: ");
    scanf("%d", &server_addr.sin_port);
    printf("Enter file name to download: ");
    scanf("%s", filename);

    server_addr.sin_family = AF_INET;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    send(sockfd, "GET /path/to/file HTTP/1.1\r\nHost: example.com\r\n\r\n", strlen("GET /path/to/file HTTP/1.1\r\nHost: example.com\r\n\r\n"), 0);

    char response[BUFFER_SIZE];
    if (read(sockfd, response, BUFFER_SIZE) <= 0) {
        perror("Failed to receive response from server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char content_length_str[256];
    if (sscanf(response, "Content-Length: %s", content_length_str) != 1) {
        fprintf(stderr, "Failed to parse Content-Length header\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    long content_length = atol(content_length_str);
    printf("File size: %ld bytes\n", content_length);

    download_file(sockfd, filename);

    close(sockfd);
    return 0;
}
