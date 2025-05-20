//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        exit(1);
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: Socket creation failed\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: Connection failed\n");
        exit(1);
    }

    char message[MAX_MESSAGE_SIZE];
    sprintf(message, "PING %s\r\n", hostname);

    if (send(sockfd, message, strlen(message), 0) == -1) {
        fprintf(stderr, "Error: Send failed\n");
        exit(1);
    }

    char response[MAX_MESSAGE_SIZE];
    int bytes_received = recv(sockfd, response, MAX_MESSAGE_SIZE, 0);
    if (bytes_received <= 0) {
        fprintf(stderr, "Error: Receive failed\n");
        exit(1);
    }

    response[bytes_received] = '\0';
    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}