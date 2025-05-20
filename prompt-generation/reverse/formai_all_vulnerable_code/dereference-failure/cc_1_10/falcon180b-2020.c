//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char *cmd = "LIST";
    char *filename = "file.txt";

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    //initialize server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(21);
    inet_pton(AF_INET, "192.168.1.100", &serveraddr.sin_addr);

    //connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    //login
    char username[20] = "username";
    char password[20] = "password";
    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    //send command
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    //download file
    char *filename_cmd = "RETR ";
    strcat(filename_cmd, filename);
    send(sockfd, filename_cmd, strlen(filename_cmd), 0);
    int file_fd = open(filename, O_CREAT | O_WRONLY);
    if (file_fd == -1) {
        printf("Error creating file\n");
        return -1;
    }
    int bytes_received = 0;
    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        write(file_fd, buffer, BUFFER_SIZE);
        bytes_received += BUFFER_SIZE;
    }
    close(sockfd);
    close(file_fd);
    printf("File downloaded successfully\n");
    return 0;
}