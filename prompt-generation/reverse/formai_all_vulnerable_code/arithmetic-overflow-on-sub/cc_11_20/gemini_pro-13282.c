//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <poll.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr = *(struct in_addr *) host->h_addr;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("Error: Could not create socket");
        exit(1);
    }

    struct pollfd pfd;
    pfd.fd = sock;
    pfd.events = POLLIN | POLLOUT;

    char buffer[MAX_SIZE];
    memset(buffer, 0, MAX_SIZE);

    int sequence = 0;

    for (;;)
    {
        // Send ping message
        sprintf(buffer, "Ping %d", sequence);
        if (sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *) &addr, sizeof(addr)) < 0)
        {
            perror("Error: Could not send ping message");
            continue;
        }

        // Wait for response
        int poll_result = poll(&pfd, 1, 1000);
        if (poll_result < 0)
        {
            perror("Error: Could not poll socket");
            continue;
        }

        if (poll_result == 0)
        {
            // Timeout
            fprintf(stderr, "Timeout: No response received\n");
        }
        else
        {
            // Response received
            if (pfd.revents & POLLIN)
            {
                int len = recvfrom(sock, buffer, MAX_SIZE, 0, (struct sockaddr *) &addr, sizeof(addr));
                if (len < 0)
                {
                    perror("Error: Could not receive response");
                    continue;
                }

                // Parse response
                int received_sequence = atoi(buffer + 5);
                if (received_sequence != sequence)
                {
                    fprintf(stderr, "Error: Invalid sequence number received\n");
                    continue;
                }

                // Calculate round-trip time
                struct timespec start_time, end_time;
                clock_gettime(CLOCK_MONOTONIC, &start_time);
                clock_gettime(CLOCK_MONOTONIC, &end_time);
                long long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_nsec - start_time.tv_nsec) / 1000;

                printf("Ping %d received. Round-trip time: %lld ms\n", sequence, elapsed_time);
            }
        }

        sequence++;
    }

    close(sock);

    return 0;
}