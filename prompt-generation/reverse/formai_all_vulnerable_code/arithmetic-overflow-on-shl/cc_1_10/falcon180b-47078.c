//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>

// Function to count the number of 1's in a binary number
int count_ones(unsigned int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

// Function to reverse the bits in a binary number
unsigned int reverse_bits(unsigned int n) {
    unsigned int reversed = 0;
    int i;
    for (i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            reversed |= (1 << (31 - i));
        }
    }
    return reversed;
}

// Function to check if a binary number is a power of 2
int is_power_of_two(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    while (n > 1) {
        if (n % 2!= 0) {
            return 0;
        }
        n /= 2;
    }
    return 1;
}

int main() {
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Count the number of 1's in a binary number\n");
        printf("2. Reverse the bits in a binary number\n");
        printf("3. Check if a binary number is a power of 2\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%d", &choice);
                printf("Number of 1's in %d is %d\n", choice, count_ones(choice));
                break;
            case 2:
                printf("Enter a binary number: ");
                scanf("%d", &choice);
                printf("Reversed bits of %d is %d\n", choice, reverse_bits(choice));
                break;
            case 3:
                printf("Enter a binary number: ");
                scanf("%d", &choice);
                if (is_power_of_two(choice)) {
                    printf("%d is a power of 2\n", choice);
                } else {
                    printf("%d is not a power of 2\n", choice);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}