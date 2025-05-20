#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <file_path>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return 1;
    }

    send(sockfd, "USER anonymous\r\n", 15, 0);
    send(sockfd, "PASS anonymous\r\n", 14, 0);
    send(sockfd, "CWD /\r\n", 7, 0);
    send(sockfd, "RETR ", 5, 0);
    send(sockfd, argv[2], strlen(argv[2]), 0);
    send(sockfd, "\r\n", 2, 0);

    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    int file_size = atoi(buffer + 5);

    FILE *fp = fopen("downloaded_file", "wb");
    if (!fp) {
        perror("File opening failed");
        return 1;
    }

    while (file_size > 0) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) break;
        fwrite(buffer, 1, bytes_received, fp);
        file_size -= bytes_received;
    }

    fclose(fp);
    close(sockfd);
    return 0;
}
