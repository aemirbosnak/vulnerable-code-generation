//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in target;
    int port;
    char *ip;

    // Check if user provided an IP address and port number
    if (argc!= 3)
    {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    // Convert IP address from string to binary format
    ip = argv[1];
    struct hostent *he = gethostbyname(ip);
    if (he == NULL)
    {
        printf("Invalid IP address\n");
        return 1;
    }
    memcpy(&target.sin_addr.s_addr, he->h_addr, he->h_length);

    // Convert port number from string to integer
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    // Connect to target IP address and port number
    if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == -1)
    {
        printf("Port %d is closed\n", port);
        close(sockfd);
        return 0;
    }

    // Port is open, send data and receive response
    char send_data[] = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
    send(sockfd, send_data, strlen(send_data), 0);
    char recv_data[1024];
    memset(recv_data, 0, sizeof(recv_data));
    recv(sockfd, recv_data, sizeof(recv_data), 0);

    // Print response
    printf("Response: %s\n", recv_data);

    // Close socket
    close(sockfd);

    return 0;
}