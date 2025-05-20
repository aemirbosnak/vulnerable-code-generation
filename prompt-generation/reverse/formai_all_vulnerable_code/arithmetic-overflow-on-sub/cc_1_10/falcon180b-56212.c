//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, result;
    char choice;
    printf("Welcome to the Puzzling Arithmetic Program!\n");
    printf("Please choose an operation:\n");
    printf("A - Addition\n");
    printf("S - Subtraction\n");
    printf("M - Multiplication\n");
    printf("D - Division\n");
    scanf("%c", &choice);
    switch(choice) {
        case 'A':
        case 'a':
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 'S':
        case's':
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 'M':
        case'm':
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 'D':
        case 'd':
            printf("Enter two numbers: ");
            scanf("%d%d", &num1, &num2);
            if(num2 == 0) {
                printf("Cannot divide by zero!\n");
            }
            else {
                result = num1 / num2;
                printf("Result: %d\n", result);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}