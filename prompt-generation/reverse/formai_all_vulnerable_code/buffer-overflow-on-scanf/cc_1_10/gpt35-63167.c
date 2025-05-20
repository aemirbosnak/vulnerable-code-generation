//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, port;
    struct sockaddr_in servaddr;
    char buff[MAXSIZE], filename[MAXSIZE];
    FILE *fp;

    if (argc != 3) {
        printf("Usage: %s [IP address] [Port number]\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    port = atoi(argv[2]);
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection error");
        exit(1);
    }

    printf("Connected to the server.\n");
    printf("Enter the name of the file you want to download: ");
    scanf("%s", filename);

    write(sockfd, filename, strlen(filename)+1);

    if ((fp = fopen(filename, "wb")) == NULL) {
        perror("File create error");
        exit(1);
    }

    bzero(buff, MAXSIZE);
    while ((n = read(sockfd, buff, MAXSIZE)) > 0) {
        fwrite(buff, sizeof(char), n, fp);
        bzero(buff, MAXSIZE);
    }

    printf("File downloaded successfully.\n");

    close(sockfd);
    fclose(fp);

    return 0;
}