//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_URL_LEN 1024
#define MAX_HOST_LEN 256
#define MAX_IP_LEN 16
#define MAX_TIMEOUT 30

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char host[MAX_HOST_LEN];
    char ip[MAX_IP_LEN];
    char buf[MAX_URL_LEN];
    int port = PORT;
    int sockfd;
    int n;

    // Parse URL
    n = sscanf(url, "http://%1023[^\n]:%d/%1023[^\n]", host, &port, buf);
    if (n < 3) {
        printf("Invalid URL\n");
        return 1;
    }

    // Resolve hostname
    struct hostent *he = gethostbyname(host);
    if (!he) {
        printf("Error: gethostbyname() failed\n");
        return 1;
    }
    strcpy(ip, he->h_addr_list[0]);

    // Connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: socket() failed\n");
        return 1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: connect() failed\n");
        return 1;
    }

    // Send HTTP request
    char request[MAX_URL_LEN];
    snprintf(request, MAX_URL_LEN, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", buf, host);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error: send() failed\n");
        return 1;
    }

    // Receive HTTP response
    char response[MAX_URL_LEN];
    memset(response, 0, MAX_URL_LEN);
    if ((n = recv(sockfd, response, MAX_URL_LEN, 0)) < 0) {
        printf("Error: recv() failed\n");
        return 1;
    }

    // Check for HTTP status code
    char status_code[10];
    memset(status_code, 0, 10);
    if (sscanf(response, "HTTP/%*s %9[^\n]", status_code) != 1) {
        printf("Error: unable to parse HTTP status code\n");
        return 1;
    }
    int status_code_int = atoi(status_code);
    if (status_code_int != 200) {
        printf("Error: HTTP status code %d\n", status_code_int);
        return 1;
    }

    // Print HTTP response body
    char *body = strstr(response, "\r\n\r\n");
    if (!body) {
        printf("Error: unable to find HTTP response body\n");
        return 1;
    }
    printf("%s\n", body + 4);

    // Close socket
    close(sockfd);

    return 0;
}