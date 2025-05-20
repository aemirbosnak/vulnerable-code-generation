//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    int a;
    int b;
    int c;
} myArithmetic;

int main() {
    myArithmetic arithmetic;
    int result;

    srand(time(NULL));

    printf("Welcome to the Mysterious Arithmetic Lab!\n");
    printf("In this lab, we will perform some curious arithmetic operations!\n");
    printf("Please stay focused and do not blink your eyes!\n");
    printf("Press enter to start the lab...\n");
    getchar();

    arithmetic.a = rand() % 10 + 1;
    arithmetic.b = rand() % 10 + 1;

    printf("We have two mysterious numbers, %d and %d.\n", arithmetic.a, arithmetic.b);

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = arithmetic.a + arithmetic.b;
                printf("The result of addition is: %d\n", result);
                break;
            case 2:
                if (arithmetic.b == 0) {
                    printf("Error: Cannot divide by zero!\n");
                    continue;
                }
                result = arithmetic.a - arithmetic.b;
                printf("The result of subtraction is: %d\n", result);
                break;
            case 3:
                result = arithmetic.a * arithmetic.b;
                printf("The result of multiplication is: %d\n", result);
                break;
            case 4:
                if (arithmetic.b == 0) {
                    printf("Error: Cannot divide by zero!\n");
                    continue;
                }
                result = arithmetic.a / arithmetic.b;
                printf("The result of division is: %f\n", (float)result);
                break;
            case 5:
                printf("Thanks for visiting the Mysterious Arithmetic Lab!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        arithmetic.a = rand() % 10 + 1;
        arithmetic.b = rand() % 10 + 1;
    }

    return 0;
}