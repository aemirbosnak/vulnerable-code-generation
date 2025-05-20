//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multiplayer
#include <stdio.h>

#define MAX_PLAYERS 4

// Function to calculate the checksum of given data buffer
int calculate_checksum(unsigned char *data, int length) {
    int checksum = 0;
    for(int i = 0; i < length; i++) {
        checksum += data[i];
    }
    return checksum;
}

// Function to send data to all players and receive their checksums
void send_data_and_receive_checksums(unsigned char *data, int length, int *checksums) {
    printf("Sending data to all players...\n");
    for(int i = 0; i < MAX_PLAYERS; i++) {
        printf("Sending data to player %d\n", i+1);
        // Send data to player i
        // ...
        // Receive checksum from player i
        printf("Receiving checksum from player %d\n", i+1);
        scanf("%d", &checksums[i]);
    }
    printf("Received checksums from all players.\n");
}

// Function to verify the checksums received from players
int verify_checksums(int *checksums) {
    for(int i = 0; i < MAX_PLAYERS; i++) {
        for(int j = i+1; j < MAX_PLAYERS; j++) {
            if(checksums[i] != checksums[j]) {
                return 0; // Checksums do not match
            }
        }
    }
    return 1; // Checksums match
}

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04};
    int checksums[MAX_PLAYERS];
    send_data_and_receive_checksums(data, 4, checksums);
    if(verify_checksums(checksums)) {
        printf("Checksums match! Data is valid.\n");
    }
    else {
        printf("Checksums do not match! Data is corrupt.\n");
    }
    return 0;
}