//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void print_binary(unsigned int num) {
    int i = 31;
    while (num > 0) {
        printf("%d", (num & 1));
        num >>= 1;
        i--;
    }
    while (i >= 0) {
        printf(" ");
        i--;
    }
}

// Function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    unsigned int result;
    switch (operation) {
        case '&': // Bitwise AND
            result = num1 & num2;
            printf("Result of %c operation: ", operation);
            print_binary(result);
            break;
        case '|': // Bitwise OR
            result = num1 | num2;
            printf("Result of %c operation: ", operation);
            print_binary(result);
            break;
        case '^': // Bitwise XOR
            result = num1 ^ num2;
            printf("Result of %c operation: ", operation);
            print_binary(result);
            break;
        case '~': // Bitwise NOT
            result = ~num1;
            printf("Result of %c operation: ", operation);
            print_binary(result);
            break;
        case '<<': // Left shift
            result = num1 << num2;
            printf("Result of %c operation: ", operation);
            print_binary(result);
            break;
        case '>>': // Right shift
            result = num1 >> num2;
            printf("Result of %c operation: ", operation);
            print_binary(result);
            break;
        default:
            printf("Invalid operation!\n");
    }
}

int main() {
    int choice;
    unsigned int num1, num2;

    do {
        printf("\nEnter two numbers:\n");
        scanf("%u %u", &num1, &num2);

        printf("\nEnter the operation:\n");
        printf("1. Bitwise AND\n");
        printf("2. Bitwise OR\n");
        printf("3. Bitwise XOR\n");
        printf("4. Bitwise NOT\n");
        printf("5. Left shift\n");
        printf("6. Right shift\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bitwise_operations(num1, num2, '&');
                break;
            case 2:
                bitwise_operations(num1, num2, '|');
                break;
            case 3:
                bitwise_operations(num1, num2, '^');
                break;
            case 4:
                bitwise_operations(num1, 0, '~');
                break;
            case 5:
                bitwise_operations(num1, num2, '<<');
                break;
            case 6:
                bitwise_operations(num1, num2, '>>');
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}