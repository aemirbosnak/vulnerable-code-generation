//FormAI DATASET v1.0 Category: Syntax parsing ; Style: imaginative
// Welcome to the Land of Syntax - a world where imagination meets coding!

#include<stdio.h>

// Defining a structure to store input values

typedef struct inputValues {
    int num1;
    int num2;
    char operator;
} InputValues;

// Defining a function to parse user input

InputValues parseInput(char *input) {

    InputValues values;

    // Splitting the user input into its components - num1, num2, and operator
    sscanf(input, "%d %c %d", &values.num1, &values.operator, &values.num2);

    return values;
}

int main() {

    printf("\nWelcome to the Syntax parser! Please enter your input in the format 'num1 operator num2'\n");

    char input[30];

    // Taking user input and parsing it
    fgets(input, 30, stdin);
    InputValues values = parseInput(input);

    int result;

    // Evaluating the expression based on operator type
    switch(values.operator) {
        case '+':
            result = values.num1 + values.num2;
            break;

        case '-':
            result = values.num1 - values.num2;
            break;

        case '*':
            result = values.num1 * values.num2;
            break;

        case '/':
            result = values.num1 / values.num2;
            break;

        default:
            printf("\nSorry, invalid operator entered\n");
            return -1;
    }

    // Printing the result
    printf("\nThe result of the expression is: %d\n", result);

    return 0;
}