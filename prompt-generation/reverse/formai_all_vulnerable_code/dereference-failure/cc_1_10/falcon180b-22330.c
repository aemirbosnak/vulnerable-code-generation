//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 512
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd, portno;
    char *ip_address;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int n;

    if (argc!= 4) {
        printf("Usage:./ftp_client <ip_address> <port_number> <command>\n");
        exit(0);
    }

    ip_address = argv[1];
    portno = atoi(argv[2]);
    char *command = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Unable to create socket\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        exit(0);
    }

    send(sockfd, command, strlen(command), 0);

    while (1) {
        bzero(buffer, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("Error: Unable to receive data\n");
            exit(0);
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}