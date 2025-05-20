//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

int sockfd;

void error(char *msg)
{
    perror(msg);
    exit(0);
}

void connect_to_server(char *ip, int port)
{
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating the socket!!\n");
        exit(0);
    }

    printf("Socket created successfully!\n");

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection failed!\n");
        exit(0);
    }

    printf("Connected to the server successfully!\n");
}

void send_file(char *file_path)
{
    char buffer[MAXSIZE];
    int nbytes, fd;

    fd = open(file_path, O_RDONLY);

    if (fd == -1) {
        printf("Error opening the file!!\n");
        exit(0);
    }

    bzero(buffer, MAXSIZE);

    while ((nbytes = read(fd, buffer, MAXSIZE)) > 0) {
        if (send(sockfd, buffer, nbytes, 0) == -1) {
            printf("Error sending the file!\n");
            exit(0);
        }
        bzero(buffer, MAXSIZE);
    }

    printf("File sent successfully!\n");

    close(fd);
}

void receive_file(char *file_path)
{
    char buffer[MAXSIZE];
    int nbytes, fd;

    fd = open(file_path, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1) {
        printf("Error creating the file!!\n");
        exit(0);
    }

    bzero(buffer, MAXSIZE);

    while ((nbytes = recv(sockfd, buffer, MAXSIZE, 0)) > 0) {
        if (nbytes == -1) {
            printf("Error receiving the file!\n");
            exit(0);
        }

        if (write(fd, buffer, nbytes) == -1) {
            printf("Error writing to the file!\n");
            exit(0);
        }

        bzero(buffer, MAXSIZE);
    }

    printf("File received successfully!\n");

    close(fd);
}

int main()
{
    char ip[MAXSIZE], file_path[MAXSIZE];
    int port, choice;

    printf("Enter the IP address of the FTP server: ");
    scanf("%s", ip);

    printf("Enter the port number: ");
    scanf("%d", &port);

    connect_to_server(ip, port);

    printf("Menu:\n");
    printf("1. Upload file\n");
    printf("2. Download file\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the file path to upload: ");
            scanf("%s", file_path);
            send_file(file_path);
            break;
        case 2:
            printf("Enter the file path to download: ");
            scanf("%s", file_path);
            receive_file(file_path);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    close(sockfd);

    return 0;
}