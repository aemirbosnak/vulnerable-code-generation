//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage:./smtp_client <server_ip> <port_number> <email_file>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        printf("Error opening email file\n");
        return 1;
    }

    char *email_data = malloc(BUF_SIZE);
    fread(email_data, 1, BUF_SIZE, fp);
    fclose(fp);

    char *email_header = "From: example@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\n";
    strcat(email_data, email_header);

    send(sockfd, email_data, strlen(email_data), 0);

    while ((n = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    free(email_data);

    return 0;
}