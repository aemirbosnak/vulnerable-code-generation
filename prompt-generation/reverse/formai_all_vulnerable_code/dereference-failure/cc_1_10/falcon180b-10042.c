//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[256];
    strcpy(hostname, argv[1]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        print_error("Failed to resolve hostname");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        print_error("Failed to create socket");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("Failed to connect to server");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "PING\n");

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        print_error("Failed to send PING request");
    }

    int bytes_received = 0;
    int timeout_count = 0;
    while (bytes_received < 7 && timeout_count < TIMEOUT) {
        bytes_received += recv(sockfd, buffer, BUFFER_SIZE, 0);
        timeout_count++;
        usleep(100000);
    }

    if (bytes_received < 7) {
        print_error("Timeout exceeded");
    }

    close(sockfd);

    if (buffer[0]!= 'P' || buffer[1]!= 'I' || buffer[2]!= 'N' || buffer[3]!= 'G') {
        print_error("Invalid response from server");
    }

    printf("Ping successful\n");
    return 0;
}