//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA 100
#define LANES 10

typedef struct {
    char nobleName[30];
    int packetLoss;
    int responseTime;
    int jitter;
} NetworkLord;

void printQualityOfService(NetworkLord lords[], int count) {
    printf("---- Network Quality of Service Report ----\n");
    for (int i = 0; i < count; i++) {
        printf("Noble: %s\n", lords[i].nobleName);
        printf("  Packet Loss: %d%%\n", lords[i].packetLoss);
        printf("  Response Time: %d ms\n", lords[i].responseTime);
        printf("  Jitter: %d ms\n", lords[i].jitter);
        printf("-------------------------------------------\n");
    }
}

void assessNetworkQuality(NetworkLord *lord) {
    if (lord->packetLoss < 1 && lord->responseTime < 50 && lord->jitter < 10) {
        printf("Noble %s's network is as swift as a galloping steed!\n", lord->nobleName);
    } else if (lord->packetLoss < 5 && lord->responseTime < 100) {
        printf("Noble %s's network is steady but may face the occasional bump in the road.\n", lord->nobleName);
    } else {
        printf("Noble %s's network is plagued by troubles and needs attention!\n", lord->nobleName);
    }
}

void gatherNetworkData(NetworkLord *lord) {
    srand(time(NULL) ^ (getpid() << 16)); // Seeding for randomness based on time and process ID
    snprintf(lord->nobleName, sizeof(lord->nobleName), "Noble %d", rand() % 1000);
    lord->packetLoss = rand() % 10; // Up to 9%
    lord->responseTime = rand() % 300; // Up to 299 ms
    lord->jitter = rand() % 50; // Up to 49 ms
}

int main() {
    NetworkLord lords[LANES];

    printf("Hear ye! Hear ye! Welcome to the Network Quality of Service Monitoring!\n");
    printf("We shall now summon the lords of the land to assess their network domains.\n");

    for (int i = 0; i < LANES; i++) {
        gatherNetworkData(&lords[i]);
        assessNetworkQuality(&lords[i]);
    }

    printQualityOfService(lords, LANES);

    printf("Thus concludes our noble quest for quality in the realm of networking!\n");
    return 0;
}