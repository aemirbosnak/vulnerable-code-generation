//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
// Romeo and Juliet Port Scanner
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT_MIN 1024
#define PORT_MAX 65535

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recv_buf[BUF_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("ERROR connecting\n");
        return 1;
    }

    bzero(recv_buf, BUF_SIZE);
    n = recv(sockfd, recv_buf, BUF_SIZE, 0);
    if (n < 0) {
        printf("ERROR reading from socket\n");
        return 1;
    }

    printf("%s\n", recv_buf);

    close(sockfd);

    return 0;
}