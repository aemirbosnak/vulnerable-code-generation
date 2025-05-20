//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: careful
/*
 * A simple FTP client program
 * Connects to an FTP server and can perform operations like file upload and download 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char buf[MAX_BUF_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *he;

    if (argc != 2) {
        fprintf(stderr, "usage: ftpclient hostname\n");
        exit(1);
    }

    if ((he = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname failed");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connection failed");
        exit(1);
    }

    printf("Connected to server %s (%s)\n", argv[1], inet_ntoa(server_addr.sin_addr));

    while(1) {
        printf("Enter command: ");
        fgets(buf, MAX_BUF_SIZE, stdin);

        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send failed");
            close(sockfd);
            exit(1);
        }

        if ((numbytes = recv(sockfd, buf, MAX_BUF_SIZE, 0)) == -1) {
            perror("receive failed");
            close(sockfd);
            exit(1);
        }
        buf[numbytes] = '\0';

        printf("Server: %s", buf);

        if (strcmp(buf, "QUIT\n") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}