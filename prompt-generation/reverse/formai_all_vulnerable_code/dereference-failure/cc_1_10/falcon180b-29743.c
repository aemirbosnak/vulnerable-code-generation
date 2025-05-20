//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: irregular
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

int main() {
    int sockfd, newsockfd, portno, clilen, ret;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    puts("Socket created");

    // set the reuse address flag
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    // fill server information
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    puts("Connected to server");

    // receive data from server
    ret = recv(sockfd, buffer, 1024, 0);
    if (ret < 0) {
        perror("recv failed");
        exit(1);
    }

    puts("Received data from server");

    // close socket
    close(sockfd);

    puts("Socket closed");

    return 0;
}