//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define TARGET_ADDRESS "192.168.1.1" // The desired castle address
#define NUMBER_OF_PINGS 5 // Number of heralds to send

// Function to measure the round trip time
long long measure_ping(const char *target) {
    struct timeval start, end;
    int sock;
    struct sockaddr_in castle;

    // Create a socket for our knight
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Failed to create socket for our faithful knight!");
        exit(EXIT_FAILURE);
    }

    // Set the castle details
    castle.sin_family = AF_INET;
    castle.sin_port = htons(8080); // The port where the castle listens
    inet_pton(AF_INET, target, &castle.sin_addr);

    // Get the start time of our heroic mission
    gettimeofday(&start, NULL);

    // Send the ping message
    if (sendto(sock, "Ping", 4, 0, (struct sockaddr*)&castle, sizeof(castle)) < 0) {
        perror("Failed in sending our noble herald!");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Receive the response from the castle
    char buffer[1024];
    socklen_t castle_size = sizeof(castle);
    if (recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&castle, &castle_size) < 0) {
        perror("The castle did not respond!");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Get the end time of our noble quest
    gettimeofday(&end, NULL);

    // Close the socket
    close(sock);

    // Calculate the round-trip time in milliseconds
    long long ping_time = (end.tv_sec - start.tv_sec) * 1000LL + (end.tv_usec - start.tv_usec) / 1000;
    
    return ping_time;
}

// Function for the knight’s quest
void conduct_ping_test() {
    printf("::: The Knight's Ping Quest Commences :::\n");
    printf("Sending trusty heralds to %s... \n", TARGET_ADDRESS);
    
    for (int i = 0; i < NUMBER_OF_PINGS; i++) {
        printf("Herald %d: Dispatching...\n", i + 1);
        long long time_taken = measure_ping(TARGET_ADDRESS);
        printf("Herald %d: The time taken to reach the castle was %lld ms.\n", i + 1, time_taken);
        usleep(1000000); // Wait for a second before sending the next herald
    }
    
    printf("::: The Knight's Ping Quest Concluded :::\n");
}

int main() {
    conduct_ping_test();
    return 0;
}