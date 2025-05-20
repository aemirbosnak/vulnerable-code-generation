//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buf[100];

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // set up server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000); // port number of server
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("ERROR converting address");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // send message to server
    sprintf(buf, "Hello, World!");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("ERROR sending message");
        exit(EXIT_FAILURE);
    }

    // receive response from server
    n = recv(sockfd, buf, 100, 0);
    if (n < 0) {
        perror("ERROR receiving message");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0'; // null terminate the buffer

    // print the response
    printf("Response from server: %s\n", buf);

    // close the socket
    close(sockfd);

    return 0;
}