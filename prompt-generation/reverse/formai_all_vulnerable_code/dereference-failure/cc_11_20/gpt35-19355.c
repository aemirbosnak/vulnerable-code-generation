//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mind-bending
//This is a mind-bending example for a C Network Quality of Service (QoS) monitor program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NetworkElement {
    int id;
    char* name;
    int type; //0=router, 1=switch, 2=host
    int numInterfaces;
    float bandwidth;
};

struct Packet {
    int id;
    int srcId;
    int dstId;
    float size;
    int type; //0=web, 1=video, 2=voice
};

int main() {
    srand(time(NULL));
    int numElements = 5;
    struct NetworkElement* network = malloc(numElements * sizeof(struct NetworkElement));
    char* names[] = {"Router1", "Switch1", "Host1", "Host2", "Host3", "Host4"};
    for (int i = 0; i < numElements; i++) {
        network[i].id = i;
        network[i].name = names[i];
        if (i == 0 || i == 1) {
            network[i].type = 0;
            network[i].numInterfaces = 2;
            network[i].bandwidth = 10000.0;
        } else {
            network[i].type = 2;
            network[i].numInterfaces = 1;
            network[i].bandwidth = 1000.0;
        }
    }
    int numPackets = 10;
    struct Packet* packets = malloc(numPackets * sizeof(struct Packet));
    for (int i = 0; i < numPackets; i++) {
        packets[i].id = i;
        packets[i].srcId = rand() % 4 + 1;
        packets[i].dstId = rand() % 4 + 1;
        packets[i].size = rand() % 100 + 1;
        packets[i].type = rand() % 3;
    }
    float** trafficMatrix = malloc(numElements * sizeof(float*));
    for (int i = 0; i < numElements; i++) {
        trafficMatrix[i] = malloc(numElements * sizeof(float));
        for (int j = 0; j < numElements; j++) {
            trafficMatrix[i][j] = 0.0;
        }
    }
    for (int i = 0; i < numPackets; i++) {
        trafficMatrix[packets[i].srcId][packets[i].dstId] += packets[i].size;
    }
    for (int i = 0; i < numElements; i++) {
        for (int j = 0; j < numElements; j++) {
            if (i != j && trafficMatrix[i][j] > 0.0) {
                printf("%s sent %.2f MB of data to %s\n", network[i].name, trafficMatrix[i][j], network[j].name);
            }
        }
    }
    for (int i = 0; i < numElements; i++) {
        free(trafficMatrix[i]);
    }
    free(trafficMatrix);
    free(packets);
    free(network);
    return 0;
}