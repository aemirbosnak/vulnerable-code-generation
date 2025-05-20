//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of set bits in an integer
int count_bits(int num) {
    int count = 0;
    while (num!= 0) {
        num &= (num - 1);
        count++;
    }
    return count;
}

int main() {
    int num1, num2, result;
    char choice;

    // Prompt user for two integers
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    // Prompt user for operation
    printf("Enter operation (+, -, *, &, |, ^, <<, >>): ");
    scanf(" %c", &choice);

    // Perform operation based on user input
    switch (choice) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '&':
            result = num1 & num2;
            break;
        case '|':
            result = num1 | num2;
            break;
        case '^':
            result = num1 ^ num2;
            break;
        case '<<':
            result = num1 << num2;
            break;
        case '>>':
            result = num1 >> num2;
            break;
        default:
            printf("Invalid operation.\n");
            exit(1);
    }

    // Print result and number of set bits in result
    printf("Result: %d\n", result);
    printf("Number of set bits in result: %d\n", count_bits(result));

    return 0;
}