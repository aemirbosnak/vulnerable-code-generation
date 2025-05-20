//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    // create a socket for sending and receiving data
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0)
    {
        perror("socket creation failed");
        exit(1);
    }

    // get the IP address of the remote host
    char hostname[256];
    gets(hostname);

    // create a ping request message
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1);
    addr.sin_addr.s_addr = inet_addr(hostname);
    char ping_msg[256];
    sprintf(ping_msg, "Ping: %s\n", hostname);

    // send the ping request message to the remote host
    int n = sendto(sock, ping_msg, strlen(ping_msg), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (n < 0)
    {
        perror("sendto");
        exit(1);
    }

    // receive the response message from the remote host
    struct sockaddr_in response_addr;
    socklen_t response_addr_size = sizeof(response_addr);
    char response_msg[256];
    memset(response_msg, 0, sizeof(response_msg));
    int n_bytes = recvfrom(sock, response_msg, sizeof(response_msg), 0, (struct sockaddr *)&response_addr, &response_addr_size);
    if (n_bytes < 0)
    {
        perror("recvfrom");
        exit(1);
    }

    // check if the response message starts with "PONG"
    if (strncmp(response_msg, "PONG", 4)!= 0)
    {
        printf("Received unexpected response: %s\n", response_msg);
        exit(1);
    }

    // close the socket
    close(sock);

    printf("Ping successful!\n");

    return 0;
}