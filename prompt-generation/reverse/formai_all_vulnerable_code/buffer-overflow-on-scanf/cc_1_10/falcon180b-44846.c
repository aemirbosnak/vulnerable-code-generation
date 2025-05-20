//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, choice;
    char operator;
    float result;

    srand(time(0)); //initialize random seed
    num1 = rand() % 100 + 1; //generate random number between 1 and 100
    num2 = rand() % 100 + 1; //generate another random number between 1 and 100

    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    scanf("%d", &choice); //read user choice

    switch(choice) {
        case 1:
            operator = '+';
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case 2:
            operator = '-';
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case 3:
            operator = '*';
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case 4:
            if(num2!= 0) { //check if division by zero
                operator = '/';
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            } else {
                printf("Error! Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}