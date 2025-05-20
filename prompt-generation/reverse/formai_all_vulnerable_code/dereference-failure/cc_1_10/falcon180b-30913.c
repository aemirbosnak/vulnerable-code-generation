//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./ftp_client <ip_address> <port_number> <filename>\n");
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char *filename = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket!\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server!\n");
        return 1;
    }

    printf("Connected to server successfully!\n");

    char cmd[20];
    sprintf(cmd, "RETR %s", filename);
    send(sockfd, cmd, strlen(cmd), 0);

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    while ((int)fread(buffer, 1, BUFFER_SIZE, fp) > 0) {
        send(sockfd, buffer, fread(buffer, 1, BUFFER_SIZE, fp), 0);
    }

    fclose(fp);
    close(sockfd);

    printf("File transfer completed successfully!\n");

    return 0;
}