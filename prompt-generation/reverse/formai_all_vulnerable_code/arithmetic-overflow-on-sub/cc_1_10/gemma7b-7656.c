//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_SUBNET_MASK_LEN 32

int main()
{
    int subnet_mask_len;
    char subnet_mask[MAX_SUBNET_MASK_LEN];
    char host_address[16];
    int host_bits;
    int network_bits;
    struct sockaddr_in server_addr;
    int sockfd;
    char buf[1024];

    // Get the subnet mask length from the user
    printf("Enter the subnet mask length: ");
    scanf("%d", &subnet_mask_len);

    // Get the subnet mask
    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    // Get the host address
    printf("Enter the host address: ");
    scanf("%s", host_address);

    // Calculate the host bits
    host_bits = 32 - subnet_mask_len;

    // Calculate the network bits
    network_bits = subnet_mask_len - 1;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

    // Connect to the server
    server_addr.sin_port = htons(8080);
    server_addr.sin_family = AF_INET;
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send the subnet mask and host address
    sprintf(buf, "Subnet mask: %s\nHost address: %s\nHost bits: %d\nNetwork bits: %d", subnet_mask, host_address, host_bits, network_bits);
    send(sockfd, buf, strlen(buf), 0);

    // Receive the server's response
    recv(sockfd, buf, 1024, 0);

    // Print the server's response
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}