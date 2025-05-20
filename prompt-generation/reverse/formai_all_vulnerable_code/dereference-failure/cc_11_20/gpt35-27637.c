//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 65535

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <target url>\n", argv[0]);
        exit(1);
    }

    // Parse URL
    char *url = argv[1];
    char *port = "80";
    char *path = "/";
    char *host = strtok(url, "/");
    path = strtok(NULL, "") ? strtok(NULL, "") : path; 

    // Get IP address
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *addr_result;
    int status = getaddrinfo(host, port, &hints, &addr_result);
    if (status != 0) {
        printf("Error getting IP address for %s: %s\n", host, gai_strerror(status));
        exit(1);
    }

    // Connect to server
    struct addrinfo *addr_ptr;
    int sockfd;
    for (addr_ptr = addr_result; addr_ptr != NULL; addr_ptr = addr_ptr->ai_next) {
        sockfd = socket(addr_ptr->ai_family, addr_ptr->ai_socktype, addr_ptr->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        if (connect(sockfd, addr_ptr->ai_addr, addr_ptr->ai_addrlen) != -1) {
            break;
        }
        close(sockfd);
    }
    if (addr_ptr == NULL) {
        printf("Unable to connect to server.\n");
        exit(1);
    }

    // Build HTTP request
    char request[MAX_BUFFER_SIZE];
    snprintf(request, MAX_BUFFER_SIZE, "GET /%s HTTP/1.1\r\n"
                                        "Host: %s\r\n"
                                        "User-Agent: Mozilla/5.0\r\n"
                                        "Connection: close\r\n"
                                        "\r\n", path, host);

    // Send HTTP request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        printf("Error sending request.\n");
        exit(1);
    }

    // Receive HTTP response
    char response[MAX_BUFFER_SIZE];
    int total_bytes_received = 0;
    int bytes_received;
    while ((bytes_received = recv(sockfd, response + total_bytes_received, MAX_BUFFER_SIZE - total_bytes_received, 0)) > 0) {
        total_bytes_received += bytes_received;
        if (total_bytes_received == MAX_BUFFER_SIZE) {
            printf("Response too large.\n");
            exit(1);
        }
    }
    if (bytes_received == -1) {
        printf("Error receiving response.\n");
        exit(1);
    }

    // Print HTTP response
    printf("%s", response);

    // Clean up
    freeaddrinfo(addr_result);
    close(sockfd);

    return 0;
}