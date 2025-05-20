//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to count set bits in an integer
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int num, i, j, k;
    int choice;

    // Loop until user chooses to exit
    while (1) {
        printf("\nBitwise Operations Menu:\n");
        printf("1. Set a bit\n");
        printf("2. Clear a bit\n");
        printf("3. Toggle a bit\n");
        printf("4. Check if a bit is set\n");
        printf("5. Count set bits\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform selected operation
        switch (choice) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &num);
                printf("Enter the position of the bit to set: ");
                scanf("%d", &i);
                num |= (1 << i);
                printf("Result: %d\n", num);
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d", &num);
                printf("Enter the position of the bit to clear: ");
                scanf("%d", &i);
                num &= ~(1 << i);
                printf("Result: %d\n", num);
                break;
            case 3:
                printf("Enter the number: ");
                scanf("%d", &num);
                printf("Enter the position of the bit to toggle: ");
                scanf("%d", &i);
                num ^= (1 << i);
                printf("Result: %d\n", num);
                break;
            case 4:
                printf("Enter the number: ");
                scanf("%d", &num);
                printf("Enter the position of the bit to check: ");
                scanf("%d", &i);
                if (num & (1 << i))
                    printf("Bit %d is set\n", i);
                else
                    printf("Bit %d is not set\n", i);
                break;
            case 5:
                printf("Enter the number: ");
                scanf("%d", &num);
                int result = countSetBits(num);
                printf("Number of set bits in %d: %d\n", num, result);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}