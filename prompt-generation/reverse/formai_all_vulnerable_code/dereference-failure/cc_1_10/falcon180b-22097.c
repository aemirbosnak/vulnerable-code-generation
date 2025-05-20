//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 5
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    struct hostent *host;
    struct sockaddr_in address;
    int sockfd, retval, attempts = 0;
    char buffer[BUFFER_SIZE];
    struct timeval timeout;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: could not resolve hostname\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    memcpy(&address.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address))!= 0) {
        printf("Error: could not connect to host\n");
        exit(1);
    }

    while (attempts < MAX_ATTEMPTS) {
        memset(buffer, 0, BUFFER_SIZE);
        retval = read(sockfd, buffer, BUFFER_SIZE);
        if (retval <= 0) {
            attempts++;
            continue;
        }
        printf("Response: %s\n", buffer);
        break;
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Error: host did not respond\n");
        exit(1);
    }

    close(sockfd);
    exit(0);
}