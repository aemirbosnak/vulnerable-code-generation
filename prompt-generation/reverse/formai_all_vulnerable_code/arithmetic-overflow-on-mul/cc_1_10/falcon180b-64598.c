//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 100000

int main() {
    int num1, num2, result;
    char choice;
    srand(time(NULL));
    num1 = rand() % MAX_NUM;
    num2 = rand() % MAX_NUM;
    printf("Choose an arithmetic operation:\n");
    printf("A - Addition\n");
    printf("S - Subtraction\n");
    printf("M - Multiplication\n");
    printf("D - Division\n");
    scanf("%c", &choice);

    switch (choice) {
        case 'A':
        case 'a':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 'S':
        case's':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 'M':
        case'm':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 'D':
        case 'd':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f\n", (float)result);
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}