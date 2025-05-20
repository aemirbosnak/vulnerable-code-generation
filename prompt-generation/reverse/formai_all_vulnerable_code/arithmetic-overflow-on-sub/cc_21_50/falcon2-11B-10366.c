//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number1, number2, operator;
    double result;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &number1, &number2);

    // Input the operator
    printf("Enter the operator: ");
    scanf("%d", &operator);

    // Apply the operator
    switch(operator) {
        case 1:
            result = number1 + number2;
            break;
        case 2:
            result = number1 - number2;
            break;
        case 3:
            result = number1 * number2;
            break;
        case 4:
            result = number1 / number2;
            break;
        case 5:
            result = number1 % number2;
            break;
        case 6:
            result = number1 + number2;
            break;
        case 7:
            result = number1 - number2;
            break;
        case 8:
            result = number1 * number2;
            break;
        case 9:
            result = number1 / number2;
            break;
        case 10:
            result = number1 % number2;
            break;
        case 11:
            result = number1 + number2;
            break;
        case 12:
            result = number1 - number2;
            break;
        case 13:
            result = number1 * number2;
            break;
        case 14:
            result = number1 / number2;
            break;
        case 15:
            result = number1 % number2;
            break;
        case 16:
            result = number1 + number2;
            break;
        case 17:
            result = number1 - number2;
            break;
        case 18:
            result = number1 * number2;
            break;
        case 19:
            result = number1 / number2;
            break;
        case 20:
            result = number1 % number2;
            break;
    }

    // Output the result
    printf("The result is: %lf\n", result);

    return 0;
}