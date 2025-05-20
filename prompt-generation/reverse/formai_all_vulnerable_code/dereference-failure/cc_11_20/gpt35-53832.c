//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

    // Command line arguments validation
    if (argc != 3) {
        printf("Usage: %s <server_ip_address> <port_number>\n", argv[0]);
        exit(1);
    }

    // Parse host address and port number
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() error");
        exit(1);
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt() error");
        exit(1);
    }

    // Bind the socket to a local address and port
    struct sockaddr_in local_addr;
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(0);
    if (bind(sockfd, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {
        perror("bind() error");
        exit(1);
    }

    // Connect to the remote host
    struct hostent *he;
    struct in_addr **addr_list;
    if ((he = gethostbyname(host)) == NULL) {
        herror("gethostbyname() error");
        exit(1);
    }
    addr_list = (struct in_addr **)he->h_addr_list;
    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr = *addr_list[0];
    remote_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
        perror("connect() error");
        exit(1);
    }

    // Set the socket to nonblocking mode
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl() error");
        exit(1);
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl() error");
        exit(1);
    }

    // Start sending and receiving data
    char buf[MAX_BUF_SIZE];
    int num_bytes, send_count = 0, recv_count = 0, dropped_count = 0;
    while (1) {

        // Send data
        num_bytes = send(sockfd, buf, MAX_BUF_SIZE, 0);
        if (num_bytes == -1 && errno != EWOULDBLOCK) {
            perror("send() error");
            break;
        }
        else if (num_bytes > 0) {
            send_count++;
        }

        // Receive data
        memset(&buf, 0, MAX_BUF_SIZE);
        num_bytes = recv(sockfd, buf, MAX_BUF_SIZE, 0);
        if (num_bytes == -1 && errno != EWOULDBLOCK) {
            perror("recv() error");
            break;
        }
        else if (num_bytes > 0) {
            recv_count++;
        }
        else if (num_bytes == 0) {
            printf("Connection closed by remote host\n");
            break;
        }

        // Wait for some time before sending another packet
        usleep(1000);

        // Check for dropped packets
        if (send_count > recv_count) {
            dropped_count = send_count - recv_count;
            printf("Packet loss: %d\n", dropped_count);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}