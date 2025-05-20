//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *hostname = "localhost";
    int port = 8080;

    if (argc > 1) {
        hostname = argv[1];
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(hostname);

    if (host == NULL) {
        fprintf(stderr, "No such host: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), stdin)!= NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);

    return 0;
}