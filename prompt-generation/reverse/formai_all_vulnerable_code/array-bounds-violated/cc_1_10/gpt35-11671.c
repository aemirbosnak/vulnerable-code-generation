//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 8192

// Struct for storing network packets
typedef struct Packet {
    unsigned char data[MAX_INPUT];
    int length;
} Packet;

// Function to check for intrusions
bool is_intrusion(Packet packet) {
    bool is_intrusion = false;

    // Check for known threats
    if (strstr(packet.data, "SELECT * FROM users")) {
        printf("Possible SQL Injection attack detected!\n");
        is_intrusion = true;
    } else if (strstr(packet.data, "rm -rf /")) {
        printf("Possible system deletion attack detected!\n");
        is_intrusion = true;
    }

    return is_intrusion;
}

int main(void) {
    // Declare variables
    Packet packet;
    char input[MAX_INPUT];
    int length;

    // Continue reading packets until user exits
    while (true) {
        // Get user input
        printf("Enter network packet data: ");
        fgets(input, MAX_INPUT, stdin);

        // Trim newline character from input
        length = strlen(input) - 1;
        input[length] = '\0';

        // Copy input into packet
        memcpy(packet.data, input, length);
        packet.length = length;

        // Check for intrusion
        if (is_intrusion(packet)) {
            printf("Intrusion detected!\n");
        } else {
            printf("Packet OK\n");
        }
    }

    // Exit program
    return EXIT_SUCCESS;
}