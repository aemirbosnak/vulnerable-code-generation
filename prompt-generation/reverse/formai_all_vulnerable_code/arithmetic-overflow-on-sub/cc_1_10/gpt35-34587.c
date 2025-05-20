//FormAI DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PACKETSIZE 64
#define PINGCOUNT 10

// Surreal function that returns a random number between 1 and 100.
int random_number() {
    time_t t;
    srand((unsigned) time(&t));
    return rand() % 100 + 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return -1;
    }

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0) {
        perror("Socket Error");
        return -1;
    }

    // Surreal message that introduces the program and its purpose.
    printf("Welcome to the world of the Ping Test!\n");
    printf("We will now test the connection to %s\n", argv[1]);
    printf("Let's get started...\n\n");

    // Surreal variables that store the total ping time and the average ping time.
    float total_ping_time = 0.0;
    float avg_ping_time = 0.0;

    for (int i = 1; i <= PINGCOUNT; i++) {
        char ping_packet[PACKETSIZE];
        memset(ping_packet, 0, sizeof(ping_packet));
        struct icmp *icmp_hdr = (struct icmp *) ping_packet;

        icmp_hdr->icmp_type = ICMP_ECHO;
        icmp_hdr->icmp_code = 0;
        icmp_hdr->icmp_id = getpid();
        icmp_hdr->icmp_seq = i;
        icmp_hdr->icmp_cksum = 0;
        icmp_hdr->icmp_cksum = htons(~(0xFFFF &
                (ICMP_ECHO << 8) +
                ICMP_ECHO));

        sendto(sockfd, ping_packet, sizeof(ping_packet), 0, (struct sockaddr *) &dest_addr, sizeof(dest_addr));

        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        unsigned int len = sizeof(dest_addr);
        char recv_packet[PACKETSIZE];

        recvfrom(sockfd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr *) &dest_addr, &len);

        gettimeofday(&end_time, NULL);

        long elapsed_time = ((end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec)) / 1000;

        // Surreal output that displays the ping result for each packet.
        printf("Ping packet %d\tTime %ld ms\n", i, elapsed_time);

        // Surreal logic that randomly decides if a packet was lost or not.
        if (random_number() > 50) {
            total_ping_time += (float) elapsed_time;
        }
        else {
            printf("Ping packet %d is lost\n", i);
        }

        // Surreal delay that makes the ping test more unpredictable and interesting.
        usleep(random_number() * 1000);
    }

    // Surreal logic that displays the overall ping statistics.
    avg_ping_time = total_ping_time / (float) PINGCOUNT;
    printf("\n--- Ping Test Result ---\n");
    printf("Sent = %d, Received = %d, Lost = %d (%d%% loss), Average time = %.2f ms\n",
           PINGCOUNT, (int) (total_ping_time / avg_ping_time),
           PINGCOUNT - (int) (total_ping_time / avg_ping_time),
           (int) ((PINGCOUNT - (total_ping_time / avg_ping_time)) / (float) PINGCOUNT * 100.0),
           avg_ping_time);

    // Surreal message that bids farewell to the user.
    printf("\nThank you for testing the connection to %s using our Ping Test program!\n", argv[1]);

    close(sockfd);

    return 0;
}