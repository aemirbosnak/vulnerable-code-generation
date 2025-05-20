//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Establish a connection to the FTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Log in to the FTP server
    char buf[1024];
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    char username[100];
    printf("Enter your username: ");
    scanf("%s", username);

    send(sockfd, username, strlen(username), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    send(sockfd, password, strlen(password), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Change the working directory to /tmp
    send(sockfd, "CWD /tmp", strlen("CWD /tmp"), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // List the files in the current directory
    send(sockfd, "LS", strlen("LS"), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Download a file from the FTP server
    char filename[100];
    printf("Enter the name of the file you want to download: ");
    scanf("%s", filename);

    send(sockfd, "RETR ", strlen("RETR "), 0);
    send(sockfd, filename, strlen(filename), 0);
    recv(sockfd, buf, sizeof(buf), 0);
    printf("%s", buf);

    // Open a file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    // Receive the file data from the FTP server
    while (recv(sockfd, buf, sizeof(buf), 0) > 0) {
        fwrite(buf, 1, strlen(buf), fp);
    }

    // Close the file
    fclose(fp);

    // Close the connection to the FTP server
    close(sockfd);

    return 0;
}