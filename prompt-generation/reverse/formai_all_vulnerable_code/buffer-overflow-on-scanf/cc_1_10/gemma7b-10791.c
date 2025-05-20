//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
    int sockfd, port, n, i, len;
    char buf[1024], hostname[256], filename[256];
    struct sockaddr_in servaddr;

    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port: ");
    scanf("%d", &port);
    printf("Enter filename: ");
    scanf("%s", filename);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    n = send(sockfd, filename, strlen(filename), 0);
    if (n < 0) {
        perror("Error sending file name");
        exit(1);
    }

    len = recv(sockfd, buf, 1024, 0);
    if (len < 0) {
        perror("Error receiving file size");
        exit(1);
    }

    printf("File size: %d bytes\n", len);

    n = recv(sockfd, buf, len, 0);
    if (n < 0) {
        perror("Error receiving file data");
        exit(1);
    }

    FILE *fp = fopen(filename, "w");
    fwrite(buf, n, 1, fp);
    fclose(fp);

    close(sockfd);
    return 0;
}