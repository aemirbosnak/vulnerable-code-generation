//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct hostent *servinfo;
    struct sockaddr_in servaddr;
    char buff[MAX_BUFF_SIZE];

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(0);
    }

    // Set up server information
    servinfo = gethostbyname(argv[1]);
    if (servinfo == NULL) {
        fprintf(stderr, "No such host: %s\n", argv[1]);
        exit(0);
    }

    // Set up server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy(servinfo->h_addr, &servaddr.sin_addr.s_addr, servinfo->h_length);
    servaddr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(0);
    }

    printf("Connected to %s:%d\n", argv[1], portno);

    // Send message to server
    n = write(sockfd, argv[3], strlen(argv[3]));
    if (n < 0) {
        perror("write failed");
        exit(0);
    }

    // Receive message from server
    n = read(sockfd, buff, MAX_BUFF_SIZE);
    if (n < 0) {
        perror("read failed");
        exit(0);
    }

    printf("Received message from server: %s\n", buff);

    close(sockfd);
    return 0;
}