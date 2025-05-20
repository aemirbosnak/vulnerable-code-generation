//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define FTP_BUFF_SIZE 1024

int main() {
    int sockfd, port;
    struct sockaddr_in serv_addr;
    char *host, *username, *password, *command;
    FILE *fp;

    printf("Welcome to the FTP client!\n");
    printf("Enter the FTP server address: ");
    scanf("%s", host);
    printf("Enter the FTP server port number: ");
    scanf("%d", &port);
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Enter the FTP command you want to execute: ");
    scanf("%s", command);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        perror("Error converting IP address");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, command, strlen(command), 0);

    if (strncmp(command, "RETR", 4) == 0) {
        char filename[FTP_BUFF_SIZE];
        recv(sockfd, filename, FTP_BUFF_SIZE, 0);
        if ((fp = fopen(filename, "w")) == NULL) {
            perror("Error opening file");
            exit(1);
        }
        while (1) {
            char buffer[FTP_BUFF_SIZE];
            int nbytes = recv(sockfd, buffer, FTP_BUFF_SIZE, 0);
            if (nbytes <= 0) {
                break;
            }
            fwrite(buffer, 1, nbytes, fp);
        }
        fclose(fp);
        printf("File downloaded successfully!\n");
    } else if (strncmp(command, "STOR", 4) == 0) {
        char filename[FTP_BUFF_SIZE];
        recv(sockfd, filename, FTP_BUFF_SIZE, 0);
        if ((fp = fopen(filename, "r")) == NULL) {
            perror("Error opening file");
            exit(1);
        }
        while (1) {
            char buffer[FTP_BUFF_SIZE];
            int nbytes = fread(buffer, 1, FTP_BUFF_SIZE, fp);
            if (nbytes <= 0) {
                break;
            }
            send(sockfd, buffer, nbytes, 0);
        }
        fclose(fp);
        printf("File uploaded successfully!\n");
    } else {
        char buffer[FTP_BUFF_SIZE];
        while (recv(sockfd, buffer, FTP_BUFF_SIZE, 0) > 0) {
            printf("%s", buffer);
        }
    }

    close(sockfd);
    return 0;
}