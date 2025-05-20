//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>

#define SIZE 32 // Number of bits in an integer

void print_binary(unsigned int num) {
    int i;
    for (i = SIZE - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    unsigned int num1, num2, result;
    int choice, i;

    // Get user input
    printf("Enter a number (in binary): ");
    scanf("%u", &num1);

    do {
        printf("\nSelect an operation:\n");
        printf("1. OR\n");
        printf("2. AND\n");
        printf("3. XOR\n");
        printf("4. NOT\n");
        printf("5. SHIFT LEFT\n");
        printf("6. SHIFT RIGHT\n");
        printf("7. COMPLEMENT\n");
        printf("8. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // OR operation
            printf("\nEnter second number (in binary): ");
            scanf("%u", &num2);
            result = num1 | num2;
            printf("\nResult: ");
            print_binary(result);
            break;

        case 2: // AND operation
            printf("\nEnter second number (in binary): ");
            scanf("%u", &num2);
            result = num1 & num2;
            printf("\nResult: ");
            print_binary(result);
            break;

        case 3: // XOR operation
            printf("\nEnter second number (in binary): ");
            scanf("%u", &num2);
            result = num1 ^ num2;
            printf("\nResult: ");
            print_binary(result);
            break;

        case 4: // NOT operation
            result = ~num1;
            printf("\nResult: ");
            print_binary(result);
            break;

        case 5: // SHIFT LEFT operation
            printf("\nEnter number of positions to shift: ");
            scanf("%d", &i);
            result = num1 << i;
            printf("\nResult: ");
            print_binary(result);
            break;

        case 6: // SHIFT RIGHT operation
            printf("\nEnter number of positions to shift: ");
            scanf("%d", &i);
            result = num1 >> i;
            printf("\nResult: ");
            print_binary(result);
            break;

        case 7: // COMPLEMENT operation
            result = ~num1;
            printf("\nResult: ");
            print_binary(result);
            break;

        case 8: // EXIT program
            printf("\nExiting program...\n");
            break;

        default:
            printf("\nInvalid choice!\n");
        }

    } while (choice!= 8);

    return 0;
}