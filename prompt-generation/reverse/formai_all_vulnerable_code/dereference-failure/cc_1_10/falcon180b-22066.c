//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int n;

    if (argc!= 3) {
        printf("Usage:./ftp_client <hostname> <port>\n");
        return 1;
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Invalid hostname\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        printf("Enter command (quit to exit): ");
        fgets(buffer, BUF_SIZE, stdin);
        n = strlen(buffer);
        if (n > 0 && buffer[n - 1] == '\n') {
            buffer[n - 1] = '\0';
        }
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        send(sockfd, buffer, n, 0);
        bzero(buffer, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Server disconnected\n");
            close(sockfd);
            return 1;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}