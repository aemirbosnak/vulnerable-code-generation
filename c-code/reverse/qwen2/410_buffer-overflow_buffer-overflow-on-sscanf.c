#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("Error opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);

    if (inet_pton(AF_INET, "pop3.example.com", &serv_addr.sin_addr) <= 0)
        error("Invalid address/ Address not supported");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Connection Failed");

    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    send(sockfd, "USER username\r\n", 15, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    send(sockfd, "PASS password\r\n", 15, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    send(sockfd, "STAT\r\n", 6, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    send(sockfd, "LIST\r\n", 6, 0);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s\n", buffer);

    // Intentional buffer overflow vulnerability
    sscanf(buffer, "%*d %*d %s", buffer); // Vulnerable line

    close(sockfd);
    return 0;
}
