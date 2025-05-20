//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: rigorous
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 80

int main() {
    int sockfd, numbytes;
    struct sockaddr_in servaddr;
    char sendbuf[100], recvbuf[100];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the address structure
    memset((char *) &servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Enter the URL to ping: ");
    scanf("%s", sendbuf);

    if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Receive the response
    if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("Response: %s\n", recvbuf);

    return 0;
}