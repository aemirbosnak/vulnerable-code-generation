//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_PACKETS 100

typedef struct packet {
    char data[MAX_SIZE];
    int size;
} Packet;

void capture_packet(Packet *packet) {
    char input[MAX_SIZE];
    printf("Enter packet data: ");
    fgets(input, MAX_SIZE, stdin);
    strncpy(packet->data, input, MAX_SIZE);
    packet->size = strlen(packet->data);
}

void print_packet(Packet packet) {
    printf("Packet: %s\n", packet.data);
    printf("Size: %d\n", packet.size);
}

int main() {
    Packet packets[MAX_PACKETS];
    int num_packets = 0;

    while (num_packets < MAX_PACKETS) {
        printf("Enter 'c' to capture a packet or 'q' to quit: ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'c') {
            capture_packet(&packets[num_packets]);
            num_packets++;
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("\nCaptured packets:\n");
    for (int i = 0; i < num_packets; i++) {
        print_packet(packets[i]);
    }

    return 0;
}