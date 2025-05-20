//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    int len;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Fill in the structure serv_addr with localhost's IP
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send a request
    char request[] = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Receive the response
    char response[1024];
    int num_read;
    while ((num_read = recv(sockfd, response, 1024, 0)) > 0) {
        response[num_read] = '\0';
        printf("%s", response);
    }

    // Close the socket
    close(sockfd);

    return 0;
}