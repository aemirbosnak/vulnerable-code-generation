//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of an integer
void print_binary(unsigned int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num & 1);
        num >>= 1;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

// Function to perform bitwise operations on two integers
void bitwise_operations(unsigned int num1, unsigned int num2, int operation) {
    switch (operation) {
        case 1: // Bitwise AND
            printf("Result of bitwise AND operation: ");
            printf("%u\n", num1 & num2);
            break;
        case 2: // Bitwise OR
            printf("Result of bitwise OR operation: ");
            printf("%u\n", num1 | num2);
            break;
        case 3: // Bitwise XOR
            printf("Result of bitwise XOR operation: ");
            printf("%u\n", num1 ^ num2);
            break;
        case 4: // Bitwise NOT
            printf("Result of bitwise NOT operation: ");
            printf("%u\n", ~num1);
            break;
        case 5: // Left Shift
            printf("Result of left shift operation: ");
            printf("%u\n", num1 << num2);
            break;
        case 6: // Right Shift
            printf("Result of right shift operation: ");
            printf("%u\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    int choice, operation;
    unsigned int num1, num2;

    do {
        printf("\nEnter two unsigned integers: ");
        scanf("%u %u", &num1, &num2);

        printf("\nEnter the operation you want to perform:\n");
        printf("1. Bitwise AND\n");
        printf("2. Bitwise OR\n");
        printf("3. Bitwise XOR\n");
        printf("4. Bitwise NOT\n");
        printf("5. Left Shift\n");
        printf("6. Right Shift\n");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                bitwise_operations(num1, num2, operation);
                break;
            default:
                printf("Invalid operation!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}