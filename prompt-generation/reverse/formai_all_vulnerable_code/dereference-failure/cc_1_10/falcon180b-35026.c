//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define DEFAULT_PORT "7"

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];
    int sockfd, numbytes;
    char buffer[MAX_DATA];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if ((server = gethostbyname(hostname)) == NULL) {
        printf("Host not found\n");
        return 1;
    }

    if (port == NULL || strcmp(port, DEFAULT_PORT) == 0) {
        serv_addr.sin_port = htons(7);
    } else {
        serv_addr.sin_port = htons(atoi(port));
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("connect failed\n");
        return 1;
    }

    printf("Connected to %s\n", hostname);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if ((numbytes = recv(sockfd, buffer, MAX_DATA, 0)) == 0) {
            printf("Connection closed\n");
            break;
        }
        printf("Received: %s", buffer);
    }

    close(sockfd);
    return 0;
}