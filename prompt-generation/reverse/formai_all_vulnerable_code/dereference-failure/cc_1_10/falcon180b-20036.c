//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char *ip_address;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    FILE *fp;

    if (argc!= 3) {
        printf("Usage:./client <IP Address> <Port Number>\n");
        exit(0);
    }

    ip_address = argv[1];
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(0);
    }

    server = gethostbyname(ip_address);
    if (server == NULL) {
        printf("Error: Invalid IP Address\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    fp = fdopen(sockfd, "r+");
    if (fp == NULL) {
        printf("Error: Failed to open file\n");
        exit(0);
    }

    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}