//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes, retval;
    struct hostent *host;
    struct sockaddr_in target;
    char *hostname;
    int port;
    char buffer[1024];
    struct timeval timeout;

    if (argc!= 4) {
        printf("Usage: %s <hostname/IP> <port> <timeout>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    timeout.tv_sec = atoi(argv[3]);
    timeout.tv_usec = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed.\n");
        exit(1);
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &target.sin_addr) <= 0) {
        printf("Invalid hostname/IP.\n");
        exit(1);
    }

    retval = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
    if (retval == -1) {
        printf("Connection failed.\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    send(sockfd, "PING", strlen("PING"), 0);

    numbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (numbytes <= 0) {
        printf("No response from server.\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    close(sockfd);

    return 0;
}