//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct hostent *server;
    struct sockaddr_in serveraddr;
    char *host = argv[1];
    int port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        printf("ERROR opening socket\n");
        return 1;
    }

    server = gethostbyname(host);
    if(server == NULL) {
        printf("ERROR, no such host\n");
        return 1;
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        printf("ERROR connecting\n");
        return 1;
    }

    char buffer[256];
    printf("FTP client connected\n");
    printf("List of files: ");
    while(fgets(buffer, sizeof(buffer), stdin)) {
        send(sockfd, buffer, strlen(buffer), 0);
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("%s", buffer);
    }

    char filename[256];
    printf("Enter file name to download: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';
    printf("Downloading %s\n", filename);

    if(send(sockfd, filename, strlen(filename), 0) < 0) {
        printf("ERROR sending filename\n");
        return 1;
    }

    if(recv(sockfd, filename, sizeof(filename), 0) < 0) {
        printf("ERROR receiving filename\n");
        return 1;
    }

    FILE *fp;
    fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("ERROR opening file for writing\n");
        return 1;
    }

    if(send(sockfd, "RETR ", 5, 0) < 0) {
        printf("ERROR sending command\n");
        return 1;
    }

    if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        printf("ERROR receiving file\n");
        return 1;
    }

    while(recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
    }

    fclose(fp);
    close(sockfd);
    return 0;
}