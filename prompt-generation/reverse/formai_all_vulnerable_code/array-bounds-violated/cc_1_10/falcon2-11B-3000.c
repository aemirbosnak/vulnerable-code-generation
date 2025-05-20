//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: single-threaded
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Resolve server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8080);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send request
    char buf[256];
    sprintf(buf, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    send(sockfd, buf, strlen(buf), 0);

    // Receive response
    bzero(buf, sizeof(buf));
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // Close socket
    close(sockfd);

    return 0;
}