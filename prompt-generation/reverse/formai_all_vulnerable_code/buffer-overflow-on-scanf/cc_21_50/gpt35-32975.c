//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 21
#define MAX_MSG 100

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[MAX_MSG];
    char username[MAX_MSG];
    char password[MAX_MSG];
    char filename[MAX_MSG];
    char command[MAX_MSG];
    int n, i;

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // setup server address
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    serveraddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // get login credentials
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // send credentials to server
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    // loop to receive commands from user
    while (1) {
        // print out available commands
        printf("Available commands: get, put, ls, cd, pwd, quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        // handle get command
        if (strcasecmp(command, "get") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            sprintf(buffer, "RETR %s\r\n", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            if (buffer[0] == '2' && buffer[1] == '2') {
                // file exists on server
                FILE *fp = fopen(filename, "w");
                if (fp == NULL) {
                    perror("Error creating file");
                    continue;
                }
                while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
                    fwrite(buffer, 1, n, fp);
                }
                fclose(fp);
                recv(sockfd, buffer, sizeof(buffer), 0);
            } else {
                // file does not exist on server
                fprintf(stderr, "Error: %s", buffer);
            }
        }

        // handle put command
        else if (strcasecmp(command, "put") == 0) {
            printf("Enter filename: ");
            scanf("%s", filename);
            FILE *fp = fopen(filename, "r");
            if (fp == NULL) {
                perror("Error opening file");
                continue;
            }
            sprintf(buffer, "STOR %s\r\n", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            while ((n = fread(buffer, 1, MAX_MSG, fp)) > 0) {
                send(sockfd, buffer, n, 0);
            }
            fclose(fp);
            recv(sockfd, buffer, sizeof(buffer), 0);
        }

        // handle ls command
        else if (strcasecmp(command, "ls") == 0) {
            send(sockfd, "LIST\r\n", 6, 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            if (buffer[0] == '1' && buffer[1] == '5') {
                // receive data from server
                int data_sockfd;
                struct sockaddr_in data_serveraddr;
                if ((data_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                    perror("Error creating socket");
                    continue;
                }
                int data_server_port;
                char *ptr = strrchr(buffer, ',');
                sscanf(ptr + 1, "%d,%d,%d,%d,%d,%d", &i, &i, &i, &i, &i, &data_server_port);
                data_serveraddr.sin_family = AF_INET;
                data_serveraddr.sin_port = htons(data_server_port);
                data_serveraddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
                if (connect(data_sockfd, (struct sockaddr*)&data_serveraddr, sizeof(data_serveraddr)) < 0) {
                    perror("Error connecting to server");
                    continue;
                }
                while ((n = recv(data_sockfd, buffer, sizeof(buffer), 0)) > 0) {
                    write(1, buffer, n);
                }
                close(data_sockfd);
                recv(sockfd, buffer, sizeof(buffer), 0);
            } else {
                fprintf(stderr, "Error: %s", buffer);
            }
        }

        // handle cd command
        else if (strcasecmp(command, "cd") == 0) {
            printf("Enter directory: ");
            scanf("%s", buffer);
            sprintf(command, "CWD %s\r\n", buffer);
            send(sockfd, command, strlen(command), 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            if (buffer[0] == '2' && buffer[1] == '5') {
                printf("Changed directory to %s\n", buffer);
            } else {
                fprintf(stderr, "Error: %s", buffer);
            }
        }

        // handle pwd command
        else if (strcasecmp(command, "pwd") == 0) {
            send(sockfd, "PWD\r\n", 5, 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            if (buffer[0] == '2' && buffer[1] == '5') {
                printf("%s", buffer + 4);
            } else {
                fprintf(stderr, "Error: %s", buffer);
            }
        }

        // handle quit command
        else if (strcasecmp(command, "quit") == 0) {
            send(sockfd, "QUIT\r\n", 6, 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            if (buffer[0] == '2' && buffer[1] == '2') {
                printf("Disconnected from server\n");
            } else {
                fprintf(stderr, "Error: %s", buffer);
            }
            break;
        }

        // handle invalid command
        else {
            printf("Invalid command\n");
        }
    }

    // close socket
    close(sockfd);

    return 0;
}