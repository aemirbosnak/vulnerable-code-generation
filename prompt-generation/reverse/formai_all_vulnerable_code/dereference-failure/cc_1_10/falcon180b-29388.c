//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024
#define DEFAULT_PORT "80"

typedef struct {
    char *host;
    char *service;
    int sockfd;
    struct sockaddr_in servaddr;
} hostent;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket failed");
    }
    return sockfd;
}

int connect_to_host(const char *host, const char *service) {
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        error("gethostbyname failed");
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(service));
    servaddr.sin_addr.s_addr = *((unsigned long *)he->h_addr);
    int sockfd = create_socket();
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        error("connect failed");
    }
    return sockfd;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        exit(1);
    }
    char *host = argv[1];
    char *service = argv[2];
    if (strcmp(service, "") == 0) {
        service = DEFAULT_PORT;
    }
    int sockfd = connect_to_host(host, service);
    char buffer[MAX_DATA_SIZE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sockfd, buffer, MAX_DATA_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        fprintf(stdout, "%s", buffer);
    }
    close(sockfd);
    return 0;
}