//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void bitwise_operations() {
    // Declare variables
    int num1, num2, choice;
    char operation[10];

    // Initialize variables
    num1 = 0;
    num2 = 0;
    choice = 0;

    // Loop until user chooses to exit
    while (choice!= 4) {
        // Display menu
        printf("\nBitwise Operations Menu:\n");
        printf("1. Bitwise AND\n");
        printf("2. Bitwise OR\n");
        printf("3. Bitwise XOR\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Get user input for numbers and operation
        if (choice!= 4) {
            printf("Enter two numbers separated by a space:\n");
            scanf("%d %d", &num1, &num2);
            printf("Enter the operation (AND/OR/XOR): ");
            scanf("%s", operation);
        }

        // Perform bitwise operation
        switch (choice) {
            case 1:
                printf("Bitwise AND result: %d\n", num1 & num2);
                break;
            case 2:
                printf("Bitwise OR result: %d\n", num1 | num2);
                break;
            case 3:
                printf("Bitwise XOR result: %d\n", num1 ^ num2);
                break;
            default:
                break;
        }
    }
}

int main() {
    bitwise_operations();
    return 0;
}