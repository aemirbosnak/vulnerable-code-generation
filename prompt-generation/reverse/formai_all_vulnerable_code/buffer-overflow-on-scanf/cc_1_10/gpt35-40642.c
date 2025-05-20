//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NETWORK_DEVICES 10
#define MAX_PACKET_SIZE 1024

typedef struct NetworkDevice {
    int id;
    int bandwidth; // measured in megabits per second (Mbps)
    int delay; // measured in milliseconds (ms)
    int packetLossRate; // measured in percentage (%)
} NetworkDevice;

typedef struct Packet {
    int size; // measured in bytes
    int srcId;
    int destId;
} Packet;

typedef struct QoSParams {
    int maxDelay; // measured in ms
    int maxPacketLossRate; // measured in %
} QoSParams;

bool isPacketDelivered(QoSParams *qosParams, int delay, int packetLossRate) {
    return delay <= qosParams->maxDelay && packetLossRate <= qosParams->maxPacketLossRate;
}

int main() {
    int numDevices, i, j;
    Packet packets[MAX_PACKET_SIZE];
    NetworkDevice devices[MAX_NETWORK_DEVICES];
    QoSParams qosParams;

    printf("Enter number of network devices (max 10): ");
    scanf("%d", &numDevices);

    // initialize network devices
    for (i = 0; i < numDevices; i++) {
        devices[i].id = i + 1;
        printf("Enter bandwidth (Mbps) for Device %d: ", devices[i].id);
        scanf("%d", &devices[i].bandwidth);
        printf("Enter delay (ms) for Device %d: ", devices[i].id);
        scanf("%d", &devices[i].delay);
        printf("Enter packet loss rate (%%) for Device %d: ", devices[i].id);
        scanf("%d", &devices[i].packetLossRate);
    }

    printf("Enter maximum tolerable delay (ms): ");
    scanf("%d", &qosParams.maxDelay);
    printf("Enter maximum tolerable packet loss rate (%%): ");
    scanf("%d", &qosParams.maxPacketLossRate);

    // simulate packet transmission and delivery
    int numPackets, numDelivered = 0;
    printf("Enter number of packets to transmit: ");
    scanf("%d", &numPackets);

    for (i = 0; i < numPackets; i++) {
        packets[i].srcId = rand() % numDevices + 1; // choose random source device
        do {
            packets[i].destId = rand() % numDevices + 1; // choose random destination device
        } while (packets[i].srcId == packets[i].destId); // ensure source and destination devices are different
        packets[i].size = rand() % MAX_PACKET_SIZE + 1; // choose random packet size

        // simulate transmission
        int srcIndex = packets[i].srcId - 1;
        int destIndex = packets[i].destId - 1;
        int transmissionTime = (packets[i].size * 8000) / devices[srcIndex].bandwidth; // calculate time to transmit in ms
        int delay = devices[srcIndex].delay + devices[destIndex].delay + transmissionTime; // total delay
        bool isLost = rand() % 100 < devices[srcIndex].packetLossRate; // check if packet is lost

        // simulate delivery
        bool delivered = false;
        if (!isLost) {
            delivered = isPacketDelivered(&qosParams, delay, devices[destIndex].packetLossRate);
            if (delivered) {
                numDelivered++;
            }
        }

        // print packet details
        printf("\nPacket %d:\n", i+1);
        printf("Size: %d bytes\n", packets[i].size);
        printf("Source Device: %d\n", packets[i].srcId);
        printf("Destination Device: %d\n", packets[i].destId);
        printf("Transmission Time: %d ms\n", transmissionTime);
        printf("Total Delay: %d ms\n", delay);
        printf("Packet Loss Rate: %d%%\n", devices[srcIndex].packetLossRate);
        printf("Lost? %s\n", isLost ? "Yes" : "No");
        printf("Delivered? %s\n", delivered ? "Yes" : "No");
    }

    float deliveryRate = (float)numDelivered / numPackets * 100;
    printf("\nPacket Delivery Rate: %.2f%%\n", deliveryRate);

    return 0;
}