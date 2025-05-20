//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFERSIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return 1;
    }

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    char buffer[BUFFERSIZE];
    bzero(buffer, BUFFERSIZE);

    while (1) {
        printf("ftp> ");
        fgets(buffer, BUFFERSIZE, stdin);

        if (strcmp(buffer, "help\n") == 0) {
            printf("Commands:\n");
            printf("  help     - display this help message\n");
            printf("  ls       - list files in the current directory\n");
            printf("  cd       - change the current directory\n");
            printf("  get      - download a file\n");
            printf("  put      - upload a file\n");
            printf("  quit     - quit the FTP session\n");
        } else if (strcmp(buffer, "ls\n") == 0) {
            send(sockfd, "ls\n", strlen("ls\n"), 0);
            bzero(buffer, BUFFERSIZE);
            int n = read(sockfd, buffer, BUFFERSIZE);
            if (n > 0) {
                printf("%s", buffer);
            }
        } else if (strcmp(buffer, "cd\n") == 0) {
            printf("Enter the directory you want to change to: ");
            fgets(buffer, BUFFERSIZE, stdin);
            send(sockfd, "cd ", strlen("cd "), 0);
            send(sockfd, buffer, strlen(buffer), 0);
            bzero(buffer, BUFFERSIZE);
            int n = read(sockfd, buffer, BUFFERSIZE);
            if (n > 0) {
                printf("%s", buffer);
            }
        } else if (strcmp(buffer, "get\n") == 0) {
            printf("Enter the name of the file you want to download: ");
            fgets(buffer, BUFFERSIZE, stdin);
            send(sockfd, "get ", strlen("get "), 0);
            send(sockfd, buffer, strlen(buffer), 0);
            bzero(buffer, BUFFERSIZE);
            int n = read(sockfd, buffer, BUFFERSIZE);
            if (n > 0) {
                printf("%s", buffer);
            }
        } else if (strcmp(buffer, "put\n") == 0) {
            printf("Enter the name of the file you want to upload: ");
            fgets(buffer, BUFFERSIZE, stdin);
            send(sockfd, "put ", strlen("put "), 0);
            send(sockfd, buffer, strlen(buffer), 0);
            bzero(buffer, BUFFERSIZE);
            int n = read(sockfd, buffer, BUFFERSIZE);
            if (n > 0) {
                printf("%s", buffer);
            }
        } else if (strcmp(buffer, "quit\n") == 0) {
            send(sockfd, "quit\n", strlen("quit\n"), 0);
            close(sockfd);
            return 0;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}