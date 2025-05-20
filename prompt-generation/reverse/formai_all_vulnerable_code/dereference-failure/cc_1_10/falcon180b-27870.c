//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if(argc!= 4) {
        die("Usage:./smtp_client <server_address> <port_number> <username>");
    }

    char* server_address = argv[1];
    int port_number = atoi(argv[2]);
    char* username = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        die("socket failed");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, server_address, &serv_addr.sin_addr);

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        die("connect failed");
    }

    char buffer[1024];
    char* msg = "HELO ";
    strcat(msg, server_address);
    strcat(msg, "\r\n");

    send(sockfd, msg, strlen(msg), 0);

    while(1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if(bytes_received <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}