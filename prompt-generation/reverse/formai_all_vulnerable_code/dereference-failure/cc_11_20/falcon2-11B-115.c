//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

int main(int argc, char* argv[]) {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(struct sockaddr_in);
    char buffer[BUFSIZ];
    char target_url[128];
    char client_ip[INET_ADDRSTRLEN];
    char server_ip[INET_ADDRSTRLEN];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target_url> <proxy_port>\n", argv[0]);
        exit(1);
    }

    strcpy(target_url, argv[1]);
    char *endptr;
    long port = strtol(argv[2], &endptr, 10);
    if (endptr == argv[2] || *endptr!= '\0' || port <= 0) {
        fprintf(stderr, "Invalid port number.\n");
        exit(1);
    }

    printf("Connecting to %s on port %ld...\n", target_url, port);

    // Connect to target server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, target_url, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid target URL.\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s on port %ld.\n", target_url, port);

    // Accept client connection
    memset(&client_addr, 0, sizeof(client_addr));
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
    if (new_sockfd < 0) {
        perror("accept");
        exit(1);
    }

    printf("Client connected from %s\n", inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip)));

    // Receive client request
    bzero(buffer, BUFSIZ);
    if (read(new_sockfd, buffer, sizeof(buffer)) < 0) {
        perror("read");
        exit(1);
    }

    printf("Received request: %s\n", buffer);

    // Forward request to target server
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response from target server
    bzero(buffer, BUFSIZ);
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        perror("read");
        exit(1);
    }

    printf("Received response: %s\n", buffer);

    // Send response back to client
    if (write(new_sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        exit(1);
    }

    printf("Response sent back to client\n");

    // Clean up
    close(new_sockfd);
    close(sockfd);

    return 0;
}