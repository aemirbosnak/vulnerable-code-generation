//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

void ftp_client_login(int sockfd)
{
    char buf[MAXSIZE];
    char username[MAXSIZE];
    char password[MAXSIZE];

    printf("Enter username: ");
    scanf("%s", username);
    sprintf(buf, "USER %s\r\n", username);
    send(sockfd, buf, strlen(buf), 0);

    recv(sockfd, buf, MAXSIZE, 0);
    printf("%s", buf);

    printf("Enter password: ");
    scanf("%s", password);
    sprintf(buf, "PASS %s\r\n", password);
    send(sockfd, buf, strlen(buf), 0);

    recv(sockfd, buf, MAXSIZE, 0);
    printf("%s", buf);
}

void ftp_client_get(int sockfd)
{
    char buf[MAXSIZE];
    char filename[MAXSIZE];

    printf("Enter filename: ");
    scanf("%s", filename);

    sprintf(buf, "RETR %s\r\n", filename);
    send(sockfd, buf, strlen(buf), 0);

    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    int numbytes;

    while ((numbytes = recv(sockfd, buf, MAXSIZE, 0)) > 0) {
        fwrite(buf, sizeof(char), numbytes, fp);
    }

    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: ./client <ipaddr> <port>\n");
        exit(1);
    }

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect");
        exit(1);
    }

    ftp_client_login(sockfd);

    printf("1. Download file\n2. Upload file\n3. Quit\n");

    int choice;

    while (1) {
        printf("Enter a choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            ftp_client_get(sockfd);
        } else if (choice == 2) {
            // code to upload file
        } else if (choice == 3) {
            close(sockfd);
            exit(0);
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}