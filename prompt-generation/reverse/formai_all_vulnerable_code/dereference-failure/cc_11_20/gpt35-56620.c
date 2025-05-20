//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s hostname port filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    char *filename = argv[3];

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // resolve hostname to IP address
    struct hostent *he;
    if ((he = gethostbyname(host)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // create server address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *) he->h_addr);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // send request to server
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", filename, host);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    char response[BUFFER_SIZE];
    memset(response, 0, sizeof(response));
    ssize_t n = recv(sockfd, response, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // check if response is valid HTTP
    if (strstr(response, "HTTP/1.1 ") != response) {
        printf("Invalid HTTP response\n");
        exit(EXIT_FAILURE);
    }

    // check if response code is 200 OK
    if (strncmp(response + 9, "200", 3) != 0) {
        printf("Error: %s\n", response + 9);
        exit(EXIT_FAILURE);
    }

    // check if response contains content-length header
    char *content_length_start = strstr(response, "Content-Length: ");
    if (content_length_start == NULL) {
        printf("Error: Content-Length header not found\n");
        exit(EXIT_FAILURE);
    }

    // parse content-length header value
    int content_length = atoi(content_length_start + 16);

    // allocate memory for file content
    char *file_content = malloc(content_length);
    if (file_content == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // receive file content in chunks asynchronously
    char *pos = file_content;
    int remaining = content_length;
    while (remaining > 0) {
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, remaining > BUFFER_SIZE ? BUFFER_SIZE : remaining, 0);
        if (n < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        } else if (n == 0) {
            printf("Connection closed by server\n");
            exit(EXIT_FAILURE);
        }
        memcpy(pos, buffer, n);
        pos += n;
        remaining -= n;
    }

    // write file content to disk
    FILE *file = fopen(filename, "wb");
    fwrite(file_content, sizeof(char), content_length, file);
    fclose(file);

    // free memory
    free(file_content);

    // close socket
    close(sockfd);

    printf("File downloaded successfully\n");

    return 0;
}