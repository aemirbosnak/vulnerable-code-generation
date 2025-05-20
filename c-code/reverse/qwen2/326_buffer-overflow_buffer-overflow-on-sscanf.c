#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void download_file(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
}

int main() {
    int sockfd;
    char filename[256], filesize_str[256];
    unsigned long filesize;

    // Simulate connection setup
    sockfd = 1234; // Replace with actual socket creation and connection logic

    // Receive file name and size
    if (read(sockfd, filename, sizeof(filename) - 1) <= 0) {
        perror("Failed to receive file name");
        return EXIT_FAILURE;
    }

    if (read(sockfd, filesize_str, sizeof(filesize_str) - 1) <= 0) {
        perror("Failed to receive file size");
        return EXIT_FAILURE;
    }

    // Vulnerable sscanf call
    sscanf(filesize_str, "%lu", &filesize);

    // Download file
    printf("Downloading %s (%lu bytes)\n", filename, filesize);
    download_file(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}
