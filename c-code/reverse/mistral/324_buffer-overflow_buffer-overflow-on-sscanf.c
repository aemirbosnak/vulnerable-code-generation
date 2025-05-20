#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char filename[256];

    if (argc != 3) {
        printf("Usage: %s <server> <file>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    write(sockfd, argv[2], strlen(argv[2]) + 1);

    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n > 0) {
        sscanf(buffer, "%s %*s %*d", filename);
        printf("Downloading %s\n", filename);

        FILE *fp = fopen(filename, "wb");
        while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
            fwrite(buffer, 1, n, fp);
        }
        fclose(fp);
    }

    close(sockfd);
    return 0;
}
