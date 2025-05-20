//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    int sockfd, port, rcv_size;
    char buffer[BUFFER_SIZE] = {0};
    char command[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE] = {0};

    if (argc < 3) {
        printf("Usage: ./ftpclient <ip> <port>\n");
        return -1;
    }
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        printf("Invalid address.\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Connection failed.\n");
        return -1;
    }

    printf("Connected to the server.\n");

    while(1) {
        printf("> ");
        fgets(command, BUFFER_SIZE, stdin);
        char *pos;
        if ((pos=strchr(command, '\n')) != NULL) {
            *pos = '\0';
        }

        if(strcmp(command, "quit") == 0) {
            write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
            memset(buffer, 0, sizeof(buffer));
            rcv_size = read(sockfd, buffer, sizeof(buffer));
            printf("%s", buffer);
            break;
        } else if (strncmp(command, "get", 3) == 0) {
            write(sockfd, command, strlen(command));
            memset(buffer, 0, sizeof(buffer));
            rcv_size = read(sockfd, buffer, sizeof(buffer));
            printf("%s", buffer);
        } else if (strncmp(command, "put", 3) == 0) {
            write(sockfd, command, strlen(command));
            memset(buffer, 0, sizeof(buffer));
            rcv_size = read(sockfd, buffer, sizeof(buffer));
            if (strncmp(buffer, "READY", 5) == 0) {
                FILE *fp;
                char *filename = command + 4;
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Error opening file %s\n", filename);
                } else {
                    memset(buffer, 0, sizeof(buffer));
                    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
                        write(sockfd, buffer, strlen(buffer));
                        memset(buffer, 0, sizeof(buffer));
                    }
                    fclose(fp);
                }
            }
        } else if (strcmp(command, "ls") == 0) {
            write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
            memset(buffer, 0, sizeof(buffer));
            rcv_size = read(sockfd, buffer, sizeof(buffer));
            printf("%s", buffer);
        } else if (strncmp(command, "cd", 2) == 0) {
            write(sockfd, command, strlen(command));
            memset(buffer, 0, sizeof(buffer));
            rcv_size = read(sockfd, buffer, sizeof(buffer));
            printf("%s", buffer);
        } else {
            printf("Invalid command.\n");
        }
    }

    close(sockfd);
    return 0;
}