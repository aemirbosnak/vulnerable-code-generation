//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <host> <port> <filename>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];
    char *filename = argv[3];

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, port, &hints, &res)!= 0) {
        die("getaddrinfo");
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen)!= 0) {
        die("connect");
    }

    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        die("fopen");
    }

    char command[100];
    sprintf(command, "STOR %s\r\n", filename);
    send(sockfd, command, strlen(command), 0);

    while (fread(buffer, 1, BUFFER_SIZE, file) > 0) {
        send(sockfd, buffer, BUFFER_SIZE, 0);
    }

    fclose(file);
    close(sockfd);

    printf("File uploaded successfully!\n");
    return 0;
}