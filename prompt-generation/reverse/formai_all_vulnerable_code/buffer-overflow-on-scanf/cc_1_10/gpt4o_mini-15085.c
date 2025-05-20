//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define constants for the number of samples and states
#define NUM_SAMPLES 8
#define SAMPLE_ACTIVE 0x01  // Binary 00000001
#define SAMPLE_SIGNALED 0x02 // Binary 00000010
#define SAMPLE_COLLECTED 0x04 // Binary 00000100
#define SAMPLE_ANALYZED 0x08 // Binary 00001000

void displaySampleStates(unsigned char sampleStates) {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        unsigned char mask = 1 << i; // Create a mask for the i-th sample
        if (sampleStates & mask) {
            printf("Sample %d: ACTIVE\n", i);
        } else {
            printf("Sample %d: INACTIVE\n", i);
        }
    }
}

void updateSampleStatus(unsigned char* sampleStates, int sampleIndex, unsigned char statusMask) {
    *sampleStates |= (statusMask << sampleIndex);
}

void resetSampleStatus(unsigned char* sampleStates, int sampleIndex, unsigned char statusMask) {
    *sampleStates &= ~(statusMask << sampleIndex);
}

void toggleSampleStatus(unsigned char* sampleStates, int sampleIndex, unsigned char statusMask) {
    *sampleStates ^= (statusMask << sampleIndex);
}

void checkSampleStatus(unsigned char sampleStates, int sampleIndex) {
    unsigned char mask = SAMPLE_ACTIVE << sampleIndex;
    if (sampleStates & mask) {
        printf("Sample %d is ACTIVE.\n", sampleIndex);
    } else {
        printf("Sample %d is INACTIVE.\n", sampleIndex);
    }
}

int main() {
    unsigned char sampleStates = 0; // Initialize all samples to INACTIVE
    int choice, sampleIndex;

    printf("Laboratory Sample Management System\n");
    printf("====================================\n");

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Display Sample States\n");
        printf("2. Activate Sample\n");
        printf("3. Deactivate Sample\n");
        printf("4. Toggle Sample Status\n");
        printf("5. Check Sample Status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySampleStates(sampleStates);
                break;

            case 2:
                printf("Enter Sample Index to Activate (0-%d): ", NUM_SAMPLES - 1);
                scanf("%d", &sampleIndex);
                if (sampleIndex >= 0 && sampleIndex < NUM_SAMPLES) {
                    updateSampleStatus(&sampleStates, sampleIndex, SAMPLE_ACTIVE);
                    printf("Sample %d activated.\n", sampleIndex);
                } else {
                    printf("Invalid Sample Index!\n");
                }
                break;

            case 3:
                printf("Enter Sample Index to Deactivate (0-%d): ", NUM_SAMPLES - 1);
                scanf("%d", &sampleIndex);
                if (sampleIndex >= 0 && sampleIndex < NUM_SAMPLES) {
                    resetSampleStatus(&sampleStates, sampleIndex, SAMPLE_ACTIVE);
                    printf("Sample %d deactivated.\n", sampleIndex);
                } else {
                    printf("Invalid Sample Index!\n");
                }
                break;

            case 4:
                printf("Enter Sample Index to Toggle (0-%d): ", NUM_SAMPLES - 1);
                scanf("%d", &sampleIndex);
                if (sampleIndex >= 0 && sampleIndex < NUM_SAMPLES) {
                    toggleSampleStatus(&sampleStates, sampleIndex, SAMPLE_ACTIVE);
                    printf("Sample %d status toggled.\n", sampleIndex);
                } else {
                    printf("Invalid Sample Index!\n");
                }
                break;

            case 5:
                printf("Enter Sample Index to Check (0-%d): ", NUM_SAMPLES - 1);
                scanf("%d", &sampleIndex);
                if (sampleIndex >= 0 && sampleIndex < NUM_SAMPLES) {
                    checkSampleStatus(sampleStates, sampleIndex);
                } else {
                    printf("Invalid Sample Index!\n");
                }
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}