//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>

#define TRUE   1
#define FALSE  0
#define MAX_SIZE 1000
#define SERVER_PORT 5000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int opt = TRUE;
    int addrlen = sizeof(struct sockaddr_in);
    int n;
    fd_set readfds;
    struct timeval timeout;

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(SERVER_PORT);

    // Set timeout for read operation
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send data to server
    strcpy(send_buffer, "QoS Monitor");
    n = send(sockfd, send_buffer, strlen(send_buffer), 0);

    if (n < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    printf("Data sent to server\n");

    // Receive data from server
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) < 0) {
        perror("select failed");
        exit(EXIT_FAILURE);
    }

    if (FD_ISSET(sockfd, &readfds)) {
        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

        if (n < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        printf("Data received from server: %s\n", recv_buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}