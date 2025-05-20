//FormAI DATASET v1.0 Category: Networking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>

#define BUF_SIZE 128

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sock_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);

    printf("Connected to server.\n");

    while (1) {
        printf("Enter a message: ");
        fgets(buffer, BUF_SIZE, stdin);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
            perror("send() failed");
            exit(EXIT_FAILURE);
        }

        int bytes_read = recv(sock_fd, buffer, BUF_SIZE, 0);

        if (bytes_read < 0) {
            perror("recv() failed");
            exit(EXIT_FAILURE);
        }

        buffer[bytes_read] = '\0';

        printf("Server response: %s", buffer);
    }

    close(sock_fd);

    return 0;

}