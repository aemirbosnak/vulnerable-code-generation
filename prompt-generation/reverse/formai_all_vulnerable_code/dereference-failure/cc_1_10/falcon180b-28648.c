//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct hostent *host;
    struct sockaddr_in servaddr;
    char *ip_address;
    int port;
    char buffer[1024];
    struct timeval timeout;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    ip_address = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    // Set timeout
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // Get host information
    host = gethostbyname(ip_address);
    if (host == NULL) {
        fprintf(stderr, "No such host: %s\n", ip_address);
        exit(1);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);
    servaddr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    // Send data
    strcpy(buffer, "PING");
    numbytes = strlen(buffer);
    if (send(sockfd, buffer, numbytes, 0) == -1) {
        perror("send failed");
        exit(1);
    }

    // Receive data
    numbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (numbytes <= 0) {
        perror("recv failed");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}