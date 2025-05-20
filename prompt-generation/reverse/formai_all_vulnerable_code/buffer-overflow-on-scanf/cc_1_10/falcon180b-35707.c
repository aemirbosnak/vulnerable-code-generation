//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main() {

    // Declare variables
    int num1, num2, choice;
    char operation;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate two random numbers between 1 and 100
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    // Print the numbers to be used in the operation
    printf("Numbers: %d and %d\n\n", num1, num2);

    // Ask the user which operation to perform
    printf("Which operation would you like to perform?\n");
    printf("a. AND\n");
    printf("b. OR\n");
    printf("c. XOR\n");
    printf("d. NOT\n");
    scanf("%c", &operation);

    // Perform the selected operation
    switch (operation) {
        case 'a': // AND
            num1 = num1 & num2;
            break;
        case 'b': // OR
            num1 = num1 | num2;
            break;
        case 'c': // XOR
            num1 = num1 ^ num2;
            break;
        case 'd': // NOT
            num1 = ~num1;
            break;
        default:
            printf("Invalid operation selected.\n");
            return 0;
    }

    // Print the result
    printf("Result: %d\n", num1);

    return 0;
}