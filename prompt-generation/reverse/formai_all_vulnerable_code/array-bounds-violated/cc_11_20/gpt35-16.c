//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    // Parse URL
    char *url = argv[1];
    char hostname[BUFFER_SIZE];
    int port = 80;
    char path[BUFFER_SIZE];
    int ssl = 0;
    if (strncmp(url, "http://", 7) == 0) {
        url += 7;
    } else if (strncmp(url, "https://", 8) == 0) {
        url += 8;
        ssl = 1;
        port = 443;
    }
    char *port_pos = strchr(url, ':');
    char *path_pos = strchr(url, '/');
    if (path_pos == NULL) {
        strcpy(path, "/");
    } else {
        strcpy(path, path_pos);
        *path_pos = '\0';
    }
    if (port_pos != NULL) {
        sscanf(port_pos+1, "%d", &port);
        strncpy(hostname, url, strlen(url) - strlen(port_pos));
        hostname[strlen(url) - strlen(port_pos)] = '\0';
    } else {
        strcpy(hostname, url);
    }

    // Resolve hostname to IP address
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Error: Could not resolve hostname\n");
        return 1;
    }
    char *ip = inet_ntoa(*(struct in_addr *)he->h_addr_list[0]);
    printf("Connecting to %s (%s) on port %d...\n", hostname, ip, port);

    // Open socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not open socket\n");
        return 1;
    }
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    // Send HTTP request
    char request[BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    printf("Sending request:\n%s", request);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error: Could not send request\n");
        return 1;
    }

    // Receive HTTP response
    char response[BUFFER_SIZE];
    int received = 0;
    printf("Receiving response:\n");
    while ((received = recv(sockfd, response, BUFFER_SIZE-1, 0)) > 0) {
        response[received] = '\0';
        printf("%s", response);
    }

    close(sockfd);
    return 0;
}