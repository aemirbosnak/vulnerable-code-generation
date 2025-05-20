//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// Ping the server and measure the round-trip time
int ping(char *host, int port, int count) {
    int sock;                        // Socket descriptor
    struct sockaddr_in addr;          // Socket address
    socklen_t addr_len;               // Length of socket address
    char buf[1024];                  // Buffer for receiving and sending data
    int i, n, total_time;
    struct timeval start, end;

    // Create a socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    // Set up the socket address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);
    addr_len = sizeof(addr);

    // Ping the server
    total_time = 0;
    for (i = 0; i < count; i++) {
        // Send a ping message
        sprintf(buf, "PING %d", i);
        n = sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&addr, addr_len);
        if (n < 0) {
            perror("sendto");
            return -1;
        }

        // Start the timer
        gettimeofday(&start, NULL);

        // Receive the ping response
        n = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &addr_len);
        if (n < 0) {
            perror("recvfrom");
            return -1;
        }

        // Stop the timer
        gettimeofday(&end, NULL);

        // Calculate the round-trip time
        total_time += (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    }

    // Close the socket
    close(sock);

    return total_time / count;
}

int main() {
    int port = 80;                  // Port to ping
    int count = 4;                  // Number of pings to send
    char *host = "www.google.com";  // Host to ping

    // Ping the server
    int round_trip_time = ping(host, port, count);

    // Print the results
    if (round_trip_time == -1) {
        printf("Ping failed.\n");
    } else {
        printf("Ping succeeded. Round-trip time: %d ms\n", round_trip_time);
    }

    return 0;
}