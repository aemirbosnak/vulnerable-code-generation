//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;
    FILE *fp;

    if (argc < 3) {
        printf("Usage:./ftp_client <server_ip> <port_number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        n = send(sockfd, buffer, strlen(buffer), 0);

        if (n == -1) {
            printf("Error sending command\n");
            exit(1);
        }

        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (n == -1) {
            printf("Error receiving response\n");
            exit(1);
        }

        printf("Server response: %s", buffer);
    }

    close(sockfd);
    exit(0);
}