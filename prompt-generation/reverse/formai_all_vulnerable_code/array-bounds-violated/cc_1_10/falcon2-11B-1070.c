//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to the server\n");

    // Send some data to the server
    char buffer[1024];
    bzero(buffer, 1024);
    sprintf(buffer, "Hello, world!");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Receive some data from the server
    bzero(buffer, 1024);
    n = recv(sockfd, buffer, 1024, 0);
    if (n < 0) {
        perror("recv failed");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}