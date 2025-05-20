//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *host_name;
    char *port_num;
    int opt = 1;

    // Check if server address and port number are provided as command-line arguments
    if (argc < 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(1);
    }

    host_name = argv[1];
    port_num = argv[2];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set option to reuse address
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        printf("Error setting socket option: %s\n", strerror(errno));
        exit(1);
    }

    // Get server address
    if ((host = gethostbyname(host_name)) == NULL) {
        printf("Error getting host address: %s\n", strerror(errno));
        exit(1);
    }

    // Convert port number to network byte order
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port_num));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send and receive data
    char send_buf[1024];
    char recv_buf[1024];
    int bytes_sent, bytes_recv;
    while (1) {
        memset(send_buf, 0, sizeof(send_buf));
        printf("Enter message to send: ");
        fgets(send_buf, sizeof(send_buf), stdin);
        bytes_sent = send(sockfd, send_buf, strlen(send_buf), 0);
        if (bytes_sent == -1) {
            printf("Error sending message: %s\n", strerror(errno));
            exit(1);
        }
        memset(recv_buf, 0, sizeof(recv_buf));
        bytes_recv = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
        if (bytes_recv == -1) {
            printf("Error receiving message: %s\n", strerror(errno));
            exit(1);
        }
        printf("Received message: %s\n", recv_buf);
    }

    close(sockfd);
    exit(0);
}