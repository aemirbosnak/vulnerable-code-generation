//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define a maximum number of digits for the input
#define MAX_DIGITS 1000

int main() {
    char input[MAX_DIGITS];
    int length, i, j, num1, num2, carry, result;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%[^\n]", input);
    length = strlen(input);

    // Reverse the input string
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

    // Convert the input string to an integer
    num1 = atoi(input);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Perform the arithmetic operation
    if (num2 == 0) {
        printf("Division by zero is not allowed.\n");
        exit(1);
    }

    switch (num2) {
        case 1:
            result = num1;
            break;
        case 2:
            result = num1 * 2;
            break;
        case 3:
            result = num1 * 3;
            break;
        case 4:
            result = num1 * 4;
            break;
        case 5:
            result = num1 * 5;
            break;
        case 6:
            result = num1 * 6;
            break;
        case 7:
            result = num1 * 7;
            break;
        case 8:
            result = num1 * 8;
            break;
        case 9:
            result = num1 * 9;
            break;
        default:
            result = num1 + num2;
            break;
    }

    // Convert the result to a string
    char result_str[MAX_DIGITS];
    sprintf(result_str, "%d", result);

    // Reverse the result string
    for (i = 0, j = strlen(result_str) - 1; i < j; i++, j--) {
        char temp = result_str[i];
        result_str[i] = result_str[j];
        result_str[j] = temp;
    }

    // Print the result
    printf("The result is: %s\n", result_str);

    return 0;
}