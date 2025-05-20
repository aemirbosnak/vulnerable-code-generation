//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP address or hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Host not found.\n");
        return 1;
    }

    char *ip_address = inet_ntoa(*(struct in_addr *)host->h_addr);
    printf("IP address of %s: %s\n", hostname, ip_address);

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Socket creation failed.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed.\n");
        close(sockfd);
        return 1;
    }

    char send_buffer[BUFFER_SIZE] = "GET / HTTP/1.1\r\nHost: ";
    strcat(send_buffer, hostname);
    strcat(send_buffer, "\r\nConnection: close\r\n\r\n");

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) == -1) {
        printf("Error: Send failed.\n");
        close(sockfd);
        return 1;
    }

    char recv_buffer[BUFFER_SIZE];
    memset(recv_buffer, 0, sizeof(recv_buffer));

    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE - 1, 0)) > 0) {
        recv_buffer[bytes_received] = '\0';
        printf("%s", recv_buffer);
    }

    close(sockfd);
    return 0;
}