//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in serverAddr;
    struct hostent *serverHost;
    int sockfd;
    int numBytesRecvd;
    char buffer[MAX_SIZE];
    char *result;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    serverHost = gethostbyname(argv[1]);
    if (serverHost == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    memcpy((char*)&serverAddr.sin_addr.s_addr, (char*)serverHost->h_addr, serverHost->h_length);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));

    while (1) {
        numBytesRecvd = recv(sockfd, buffer, sizeof(buffer), 0);
        if (numBytesRecvd < 0) {
            perror("Error receiving data");
            exit(1);
        }

        printf("Received: %s\n", buffer);

        result = (char*)malloc(numBytesRecvd + 1);
        memcpy(result, buffer, numBytesRecvd);
        result[numBytesRecvd] = '\0';

        printf("Sent: %s\n", result);

        free(result);
    }

    close(sockfd);
    return 0;
}