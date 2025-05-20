//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to count number of bits set in an integer
int countBits(int num) {
    int count = 0;
    while (num > 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}

int main() {
    int num, choice;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Menu-driven program to perform different bitwise operations
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Count number of bits set\n");
        printf("2. Check if a bit is set\n");
        printf("3. Set a bit\n");
        printf("4. Clear a bit\n");
        printf("5. Toggle a bit\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Number of bits set: %d\n", countBits(num));
                break;
            case 2:
                printf("Enter bit position: ");
                scanf("%d", &choice);
                if (num & (1 << choice)) {
                    printf("Bit %d is set\n", choice);
                } else {
                    printf("Bit %d is not set\n", choice);
                }
                break;
            case 3:
                printf("Enter bit position: ");
                scanf("%d", &choice);
                num |= (1 << choice);
                printf("Bit %d set successfully\n", choice);
                break;
            case 4:
                printf("Enter bit position: ");
                scanf("%d", &choice);
                num &= ~(1 << choice);
                printf("Bit %d cleared successfully\n", choice);
                break;
            case 5:
                printf("Enter bit position: ");
                scanf("%d", &choice);
                num ^= (1 << choice);
                printf("Bit %d toggled successfully\n", choice);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}