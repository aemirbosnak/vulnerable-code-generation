//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ATTACK_THRESHOLD 10

struct ip_address {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
};

struct network_packet {
    struct ip_address source_address;
    struct ip_address destination_address;
    char data[1024];
};

struct attack_entry {
    struct ip_address address;
    int count;
};

int main() {
    struct network_packet packets[1000];
    struct attack_entry attacks[100];
    int packet_count = 0;
    int attack_count = 0;
    int i, j;
    char input[1024];

    printf("Welcome to the Intrusion Detection System!\n");

    while (1) {
        printf("Please input a network packet (source_address.octet1 source_address.octet2 source_address.octet3 source_address.octet4 destination_address.octet1 destination_address.octet2 destination_address.octet3 destination_address.octet4 data):\n");
        fgets(input, 1024, stdin);

        if (strlen(input) <= 1) {
            break;
        }

        struct network_packet packet;
        sscanf(input, "%d %d %d %d %d %d %d %d %[^\n]s", 
            &packet.source_address.octet1, &packet.source_address.octet2, 
            &packet.source_address.octet3, &packet.source_address.octet4, 
            &packet.destination_address.octet1, &packet.destination_address.octet2,
            &packet.destination_address.octet3, &packet.destination_address.octet4,
            packet.data);

        packets[packet_count] = packet;
        packet_count++;

        // Check for attack
        int source_exists = 0;
        for (i = 0; i < attack_count; i++) {
            if (packets[packet_count-1].source_address.octet1 == attacks[i].address.octet1 && 
                    packets[packet_count-1].source_address.octet2 == attacks[i].address.octet2 &&
                    packets[packet_count-1].source_address.octet3 == attacks[i].address.octet3 &&
                    packets[packet_count-1].source_address.octet4 == attacks[i].address.octet4) {
                attacks[i].count++;
                source_exists = 1;
                break;
            }
        }

        if (!source_exists) {
            struct attack_entry entry;
            entry.address = packets[packet_count-1].source_address;
            entry.count = 1;
            attacks[attack_count] = entry;
            attack_count++;
        }

        if (attacks[i].count >= ATTACK_THRESHOLD) {
            printf("ALERT: Possible attack detected from %d.%d.%d.%d!\n", attacks[i].address.octet1,
                    attacks[i].address.octet2, attacks[i].address.octet3, attacks[i].address.octet4);
        }
    }

    return 0;
}