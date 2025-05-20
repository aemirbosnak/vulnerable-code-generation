//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER 1024

int main(int argc, char **argv) {
    int sockfd, n, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];
    char cmd[MAX_BUFFER];
    char user[MAX_BUFFER];
    char pass[MAX_BUFFER];
    char filename[MAX_BUFFER];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("FTP Client - Remote Control Console\n");
    printf("-----------------------------------\n");

    while (1) {
        printf("FTP> ");
        bzero(cmd, MAX_BUFFER);
        fgets(cmd, MAX_BUFFER, stdin);
        sscanf(cmd, "%s", buffer);

        if (strcmp(buffer, "quit") == 0) {
            n = write(sockfd, cmd, strlen(cmd));
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            break;
        }
        else if (strcmp(buffer, "user") == 0) {
            sscanf(cmd, "%s %s", buffer, user);
            sprintf(buffer, "USER %s\r\n", user);
        }
        else if (strcmp(buffer, "pass") == 0) {
            sscanf(cmd, "%s %s", buffer, pass);
            sprintf(buffer, "PASS %s\r\n", pass);
        }
        else if (strcmp(buffer, "get") == 0) {
            sscanf(cmd, "%s %s", buffer, filename);
            sprintf(buffer, "RETR %s\r\n", filename);
        }
        else if (strcmp(buffer, "ls") == 0) {
            strcpy(buffer, "LIST\r\n");
        }
        else if (strcmp(buffer, "cd") == 0) {
            printf("Command not supported.\n");
            continue;
        }
        else {
            printf("Invalid command.\n");
            continue;
        }

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        bzero(buffer, MAX_BUFFER);
        n = read(sockfd, buffer, MAX_BUFFER);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        buffer[n] = '\0';
        printf("%s", buffer);

        if (strncmp(buffer, "220", 3) == 0)
            printf("Connected.\n");
        else if (strncmp(buffer, "331", 3) == 0)
            printf("User OK.\n");
        else if (strncmp(buffer, "230", 3) == 0)
            printf("Login OK.\n");
        else if (strncmp(buffer, "150", 3) == 0)
            printf("File transfer OK.\n");
        else if (strncmp(buffer, "226", 3) == 0)
            printf("File transfer complete.\n");
    }

    close(sockfd);
    return 0;
}