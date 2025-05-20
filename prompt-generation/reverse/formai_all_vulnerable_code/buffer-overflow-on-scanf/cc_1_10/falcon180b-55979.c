//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXHOSTNAMELEN 1024
#define MAXBUFLEN 1024

int main(int argc, char *argv[]) {
    char hostname[MAXHOSTNAMELEN];
    char buffer[MAXBUFLEN];
    int sockfd, portno, ret, len;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    const char *ip_address = "127.0.0.1";

    printf("Enter the hostname or IP address: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error getting host information\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (ret == -1) {
        printf("Error connecting to host\n");
        exit(1);
    }

    printf("Connected to host\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));

        ret = recv(sockfd, buffer, MAXBUFLEN, 0);

        if (ret == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received: %s\n", buffer);

        send(sockfd, "PING", strlen("PING"), 0);

        usleep(100000);
    }

    close(sockfd);

    return 0;
}