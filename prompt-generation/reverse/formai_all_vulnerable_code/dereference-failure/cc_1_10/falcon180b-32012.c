//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 25
#define MAX_LINE 1024
#define MAX_HOSTNAME 64
#define DATA_FILE "data.txt"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, len;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[MAX_LINE];
    FILE *fp;
    char hostname[MAX_HOSTNAME];
    char *ptr;

    if (argc!= 3) {
        printf("Usage:./smtp_client <server_ip> <file_name>\n");
        exit(0);
    }

    strcpy(hostname, argv[1]);
    strcat(hostname, ":25");
    printf("Connecting to SMTP server %s...\n", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to SMTP server\n");

    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    while (fgets(buffer, MAX_LINE, fp)!= NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
        memset(buffer, 0, MAX_LINE);
    }

    fclose(fp);

    len = sizeof(cli_addr);
    if (getsockname(sockfd, (struct sockaddr *)&cli_addr, &len) == -1) {
        printf("Error getting socket name\n");
        exit(0);
    }

    printf("Closing connection...\n");

    close(sockfd);
    return 0;
}