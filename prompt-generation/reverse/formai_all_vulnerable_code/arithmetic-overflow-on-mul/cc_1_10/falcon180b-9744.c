//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAX_DIGITS 1000000

int main(void) {
    int num1 = 0, num2 = 1, nextTerm, i, j, termCount = 0;
    char fibString[MAX_DIGITS];
    srand(time(NULL));

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");

    // Prompt user for number of terms to display
    printf("Enter the number of terms to display: ");
    scanf("%d", &num1);

    // Validate user input
    if (num1 <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Generate Fibonacci sequence up to num1 terms
    for (i = 0; i < num1; i++) {
        nextTerm = (num1 % 2 == 0)? num1 / 2 : (3 * num1 + 1);
        while (nextTerm % 2 == 0) {
            nextTerm /= 2;
        }
        num1 = num2;
        num2 = nextTerm;
        termCount++;
    }

    // Print Fibonacci sequence
    printf("\nThe Fibonacci sequence up to %d terms is:\n", num1);
    for (i = 0; i < num1; i++) {
        j = 0;
        while (num1 > 0) {
            fibString[j++] = (num1 % 10) + '0';
            num1 /= 10;
        }
        printf("%s ", fibString);
        fibString[0] = '\0';
    }
    printf("\n");

    // Print total number of terms generated
    printf("Total number of terms generated: %d\n", termCount);

    return 0;
}