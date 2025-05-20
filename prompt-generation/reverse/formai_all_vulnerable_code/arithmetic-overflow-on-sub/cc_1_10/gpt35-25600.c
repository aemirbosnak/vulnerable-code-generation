//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

// Define the values to use in the QoS calculation
#define LOSS_THRESHOLD 10 // % packet loss before QoS is considered poor
#define DELAY_THRESHOLD 100 // ms of delay before QoS is considered poor
#define POOR_QoS 0 // QoS value returned if poor QoS detected
#define FAIR_QoS 1 // QoS value returned if fair QoS detected
#define GOOD_QoS 2 // QoS value returned if good QoS detected

// Define a struct to hold QoS information
struct QoS {
    int packet_loss;
    int delay;
};

// Define a function to check QoS
int check_QoS() {
    int sock, count, len, bytes_read;
    char *host;
    struct hostent *hp;
    struct sockaddr_in server_addr;
    struct QoS qos;
    char buffer[256];
    float loss_percent, delay_ms;
    struct timespec start, stop;

    host = "www.example.com"; // Change this to the target host
    if ((hp = gethostbyname(host)) == NULL) { // Resolve the host name
        perror("DNS resolution failed");
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) { // Create a UDP socket
        perror("Socket creation failed");
        exit(1);
    }

    // Set the server address information
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    memcpy(&server_addr.sin_addr, hp->h_addr, hp->h_length);

    // Send 10 packets and calculate packet loss and delay
    count = 0;
    qos.packet_loss = 0;
    qos.delay = 0;
    while (count < 10) {
        sprintf(buffer, "Packet %d", count);
        if (sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            perror("Packet send failed");
            exit(1);
        }
        clock_gettime(CLOCK_REALTIME, &start);
        len = sizeof(server_addr);
        if ((bytes_read = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &server_addr, &len)) == -1) {
            perror("Packet receive failed");
            exit(1);
        }
        clock_gettime(CLOCK_REALTIME, &stop);
        delay_ms = ((stop.tv_sec - start.tv_sec) * 1000.0) + ((stop.tv_nsec - start.tv_nsec) / 1000000.0);
        if (delay_ms > DELAY_THRESHOLD) { // Check for delay threshold
            return POOR_QoS;
        }
        if (rand() % 100 + 1 <= LOSS_THRESHOLD) { // Check for packet loss threshold
            qos.packet_loss++;
        } else {
            qos.delay += delay_ms;
        }
        count++;
    }

    // Calculate final QoS value
    loss_percent = (float) qos.packet_loss / 10.0 * 100.0;
    delay_ms = (float) qos.delay / (10.0 - qos.packet_loss);
    if (loss_percent > LOSS_THRESHOLD) {
        return POOR_QoS;
    }
    if (delay_ms > DELAY_THRESHOLD) {
        return POOR_QoS;
    }
    return GOOD_QoS;
}

// Define the main function that will execute the QoS check
int main() {
    int QoS;

    // Check QoS and print result
    QoS = check_QoS();
    if (QoS == POOR_QoS) {
        printf("WARNING: Poor QoS detected\n");
    } else if (QoS == FAIR_QoS) {
        printf("INFO: Fair QoS detected\n");
    } else if (QoS == GOOD_QoS) {
        printf("INFO: Good QoS detected\n");
    }

    return 0;
}