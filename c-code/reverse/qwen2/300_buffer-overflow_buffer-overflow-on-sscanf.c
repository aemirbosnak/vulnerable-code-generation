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
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server_ip> <port> <username> <filename>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[2]);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    send(sock, "USER ", 5, 0);
    send(sock, argv[3], strlen(argv[3]), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    sscanf(buffer, "%*s %d", &port);

    send(sock, "PASS ", 5, 0);
    send(sock, argv[4], strlen(argv[4]), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    sscanf(buffer, "%*s %d", &port);

    send(sock, "RETR ", 5, 0);
    send(sock, argv[4], strlen(argv[4]), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    sscanf(buffer, "%*s %d", &port);

    FILE *local_file = fopen("downloaded.txt", "wb");
    while (recv(sock, buffer, BUFFER_SIZE, 0) > 0) {
        fwrite(buffer, 1, BUFFER_SIZE, local_file);
    }
    fclose(local_file);

    close(sock);
    return 0;
}
