//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECKSUM_SIZE 4
#define MAX_DATA_SIZE 1024
#define MAX_NUM_PACKETS 100

typedef struct {
    unsigned char data[MAX_DATA_SIZE];
    unsigned int length;
    unsigned char checksum[CHECKSUM_SIZE];
} packet_t;

unsigned short calculate_checksum(unsigned short *data, unsigned int len) {
    unsigned short sum = 0;
    for (int i = 0; i < len; i += 2) {
        sum += data[i] + data[i+1];
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum = ~sum;
    return sum;
}

void create_packet(packet_t *packet, unsigned char *data, unsigned int len) {
    packet->length = len;
    memcpy(packet->data, data, len);
    packet->checksum[0] = (unsigned char) (calculate_checksum(packet->data, len) & 0xFF);
    packet->checksum[1] = (unsigned char) ((calculate_checksum(packet->data, len) >> 8) & 0xFF);
}

int main() {
    packet_t packets[MAX_NUM_PACKETS];
    unsigned char test_data[MAX_DATA_SIZE] = {0};

    int num_packets = 0;

    printf("Enter number of packets: ");
    scanf("%d", &num_packets);

    printf("Enter data for each packet (max %d bytes):\n", MAX_DATA_SIZE);

    for (int i = 0; i < num_packets; i++) {
        printf("Packet %d:\n", i+1);
        unsigned int len;

        fgets(test_data, MAX_DATA_SIZE, stdin);
        len = strlen(test_data);
        test_data[len] = 0; // Remove newline character

        if (len > MAX_DATA_SIZE - CHECKSUM_SIZE) {
            printf("Data size too large!\n");
            i--;
            continue;
        }

        create_packet(&packets[i], test_data, len);
    }

    printf("\nPacket Data                               Checksum\n");

    for (int i = 0; i < num_packets; i++) {
        printf("%s               ", packets[i].data);
        for (int j = 0; j < CHECKSUM_SIZE; j++) {
            printf("%.2X ", packets[i].checksum[j]);
        }
        printf("\n");
    }

    return 0;
}