//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 10000

int main() {
    srand(time(NULL));
    int num1, num2;
    int choice;
    int result;

    printf("Welcome to the Ken Thompson style arithmetic program!\n");
    printf("This program will perform basic arithmetic operations on two numbers.\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    num1 = rand() % MAX_NUM;
    num2 = rand() % MAX_NUM;

    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("The result of %d + %d is %d.\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("The result of %d - %d is %d.\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result of %d * %d is %d.\n", num1, num2, result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result of %d / %d is %d.\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid choice. Please choose a valid operation.\n");
    }

    return 0;
}