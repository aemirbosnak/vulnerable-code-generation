//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd, portno, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server = NULL;

    // Parse the URL to get the hostname and port number
    char *url = argv[1];
    char *protocol = strtok(url, ":");
    char *hostname = strtok(NULL, ":");
    char *port_str = strtok(NULL, "/");
    char *path = strchr(url, '/');
    if (path == NULL) {
        path = "/";
    }

    // Set the default port number based on the protocol
    if (port_str == NULL) {
        if (strcmp(protocol, "http") == 0) {
            portno = 80;
        } else if (strcmp(protocol, "https") == 0) {
            portno = 443;
        } else {
            fprintf(stderr, "Unsupported protocol: %s\n", protocol);
            exit(EXIT_FAILURE);
        }
    } else {
        portno = atoi(port_str);
    }

    // Get the IP address of the host
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create a socket for the TCP connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Send the HTTP request
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // Read the HTTP response
    memset(buffer, 0, sizeof(buffer));
    while ((n = read(sockfd, buffer, BUF_SIZE - 1)) > 0) {
        fwrite(buffer, sizeof(char), n, stdout);
        memset(buffer, 0, sizeof(buffer));
    }
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}