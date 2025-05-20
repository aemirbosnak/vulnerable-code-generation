//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main() {
    //initialize variables
    int num1, num2, operator, result;
    char operation[10];

    //seed random number generator
    srand(time(NULL));

    //get two random numbers
    num1 = rand() % 100;
    num2 = rand() % 100;

    //choose a random operator
    switch(rand() % 4) {
        case 0:
            operator = '+';
            break;
        case 1:
            operator = '-';
            break;
        case 2:
            operator = '*';
            break;
        case 3:
            operator = '/';
            break;
    }

    //perform arithmetic operation
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                return 0;
            }
            result = num1 / num2;
            break;
    }

    //display result
    printf("The result is: %d\n", result);

    //choose a random string operation
    switch(rand() % 3) {
        case 0:
            strcpy(operation, "addition");
            break;
        case 1:
            strcpy(operation, "subtraction");
            break;
        case 2:
            strcpy(operation, "multiplication");
            break;
    }

    //display operation performed
    printf("The operation performed was %s.\n", operation);

    return 0;
}