//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, n, sd;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    char *ip = "127.0.0.1";
    int opt = 1;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    // set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    // get port number from command line argument
    if (argc!= 3) {
        fprintf(stderr, "usage: %s <port> <message>\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[1]);

    // fill server structure
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // send message to server
    n = write(sockfd, argv[2], strlen(argv[2]));
    if (n < 0) {
        perror("write failed");
        exit(1);
    }

    // receive response from server
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("read failed");
        exit(1);
    }
    printf("Received response: %s\n", buffer);

    // close socket
    close(sockfd);
    return 0;
}