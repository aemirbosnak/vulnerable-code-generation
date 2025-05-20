//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Could not connect to server");
        return 1;
    }

    char buffer[1024];
    int n;

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error: Could not receive data from server");
        return 1;
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "USER %s\r\n", argv[2]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: Could not send data to server");
        return 1;
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error: Could not receive data from server");
        return 1;
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", argv[3]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: Could not send data to server");
        return 1;
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error: Could not receive data from server");
        return 1;
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "STAT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: Could not send data to server");
        return 1;
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error: Could not receive data from server");
        return 1;
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: Could not send data to server");
        return 1;
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error: Could not receive data from server");
        return 1;
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "RETR 1\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: Could not send data to server");
        return 1;
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error: Could not receive data from server");
        return 1;
    }

    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error: Could not send data to server");
        return 1;
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error: Could not receive data from server");
        return 1;
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}