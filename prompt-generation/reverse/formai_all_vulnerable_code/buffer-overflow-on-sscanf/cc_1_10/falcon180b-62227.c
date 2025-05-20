//Falcon-180B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize variables
    int num1 = 0, num2 = 0;
    char input[100];
    int result = 0;

    // Loop until user enters valid input
    while (1) {
        // Prompt user for input
        printf("Enter the first number: ");
        fgets(input, sizeof(input), stdin);

        // Check if input is a valid integer
        if (sscanf(input, "%d", &num1)!= 1) {
            printf("Invalid input! Please enter a valid integer.\n");
        } else {
            break;
        }
    }

    // Loop until user enters valid input
    while (1) {
        // Prompt user for input
        printf("Enter the second number: ");
        fgets(input, sizeof(input), stdin);

        // Check if input is a valid integer
        if (sscanf(input, "%d", &num2)!= 1) {
            printf("Invalid input! Please enter a valid integer.\n");
        } else {
            break;
        }
    }

    // Perform addition and check for overflow
    result = num1 + num2;
    if ((num1 > 0 && result < num1) || (num1 < 0 && result > num1)) {
        printf("Overflow error! Result is too large or too small.\n");
        return 1;
    }

    // Display result
    printf("The result is: %d\n", result);

    return 0;
}