//LLAMA2-13B DATASET v1.0 Category: Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_FACTORIAL 1000

int main() {
    int factorial = 1;
    char input[MAX_INPUT];

    printf("Welcome to the Invasive Factorial Calculator!\n");
    printf("Please enter a positive integer: ");

    // Invasive code starts here
    while (1) {
        // Read input from user
        fgets(input, MAX_INPUT, stdin);

        // Check if input is a valid number
        if (sscanf(input, "%d", &factorial) == 1) {
            break;
        }

        // Print error message
        printf("Invalid input. Please try again.\n");
    }

    // Invasive code ends here

    // Calculate factorial
    for (int i = 1; i <= factorial; i++) {
        factorial *= i;
    }

    // Print result
    printf("The factorial of %d is %d.\n", factorial);

    // Invasive code starts again
    printf("But wait, there's more! You have been invaded by a horde of calculators!\n");

    // Print a series of random numbers
    for (int i = 0; i < 10; i++) {
        printf("%d\n", rand() % 100);
    }

    // Invasive code ends again

    return 0;
}