//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, bytes_sent, bytes_received;
    struct hostent *host;
    struct sockaddr_in serv_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: unknown host %s\n", argv[1]);
        return 1;
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = htons(0);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connection established.\n");

    if (send(sockfd, "Hello, World!", 13, 0) < 0) {
        perror("send");
        return 1;
    }

    if ((bytes_sent = send(sockfd, "Hello, World!", 13, 0)) < 0) {
        perror("send");
        return 1;
    }

    if ((bytes_received = recv(sockfd, 0, 0, 0)) < 0) {
        perror("recv");
        return 1;
    }

    printf("Received: %s\n", (char *)malloc(bytes_received + 1));

    close(sockfd);

    return 0;
}