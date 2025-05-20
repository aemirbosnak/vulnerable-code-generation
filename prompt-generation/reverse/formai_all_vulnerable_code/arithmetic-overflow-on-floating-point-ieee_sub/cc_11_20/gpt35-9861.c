//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
// A Scientific Calculator program in C
// Written in the style of Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num, result;
    int choice;

    printf("Welcome to the Donald Knuth style Scientific Calculator!\n");

    while(1) {
        printf("\nChoose an operation:\n");
        printf("1 - Addition\n");
        printf("2 - Subtraction\n");
        printf("3 - Multiplication\n");
        printf("4 - Division\n");
        printf("5 - Power of 2\n");
        printf("6 - Square Root\n");
        printf("7 - Logarithm (base 10)\n");
        printf("8 - Exit Program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter a number to add: ");
                scanf("%lf", &num);
                result += num;
                printf("Result: %lf\n", result);
                break;
            case 2:
                printf("\nEnter a number to subtract: ");
                scanf("%lf", &num);
                result -= num;
                printf("Result: %lf\n", result);
                break;
            case 3:
                printf("\nEnter a number to multiply: ");
                scanf("%lf", &num);
                result *= num;
                printf("Result: %lf\n", result);
                break;
            case 4:
                printf("\nEnter a number to divide: ");
                scanf("%lf", &num);
                if(num == 0) {
                    printf("Error: Divide by zero\n");
                    break;
                }
                result /= num;
                printf("Result: %lf\n", result);
                break;
            case 5:
                result *= result;
                printf("Result: %lf\n", result);
                break;
            case 6:
                if(result < 0) {
                    printf("Error: Square root of a negative number\n");
                    break;
                }
                result = sqrt(result);
                printf("Result: %lf\n", result);
                break;
            case 7:
                if(result <= 0) {
                    printf("Error: Logarithm of a non-positive number\n");
                    break;
                }
                result = log10(result);
                printf("Result: %lf\n", result);
                break;
            case 8:
                printf("\nThank you for using the Donald Knuth style Scientific Calculator!\n");
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}