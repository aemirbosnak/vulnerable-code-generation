//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int choice;
    int num1, num2, result;
    float num3, num4, result_float;
    char operation;

    srand(time(NULL)); // Seed the random number generator with the current time

    do {
        printf("Welcome to the Visionary Calculator!\n");
        printf("Please select an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two integers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("The result is %d.\n", result);
                break;
            case 2:
                printf("Enter two integers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("The result is %d.\n", result);
                break;
            case 3:
                printf("Enter two integers:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("The result is %d.\n", result);
                break;
            case 4:
                printf("Enter two integers:\n");
                scanf("%d %d", &num1, &num2);
                if(num2 == 0) {
                    printf("Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("The result is %d.\n", result);
                }
                break;
            case 5:
                printf("Enter a number:\n");
                scanf("%f", &num3);
                result_float = sqrt(num3);
                printf("The result is %.2f.\n", result_float);
                break;
            default:
                printf("Invalid operation. Please try again.\n");
                break;
        }

        printf("Press any key to continue...\n");
        getchar();
    } while(1);

    return 0;
}