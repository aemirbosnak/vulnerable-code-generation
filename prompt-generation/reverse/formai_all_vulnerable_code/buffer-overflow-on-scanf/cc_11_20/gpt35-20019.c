//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, data_sockfd, n;
    struct sockaddr_in serv_addr, data_addr;
    struct hostent *server;

    char buffer[MAX_SIZE];
    char username[MAX_SIZE], password[MAX_SIZE];
    char filename[MAX_SIZE];
    
    printf("Welcome to HappyFTP!\n");
    printf("Please enter the server hostname: ");
    scanf("%s", buffer);
    server = gethostbyname(buffer);

    if (server == NULL) {
        printf("Invalid server hostname!\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);
    serv_addr.sin_addr = *((struct in_addr *) server->h_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Successfully connected to the server!\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    printf("Please enter your password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    while (1) {
        printf("Please enter the command (get/put/quit): ");
        scanf("%s", buffer);

        if (strcmp(buffer, "get") == 0) {
            printf("Please enter the filename: ");
            scanf("%s", filename);

            sprintf(buffer, "TYPE I\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
            n = recv(sockfd, buffer, sizeof(buffer), 0);
            printf("%s", buffer);

            sprintf(buffer, "PASV\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
            n = recv(sockfd, buffer, sizeof(buffer), 0);
            printf("%s", buffer);
            
            int port1, port2;
            sscanf(strchr(buffer, '(') + 1, "%d,%d,%*d,%*d,%*d,%*d)", &port1, &port2);
            int data_port = port1 * 256 + port2;

            memset(&data_addr, 0, sizeof(data_addr));
            data_addr.sin_family = AF_INET;
            data_addr.sin_port = htons(data_port);
            data_addr.sin_addr = *((struct in_addr *) server->h_addr);

            data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (data_sockfd < 0) {
                perror("ERROR opening data socket");
                exit(1);
            }

            if (connect(data_sockfd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) {
                perror("ERROR connecting to data port");
                exit(1);
            }

            sprintf(buffer, "RETR %s\r\n", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
            n = recv(sockfd, buffer, MAX_SIZE, 0);

            if (strncmp(buffer, "550", 3) == 0) {
                printf("Failed to retrieve the file (file not found)\n");
                close(data_sockfd);
                continue;
            }

            int file = open(filename, O_CREAT | O_WRONLY, 0644);
            if (file < 0) {
                perror("ERROR opening file");
                exit(1);
            }

            while ((n = recv(data_sockfd, buffer, MAX_SIZE, 0)) > 0) {
                if (write(file, buffer, n) < 0) {
                    perror("ERROR writing to file");
                    break;
                }
            }

            close(file);
            close(data_sockfd);

            printf("File successfully retrieved!\n");
        } else if (strcmp(buffer, "put") == 0) {
            printf("Please enter the filename: ");
            scanf("%s", filename);

            int file = open(filename, O_RDONLY);
            if (file < 0) {
                perror("ERROR opening file");
                continue;
            }

            sprintf(buffer, "TYPE I\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
            n = recv(sockfd, buffer, sizeof(buffer), 0);
            printf("%s", buffer);

            sprintf(buffer, "PASV\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
            n = recv(sockfd, buffer, MAX_SIZE, 0);
            printf("%s", buffer);

            int port1, port2;
            sscanf(strchr(buffer, '(') + 1, "%d,%d,%*d,%*d,%*d,%*d)", &port1, &port2);
            int data_port = port1 * 256 + port2;

            memset(&data_addr, 0, sizeof(data_addr));
            data_addr.sin_family = AF_INET;
            data_addr.sin_port = htons(data_port);
            data_addr.sin_addr = serv_addr.sin_addr;

            data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (data_sockfd < 0) {
                perror("ERROR opening data socket");
                exit(1);
            }

            if (connect(data_sockfd, (struct sockaddr *) &data_addr, sizeof(data_addr)) < 0) {
                perror("ERROR connecting to data port");
                exit(1);
            }

            sprintf(buffer, "STOR %s\r\n", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            memset(buffer, 0, sizeof(buffer));
            n = recv(sockfd, buffer, MAX_SIZE, 0);

            while ((n = read(file, buffer, MAX_SIZE)) > 0) {
                if (send(data_sockfd, buffer, n, 0) < 0) {
                    perror("ERROR sending file");
                    break;
                }
            }

            close(file);
            close(data_sockfd);

            printf("File successfully uploaded!\n");
        } else if (strcmp(buffer, "quit") == 0) {
            sprintf(buffer, "QUIT\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            printf("Goodbye!\n");
            close(sockfd);
            exit(0);
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}