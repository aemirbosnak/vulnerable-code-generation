//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct IPEntry {
    char IP[16];
    int count;
};

struct IPEntry table[MAX_ENTRIES] = {}; // initialize to zero

int numEntries = 0;

int findEntry(char *ip) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(table[i].IP, ip) == 0) {
            return i;
        }
    }
    return -1;
}

void addEntry(char *ip) {
    int index = findEntry(ip);
    if (index == -1) { // not found, add a new entry
        if (numEntries < MAX_ENTRIES) { // ensure we don't exceed array bounds
            strcpy(table[numEntries].IP, ip);
            table[numEntries].count = 1;
            numEntries++;
        }
    } else { // found, update count
        table[index].count++;
    }
}

void printTable() {
    printf("IP\t\tCount\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%d\n", table[i].IP, table[i].count);
    }
}

int main() {
    char ip[16];
    int packetCount = 0;

    printf("Intrusion Detection System Active...\n");
    while (1) { // loop indefinitely
        printf("[Packet %d] Enter IP address: ", packetCount + 1);
        scanf("%s", ip);
        addEntry(ip);
        packetCount++;
        if (packetCount % 10 == 0) { // print table every 10 packets
            printTable();
        }
    }

    return 0;
}