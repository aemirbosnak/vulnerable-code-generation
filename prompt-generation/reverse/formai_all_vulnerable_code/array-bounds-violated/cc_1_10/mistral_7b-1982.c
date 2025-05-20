//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 80

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, clilen;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];
    char request[MAX_BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Could not resolve host %s\n", argv[1]);
        exit(1);
    }

    portno = PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    snprintf(request, MAX_BUFFER_SIZE,
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "User-Agent: The-Curious-C-Client/1.0\r\n"
             "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
             "Connection: keep-alive\r\n\r\n");

    write(sockfd, request, strlen(request));

    int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_received <= 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    close(sockfd);
    return 0;
}