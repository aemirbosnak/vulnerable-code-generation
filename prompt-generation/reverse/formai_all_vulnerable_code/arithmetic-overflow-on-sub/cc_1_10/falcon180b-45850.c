//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, choice, i;
    char operand;
    double result;
    time_t start, end;
    double elapsed;

    srand(time(NULL));
    start = clock();
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;
    printf("Welcome to the Medieval Arithmetic Challenge!\n");
    printf("You have been tasked with solving a random arithmetic problem.\n");
    printf("The numbers are %d and %d.\n", num1, num2);
    printf("Choose an operation:\n");
    printf("A - Addition\n");
    printf("S - Subtraction\n");
    printf("M - Multiplication\n");
    printf("D - Division\n");
    scanf("%c", &operand);
    switch (operand) {
        case 'A':
        case 'a':
            result = num1 + num2;
            printf("The result is %.0f.\n", result);
            break;
        case 'S':
        case's':
            result = num1 - num2;
            printf("The result is %.0f.\n", result);
            break;
        case 'M':
        case'm':
            result = num1 * num2;
            printf("The result is %.0f.\n", result);
            break;
        case 'D':
        case 'd':
            if (num2 == 0) {
                printf("Division by zero is not allowed!\n");
            } else {
                result = num1 / num2;
                printf("The result is %.2f.\n", result);
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Congratulations! You solved the problem in %.2f seconds.\n", elapsed);
    return 0;
}