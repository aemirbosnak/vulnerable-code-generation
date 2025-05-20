//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char user[BUFFER_SIZE], password[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char temp[BUFFER_SIZE];
    char *ipaddr;

    if (argc != 2) {
        printf("Usage: %s <FTP server IP address>\n", argv[0]);
        exit(0);
    }
    ipaddr = argv[1];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Error opening socket");
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ipaddr);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        error("Error receiving message from server");
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Username: ");
    scanf("%s", user);
    sprintf(temp, "USER %s\r\n", user);
    if (send(sockfd, temp, strlen(temp), 0) < 0) {
        error("Error sending message to server");
    }

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        error("Error receiving message from server");
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Password: ");
    scanf("%s", password);
    sprintf(temp, "PASS %s\r\n", password);
    if (send(sockfd, temp, strlen(temp), 0) < 0) {
        error("Error sending message to server");
    }

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        error("Error receiving message from server");
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    while (1) {
        printf("ftp> ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            sprintf(temp, "QUIT\r\n");
            if (send(sockfd, temp, strlen(temp), 0) < 0) {
                error("Error sending message to server");
            }

            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (n < 0) {
                error("Error receiving message from server");
            }
            buffer[n] = '\0';
            printf("%s", buffer);
            break;

        } else if (strcmp(command, "ls") == 0) {
            sprintf(temp, "LIST\r\n");
            if (send(sockfd, temp, strlen(temp), 0) < 0) {
                error("Error sending message to server");
            }

            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (n < 0) {
                error("Error receiving message from server");
            }
            buffer[n] = '\0';
            printf("%s", buffer);

        } else if (strcmp(command, "get") == 0) {
            printf("File name: ");
            scanf("%s", filename);
            sprintf(temp, "RETR %s\r\n", filename);
            if (send(sockfd, temp, strlen(temp), 0) < 0) {
                error("Error sending message to server");
            }

            FILE *fp;
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                error("Error opening file for writing");
            }

            while (1) {
                n = recv(sockfd, buffer, BUFFER_SIZE, 0);
                if (n < 0) {
                    error("Error receiving message from server");
                }
                if (n == 0) {
                    break;
                }
                fwrite(buffer, 1, n, fp);
            }

            fclose(fp);
            printf("File received successfully\n");

        } else if (strcmp(command, "put") == 0) {
            printf("File name: ");
            scanf("%s", filename);
            sprintf(temp, "STOR %s\r\n", filename);
            if (send(sockfd, temp, strlen(temp), 0) < 0) {
                error("Error sending message to server");
            }

            FILE *fp;
            fp = fopen(filename, "rb");
            if (fp == NULL) {
                error("Error opening file for reading");
            }

            while ((n = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
                if (send(sockfd, buffer, n, 0) < 0) {
                    error("Error sending file to server");
                }
            }

            fclose(fp);
            printf("File sent successfully\n");

        } else {
            printf("Invalid command\n");
        }
    }

    close(sockfd);
    return 0;
}