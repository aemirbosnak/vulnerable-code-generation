//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: brave
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1024 * 1024

int main(int argc, char const *argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);

    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_sent;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        bytes_sent = send(sockfd, buffer, bytes_read, 0);
        if (bytes_sent < 0) {
            perror("Error sending data");
            fclose(file);
            close(sockfd);
            exit(EXIT_FAILURE);
        }
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("File sent to server\n");

    close(sockfd);

    return EXIT_SUCCESS;
}