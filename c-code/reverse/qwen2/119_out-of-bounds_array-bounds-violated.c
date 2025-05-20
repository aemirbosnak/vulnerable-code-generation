#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char filename[256];

    if (argc != 3) {
        fprintf(stderr,"Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Error opening socket");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection Failed");
    }

    printf("Enter filename to download: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    send(sockfd, filename, strlen(filename), 0);

    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        error("Unable to open file for writing");
    }

    while (1) {
        int n = read(sockfd, buffer, BUFFER_SIZE);
        if (n <= 0) break;
        fwrite(buffer, 1, n, fp);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}
