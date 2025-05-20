//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int num1, num2, choice;
    char operation;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate two random numbers between 1 and 100
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    // Prompt the user to choose an arithmetic operation
    printf("Choose an arithmetic operation:\n");
    printf("a. Addition\n");
    printf("b. Subtraction\n");
    printf("c. Multiplication\n");
    printf("d. Division\n");
    scanf("%c", &operation);

    // Perform the chosen operation on the two numbers
    switch(operation) {
        case 'a':
        case 'A':
            num1 += num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, num1);
            break;
        case's':
        case 'S':
            num1 -= num2;
            printf("The difference between %d and %d is %d.\n", num1, num2, num1);
            break;
        case'm':
        case 'M':
            num1 *= num2;
            printf("The product of %d and %d is %d.\n", num1, num2, num1);
            break;
        case 'd':
        case 'D':
            if(num2 == 0) {
                printf("Cannot divide by zero.\n");
            } else {
                num1 /= num2;
                printf("The quotient of %d and %d is %d.\n", num1, num2, num1);
            }
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}