//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to print the binary representation of a number
void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); // Space every byte for clarity
    }
    printf("\n");
}

int main() {
    unsigned int num1, num2;
    int choice;
    
    printf("Welcome to the Bitwise Operations Commander!\n");
    printf("Enter two unsigned integers:\n");
    
    printf("Integer 1: ");
    scanf("%u", &num1);
    printf("Integer 2: ");
    scanf("%u", &num2);
    
    do {
        printf("\nChoose a Bitwise Operation:\n");
        printf("1. AND\n");
        printf("2. OR\n");
        printf("3. XOR\n");
        printf("4. NOT (only on first integer)\n");
        printf("5. Shift Left (First Integer)\n");
        printf("6. Shift Right (First Integer)\n");
        printf("7. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                unsigned int result = num1 & num2;
                printf("Result of %u AND %u:\n", num1, num2);
                printf("Binary: ");
                printBinary(result);
                printf("Decimal: %u\n", result);
                break;
            }
            case 2: {
                unsigned int result = num1 | num2;
                printf("Result of %u OR %u:\n", num1, num2);
                printf("Binary: ");
                printBinary(result);
                printf("Decimal: %u\n", result);
                break;
            }
            case 3: {
                unsigned int result = num1 ^ num2;
                printf("Result of %u XOR %u:\n", num1, num2);
                printf("Binary: ");
                printBinary(result);
                printf("Decimal: %u\n", result);
                break;
            }
            case 4: {
                unsigned int result = ~num1;
                printf("Result of NOT %u:\n", num1);
                printf("Binary: ");
                printBinary(result);
                printf("Decimal: %u\n", result);
                break;
            }
            case 5: {
                unsigned int result = num1 << 1;
                printf("Result of %u shifted left:\n", num1);
                printf("Binary: ");
                printBinary(result);
                printf("Decimal: %u\n", result);
                break;
            }
            case 6: {
                unsigned int result = num1 >> 1;
                printf("Result of %u shifted right:\n", num1);
                printf("Binary: ");
                printBinary(result);
                printf("Decimal: %u\n", result);
                break;
            }
            case 7:
                printf("Exiting Bitwise Operations Commander. Brave choice!\n");
                break;
            default:
                printf("Invalid choice! Please try again...\n");
        }
    } while(choice != 7);
    
    return 0;
}