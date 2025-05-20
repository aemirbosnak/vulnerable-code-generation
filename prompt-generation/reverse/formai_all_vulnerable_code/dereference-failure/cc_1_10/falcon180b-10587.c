//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LENGTH 256
#define MAX_DATA_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[MAX_HOSTNAME_LENGTH];
    strcpy(hostname, argv[1]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Could not resolve hostname %s\n", hostname);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to host\n");
        exit(1);
    }

    char data[MAX_DATA_LENGTH];
    strcpy(data, "PING");

    if (send(sockfd, data, strlen(data), 0) == -1) {
        printf("Error: Could not send data\n");
        exit(1);
    }

    char response[MAX_DATA_LENGTH];
    memset(response, 0, sizeof(response));

    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        printf("Error: Could not receive response\n");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sockfd);

    return 0;
}