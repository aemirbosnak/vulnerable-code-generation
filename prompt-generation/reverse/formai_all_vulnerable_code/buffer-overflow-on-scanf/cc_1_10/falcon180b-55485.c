//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Function to generate a random number between min and max */
double rand_double(double min, double max) {
    return (rand() % 1000000) * (max - min) / 1000000.0 + min;
}

int main() {
    int choice;
    double num1, num2, result;
    char operation;

    /* Seed the random number generator */
    srand(time(NULL));

    /* Menu */
    printf("Welcome to the Math Exercise Program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square root\n");
    scanf("%d", &choice);

    /* Generate random numbers */
    switch (choice) {
        case 1:
            num1 = rand_double(1, 100);
            num2 = rand_double(1, 100);
            printf("The result of %.2f + %.2f is %.2f.\n", num1, num2, num1 + num2);
            break;
        case 2:
            num1 = rand_double(1, 100);
            num2 = rand_double(1, 100);
            printf("The result of %.2f - %.2f is %.2f.\n", num1, num2, num1 - num2);
            break;
        case 3:
            num1 = rand_double(1, 100);
            num2 = rand_double(1, 100);
            printf("The result of %.2f * %.2f is %.2f.\n", num1, num2, num1 * num2);
            break;
        case 4:
            num1 = rand_double(1, 100);
            num2 = rand_double(1, 100);
            if (num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                printf("The result of %.2f / %.2f is %.2f.\n", num1, num2, num1 / num2);
            }
            break;
        case 5:
            num1 = rand_double(1, 100);
            printf("The square root of %.2f is %.2f.\n", num1, sqrt(num1));
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}