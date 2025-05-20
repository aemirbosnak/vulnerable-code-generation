//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1000
#define DELAY_TIME 2

// Function to calculate network Quality of Service (QoS)
void calculate_QoS(int sock) {
    char buffer[MAX_BUFFER_SIZE];
    int num_packets = 0;
    int total_bytes = 0;
    int start_time = time(NULL);
    
    while(1) {
        // Send a packet to the server
        send(sock, buffer, MAX_BUFFER_SIZE, 0);

        // Receive a packet from the server
        recv(sock, buffer, MAX_BUFFER_SIZE, 0);

        // Count the number of packets and total number of bytes
        num_packets++;
        total_bytes += MAX_BUFFER_SIZE;

        // Calculate the current time and elapsed time
        int current_time = time(NULL);
        int elapsed_time = current_time - start_time;

        // Calculate the bandwidth in Mbps
        float bandwidth = total_bytes / (elapsed_time * 125000.0);

        // Print the current bandwidth and packet loss rate
        printf("Bandwidth: %f Mbps, Packet Loss Rate: %f %%\n", bandwidth, (num_packets - ((float)total_bytes / MAX_BUFFER_SIZE)) / num_packets * 100);

        // Sleep for a short period of time to slow down the loop
        sleep(DELAY_TIME);
    }
}

int main() {
    // Initialize the socket and client address structure
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, '0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server.\n");
        return 1;
    }

    // Start calculating the Quality of Service (QoS)
    calculate_QoS(sock);

    return 0;
}