//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
// C Scientific Calculator Implementation in a Shocked Style
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Declare variables and constants
const int MAX_INPUT = 100;
const int MAX_OUTPUT = 100;

int main() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];
    int n;
    int a, b;

    // Get input from user
    printf("Enter an expression: ");
    scanf("%s", input);

    // Split input into two numbers
    n = 0;
    while (input[n] != '\0' && input[n] != ' ') {
        n++;
    }
    if (n == 0) {
        printf("Invalid input.\n");
        return 1;
    }
    a = atoi(input);
    b = atoi(input + n + 1);

    // Perform calculation
    if (input[n] == '+') {
        n = a + b;
    } else if (input[n] == '-') {
        n = a - b;
    } else if (input[n] == '*') {
        n = a * b;
    } else if (input[n] == '/') {
        n = a / b;
    } else if (input[n] == '^') {
        n = pow(a, b);
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    // Print output
    sprintf(output, "%d", n);
    printf("Result: %s\n", output);

    return 0;
}