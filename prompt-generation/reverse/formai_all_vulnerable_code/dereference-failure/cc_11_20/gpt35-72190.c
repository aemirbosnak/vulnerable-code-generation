//FormAI DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT_SEC 1
#define TIMEOUT_USEC 0
#define MAX_RETRIES 3
#define PORT_NUM 80

int main(int argc, char **argv) {
    struct addrinfo hints, *res, *p;
    int sockfd, rv;
    int retry, pack_sent, pack_received;
    struct timeval tv;
    char packet[PACKET_SIZE];
    char address[100];
    uint16_t id, seqnum;
    socklen_t sockaddr_len;
    struct sockaddr_in addr_in;

    // Get the host name from command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }
    strcpy(address, argv[1]);

    // Fill in the hints structure to get address info for the server
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM; // Use UDP

    // Get the address info
    if ((rv = getaddrinfo(address, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(rv));
        return 1;
    }

    // Loop through all the possible addresses and try each one until we can connect
    for (p = res; p != NULL; p = p->ai_next) {
        // Create a socket for the address
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("Error creating socket");
            continue;
        }

        // Connect to the address
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("Error connecting");
            close(sockfd);
            continue;
        }

        break; // We connected successfully
    }

    if (p == NULL) {
        fprintf(stderr, "Error: Unable to connect to %s\n", address);
        return 1;
    }

    // Get the IP address in presentation format
    char ipstr[INET_ADDRSTRLEN];
    struct sockaddr_in *addr = (struct sockaddr_in *)p->ai_addr;
    inet_ntop(AF_INET, &addr->sin_addr, ipstr, sizeof(ipstr));
    printf("Pinging %s (%s):\n", address, ipstr);

    // Seed the random number generator
    srand(time(NULL));

    // Set the timeout for the socket
    tv.tv_sec = TIMEOUT_SEC;
    tv.tv_usec = TIMEOUT_USEC;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof(tv));

    // Prepare the packet
    memset(packet, 0, PACKET_SIZE);
    id = rand() & 0xFFFF;
    seqnum = 0;
    packet[0] = 0x08; // ICMP Echo Request Type
    packet[1] = 0x00; // Code
    packet[2] = 0x00; // Checksum to be overwritten
    packet[3] = 0x00; // Checksum to be overwritten
    memcpy(&packet[4], &id, sizeof(id));
    memcpy(&packet[6], &seqnum, sizeof(seqnum));

    // Calculate the checksum
    uint32_t sum = 0;
    for (int i = 0; i < PACKET_SIZE - 1; i += 2) {
        sum += ((packet[i] << 8) & 0xFF00) + (packet[i + 1] & 0xFF);
    }
    if (PACKET_SIZE & 1) {
        sum += packet[PACKET_SIZE - 1];
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    uint16_t chksum = ~sum;
    memcpy(&packet[2], &chksum, sizeof(chksum));

    // Send and receive packets
    retry = 0;
    pack_sent = 0;
    pack_received = 0;
    while (retry < MAX_RETRIES) {
        ssize_t nbytes = send(sockfd, packet, PACKET_SIZE, 0);

        if (nbytes == -1) {
            perror("Error sending packet");
            retry++;
            continue;
        }

        pack_sent++;

        sockaddr_len = sizeof(addr_in);
        nbytes = recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&addr_in, &sockaddr_len);

        if (nbytes == -1) {
            printf("Request timed out\n");
            retry++;
            continue;
        }

        pack_received++;
        printf("Received packet %d from %s\n", seqnum, inet_ntoa(addr_in.sin_addr));

        sleep(1); // Wait one second before sending next packet

        seqnum++;
    }

    // Report results
    printf("\nPing statistics for %s:\n", address);
    printf("    Packets: Sent = %d, Received = %d, Lost = %d (%.2f%% loss)\n", pack_sent, pack_received, (pack_sent - pack_received), ((float)(pack_sent - pack_received) / pack_sent) * 100);

    // Cleanup
    close(sockfd);
    freeaddrinfo(res);

    return 0;
}