//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LENGTH 1024

struct sockaddr_in server_addr;

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n, len;
    char buffer[MAX_LENGTH];
    struct hostent *server;
    if(argc < 3) {
        printf("Usage : %s <ip address> <port number>\n", argv[0]);
        return 1;
    }
    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        printf("No such host\n");
        return 1;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("socket failed");
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);
    server_addr.sin_port = htons(portno);
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("connect failed");
    }
    while(1) {
        bzero(buffer, MAX_LENGTH);
        n = read(sockfd, buffer, MAX_LENGTH);
        if(n < 0) {
            error("read failed");
        }
        if(n == 0) {
            printf("Connection closed by server\n");
            break;
        }
        printf("Received message from server : %s\n", buffer);
    }
    close(sockfd);
    return 0;
}