//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname = "www.example.com";
    char *path = "/";
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, portno, bytes, sent, received, total;
    char buffer[BUFFER_SIZE];

    // Resolve hostname to IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname\n");
        return 1;
    }

    // Set up socket address
    portno = 80;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr_list[0], &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        return 1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Could not connect to server\n");
        return 1;
    }

    // Construct HTTP request
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: my_c_http_client\r\nConnection: close\r\n\r\n", path, hostname);

    // Send request
    total = strlen(buffer);
    sent = 0;
    do {
        bytes = write(sockfd, buffer+sent, total-sent);
        if (bytes < 0) {
            fprintf(stderr, "Error: Could not send request\n");
            return 1;
        }
        sent += bytes;
    } while (sent < total);

    // Receive response
    bzero(buffer, BUFFER_SIZE);
    total = BUFFER_SIZE-1;
    received = 0;
    do {
        bytes = read(sockfd, buffer+received, total-received);
        if (bytes < 0) {
            fprintf(stderr, "Error: Could not receive response\n");
            return 1;
        }
        if (bytes == 0) {
            break;
        }
        received += bytes;
    } while (received < total);

    if (received == total) {
        fprintf(stderr, "Error: Response too large\n");
        return 1;
    }

    // Parse response and print body
    char *body = strstr(buffer, "\r\n\r\n");
    if (body != NULL) {
        body += 4;
        printf("%s", body);
    }

    // Clean up
    close(sockfd);

    return 0;
}