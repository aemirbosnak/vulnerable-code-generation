//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to count the number of set bits in an integer
int count_bits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    int n, m, result;
    char choice;

    // Get the first integer from the user
    printf("Enter the first integer: ");
    scanf("%d", &n);

    // Main loop for the bitwise operations
    do {
        printf("\nSelect an operation:\n");
        printf("1. Bitwise AND\n");
        printf("2. Bitwise OR\n");
        printf("3. Bitwise XOR\n");
        printf("4. Bitwise NOT\n");
        printf("5. Count the number of set bits\n");
        printf("6. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the second integer: ");
                scanf("%d", &m);
                result = n & m;
                printf("Result: %d\n", result);
                break;
            case '2':
                printf("Enter the second integer: ");
                scanf("%d", &m);
                result = n | m;
                printf("Result: %d\n", result);
                break;
            case '3':
                printf("Enter the second integer: ");
                scanf("%d", &m);
                result = n ^ m;
                printf("Result: %d\n", result);
                break;
            case '4':
                printf("Result: %d\n", ~n);
                break;
            case '5':
                printf("Number of set bits: %d\n", count_bits(n));
                break;
            case '6':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '6');

    return 0;
}