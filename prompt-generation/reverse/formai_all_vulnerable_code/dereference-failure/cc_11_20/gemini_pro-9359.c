//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <arpa/inet.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <command>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *command = argv[3];

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[BUFSIZE];

    if (strcmp(command, "LIST") == 0) {
        write(sockfd, "LIST\r\n", 6);
        while (1) {
            int n = read(sockfd, buf, BUFSIZE);
            if (n <= 0) {
                break;
            }
            write(1, buf, n);
        }
    } else if (strcmp(command, "GET") == 0) {
        if (argc < 5) {
            printf("Usage: %s <hostname> <port> <command> <filename>\n", argv[0]);
            return 1;
        }

        char *filename = argv[4];

        write(sockfd, "GET ", 4);
        write(sockfd, filename, strlen(filename));
        write(sockfd, "\r\n", 2);

        int filefd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (filefd < 0) {
            perror("open");
            return 1;
        }

        while (1) {
            int n = read(sockfd, buf, BUFSIZE);
            if (n <= 0) {
                break;
            }
            write(filefd, buf, n);
        }

        close(filefd);
    } else if (strcmp(command, "PUT") == 0) {
        if (argc < 5) {
            printf("Usage: %s <hostname> <port> <command> <filename>\n", argv[0]);
            return 1;
        }

        char *filename = argv[4];

        int filefd = open(filename, O_RDONLY);
        if (filefd < 0) {
            perror("open");
            return 1;
        }

        write(sockfd, "PUT ", 4);
        write(sockfd, filename, strlen(filename));
        write(sockfd, "\r\n", 2);

        while (1) {
            int n = read(filefd, buf, BUFSIZE);
            if (n <= 0) {
                break;
            }
            write(sockfd, buf, n);
        }

        close(filefd);
    } else {
        printf("Invalid command: %s\n", command);
        return 1;
    }

    close(sockfd);
    return 0;
}