//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <arpa/inet.h>
#include <netinet/tcp.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    portno = accept(sockfd, (struct sockaddr *)&serv_addr, (socklen_t*)&n);

    if (portno < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    char buffer[1024];
    while (1) {
        n = recv(portno, buffer, 1024, 0);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        buffer[n] = '\0';
        printf("%s", buffer);
        send(portno, buffer, strlen(buffer), 0);
    }

    close(portno);
    return 0;
}