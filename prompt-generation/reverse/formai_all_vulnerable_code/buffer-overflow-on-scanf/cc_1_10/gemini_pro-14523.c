//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // Let's get ready to ping!
    int sockfd; // Our trusty socket file descriptor
    struct sockaddr_in addr; // Destination address, ready to set sail
    char hostname[1024]; // To store the hostname we're aiming for
    char ip_address[1024]; // To keep the IP address close by

    // First, let's create our socket, the gateway to the network
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1)
    {
        perror("Oops! Couldn't create the socket...");
        return 1;
    }

    // Next, let's hear from the user. Where should we send our packets?
    printf("Hello there! Who are we pinging today? Give me a hostname or IP address: ");
    scanf("%s", hostname);

    // Time to translate that friendly hostname into an IP address we can understand
    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0)
    {
        perror("Hmm, that address doesn't seem right. Let's try again:");
        return 1;
    }

    // Now, let's fill in the details of our destination
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0); // ICMP doesn't use ports, but we have to fill it in

    // Let's send out a packet, hoping for a cheerful response
    char packet[1024]; // Our message in a bottle
    memset(packet, 0, sizeof(packet)); // Let's start with a clean slate
    packet[0] = 8; // ICMP type: echo request
    packet[1] = 0; // ICMP code: 0
    struct timeval tv; // To measure the time it takes for our message to reach its destination
    gettimeofday(&tv, NULL); // Let's start the clock!
    memcpy(packet + 8, &tv, sizeof(tv)); // Include the timestamp in our packet
    int sent = sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (sent == -1)
    {
        perror("Oops! Our packet got lost...");
        return 1;
    }

    // Now, let's wait patiently for a response
    struct sockaddr_in recv_addr;
    socklen_t addr_len = sizeof(recv_addr);
    char recv_packet[1024];
    int recv_size = recvfrom(sockfd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr *)&recv_addr, &addr_len);
    if (recv_size == -1)
    {
        perror("No reply from the destination...");
        return 1;
    }

    // Yay, we got a response! Let's see how long it took
    gettimeofday(&tv, NULL);
    struct timeval *recv_tv = (struct timeval *)(recv_packet + 8);
    double time_taken = (double)(tv.tv_sec - recv_tv->tv_sec) + (double)(tv.tv_usec - recv_tv->tv_usec) / 1000000;

    // Okay, let's convert the IP address to a more readable form
    inet_ntop(AF_INET, &recv_addr.sin_addr, ip_address, sizeof(ip_address));

    // And finally, let's share the good news!
    printf("Hurray! We reached %s (%s) in %.3f milliseconds.\n", hostname, ip_address, time_taken);

    // Mission accomplished! Let's close the shop
    close(sockfd);

    return 0;
}