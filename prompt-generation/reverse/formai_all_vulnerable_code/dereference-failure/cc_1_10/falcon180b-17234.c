//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        exit(0);
    }

    strcpy(buffer, argv[1]);
    strcat(buffer, " ");
    strcat(buffer, argv[2]);
    strcat(buffer, " ");
    strcat(buffer, argv[3]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect\n");
        exit(0);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        printf("Error: setsockopt\n");
        exit(0);
    }

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Error: send\n");
        exit(0);
    }

    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        printf("Error: recv\n");
        exit(0);
    }

    printf("Server: %s\n", buffer);

    close(sockfd);

    return 0;
}