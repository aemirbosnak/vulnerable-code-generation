//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define ERR_MSG "Error: %s\n"

struct hostent *gethostbyname(const char *name);
int connect(int sockfd, const struct sockaddr *serv_addr, socklen_t addrlen);

int main(int argc, char *argv[]) {

    if(argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[2]) + 1;

    printf("Scanning %s:%d - %d\n", ip, start_port, end_port);

    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == 0) {
        perror("socket failed");
        exit(errno);
    }

    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(errno);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(start_port);

    if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(errno);
    }

    listen(sockfd, 3);

    while(1) {

        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);

        if(newsockfd < 0) {
            perror("accept");
            exit(errno);
        }

        printf("Connected with %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        close(newsockfd);
    }

    return 0;
}

struct hostent *gethostbyname(const char *name) {
    struct hostent *host;
    int h_errno;

    if((host = gethostbyname(name)) == NULL) {
        h_errno = h_errno;
        fprintf(stderr, ERR_MSG, "gethostbyname");
        exit(h_errno);
    }

    return host;
}

int connect(int sockfd, const struct sockaddr *serv_addr, socklen_t addrlen) {

    if(connect(sockfd, serv_addr, addrlen) < 0) {
        perror("connect");
        exit(errno);
    }

    return 0;
}