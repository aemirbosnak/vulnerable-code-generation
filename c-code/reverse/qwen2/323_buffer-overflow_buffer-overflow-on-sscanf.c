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
        fprintf(stderr, "Usage: %s <server_ip> <file_name>\n", argv[0]);
        return 1;
    }

    int server_port = 21; // FTP default port
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return 1;
    }

    FILE *fp = fopen(argv[2], "wb");
    if (!fp) {
        perror("File opening failed");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = read(sock, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);
    close(sock);

    printf("File downloaded successfully.\n");

    return 0;
}
