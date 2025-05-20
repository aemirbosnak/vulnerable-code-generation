//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname/IP>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error: could not resolve hostname '%s'\n", hostname);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: could not create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: could not connect to host '%s'\n", hostname);
        close(sockfd);
        return 1;
    }

    char send_data[BUFFER_SIZE] = "GET / HTTP/1.1\r\nHost: ";
    strcat(send_data, hostname);
    strcat(send_data, "\r\nConnection: close\r\n\r\n");

    send(sockfd, send_data, strlen(send_data), 0);

    char recv_data[BUFFER_SIZE];
    int bytes_received = 0;

    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    while (bytes_received < BUFFER_SIZE) {
        int ret = recv(sockfd, recv_data + bytes_received, BUFFER_SIZE - bytes_received, 0);

        if (ret <= 0) {
            printf("Error: could not receive data from host '%s'\n", hostname);
            close(sockfd);
            return 1;
        }

        bytes_received += ret;
    }

    close(sockfd);

    printf("Response from host '%s':\n%s", hostname, recv_data);

    return 0;
}