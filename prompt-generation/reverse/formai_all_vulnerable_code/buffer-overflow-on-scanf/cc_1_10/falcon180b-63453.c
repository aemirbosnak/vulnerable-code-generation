//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, choice;
    char *operation = "";
    int result = 0;
    int i;

    // Output a welcome message
    printf("Welcome to the Bitwise Operations Program!\n");

    // Output a list of available operations
    printf("\nAvailable operations:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left Shift\n");
    printf("6. Right Shift\n");

    // Get the user's choice of operation
    printf("\nEnter the number of the operation you want to perform: ");
    scanf("%d", &choice);

    // Get the two numbers to perform the operation on
    printf("\nEnter the first number: ");
    scanf("%d", &num1);
    printf("\nEnter the second number: ");
    scanf("%d", &num2);

    // Perform the selected operation
    switch (choice) {
        case 1: // Bitwise AND
            result = num1 & num2;
            operation = "Bitwise AND";
            break;
        case 2: // Bitwise OR
            result = num1 | num2;
            operation = "Bitwise OR";
            break;
        case 3: // Bitwise XOR
            result = num1 ^ num2;
            operation = "Bitwise XOR";
            break;
        case 4: // Bitwise NOT
            result = ~num1;
            operation = "Bitwise NOT";
            break;
        case 5: // Left Shift
            result = num1 << num2;
            operation = "Left Shift";
            break;
        case 6: // Right Shift
            result = num1 >> num2;
            operation = "Right Shift";
            break;
        default: // Invalid choice
            printf("Invalid choice!\n");
            return 1;
    }

    // Output the result
    printf("\nThe result of %s on %d and %d is %d\n", operation, num1, num2, result);

    return 0;
}