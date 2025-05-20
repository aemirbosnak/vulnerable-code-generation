//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
/* 
   C Network Quality of Service (QoS) monitor example program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PACKET_SIZE 4096
#define MAX_IP 16

// Function to calculate the total time taken for a packet to travel from source to destination
long double diffTime(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000LL + end.tv_usec - start.tv_usec;
}

int main(int argc, char *argv[]) {
    struct sockaddr_in remote_addr;
    struct hostent *host;
    char *server_ip;
    int sd, rc, i;
    char *packet;
    char *ptr;
    struct timeval start_time, end_time;

    if (argc < 2) {
        printf("Usage: %s <server-ip>\n", argv[0]);
        exit(1);
    }

    server_ip = argv[1];

    // Create the socket
    sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sd < 0) {
        perror("socket");
        exit(sd);
    }

    // Set timeout value for socket receive
    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;
    if (setsockopt(sd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    // Lookup the IP address of the server
    memset(&remote_addr, 0, sizeof(struct sockaddr_in));
    remote_addr.sin_family = AF_INET;
    host = gethostbyname(server_ip);
    if (host == NULL) {
        printf("Cannot resolve host name\n");
        exit(1);
    }
    memcpy((void *)&remote_addr.sin_addr, host->h_addr_list[0], host->h_length);
    remote_addr.sin_port = htons(9999);

    // Prepare the packet to be sent
    int packet_size = PACKET_SIZE;
    packet = (char *)malloc(packet_size * sizeof(char));
    memset(packet, 'A', packet_size);

    // Loop to send and receive packets
    for (i = 1; i <= 10; i++) {
        printf("Sending packet %d to %s\n", i, inet_ntoa(remote_addr.sin_addr));

        // Record the start time before sending the packet
        gettimeofday(&start_time, NULL);

        // Send the packet to the server
        rc = sendto(sd, packet, packet_size, 0, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr_in));
        if (rc < 0) {
            perror("sendto");
            exit(rc);
        }

        // Receive the packet from the server
        char recv_packet[PACKET_SIZE];
        int addr_len = sizeof(struct sockaddr_in);
        rc = recvfrom(sd, recv_packet, PACKET_SIZE, 0, (struct sockaddr *)&remote_addr, &addr_len);
        if (rc < 0) {
            printf("Packet %d lost\n", i);
            continue;
        }

        // Record the end time after receiving the packet
        gettimeofday(&end_time, NULL);

        // Calculate the total time taken for the packet to travel
        long double time_taken = diffTime(start_time, end_time);

        // Print the details
        printf("Packet %d received from %s in %Lf microseconds\n", i, inet_ntoa(remote_addr.sin_addr), time_taken);
    }

    // Clean up and exit
    free(packet);
    close(sd);
    return 0;
}