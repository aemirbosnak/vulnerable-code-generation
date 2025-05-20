//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct in_addr server_addr;
    if (inet_pton(AF_INET, ip_address, &server_addr) <= 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr_in;
    memset(&server_addr_in, 0, sizeof(server_addr_in));
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_addr.s_addr = server_addr.s_addr;
    server_addr_in.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&server_addr_in, sizeof(server_addr_in)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", ip_address);

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending request\n");
        close(sockfd);
        return 1;
    }

    int bytes_received = 0;
    char response[BUFFER_SIZE];
    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    close(sockfd);
    return 0;
}