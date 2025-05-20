//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, operator;
    char choice;

    srand(time(NULL)); // Seed the random number generator with the current time

    // Loop until the user decides to quit
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Generate a random number\n");
        printf("6. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%d + %d = %d\n", num1, num2, num1 + num2);
                break;
            case '2':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%d - %d = %d\n", num1, num2, num1 - num2);
                break;
            case '3':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%d * %d = %d\n", num1, num2, num1 * num2);
                break;
            case '4':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if (num2 == 0) {
                    printf("Division by zero is not allowed.\n");
                } else {
                    printf("%d / %d = %.2f\n", num1, num2, (float)num1 / (float)num2);
                }
                break;
            case '5':
                printf("Enter the minimum value: ");
                scanf("%d", &num1);
                printf("Enter the maximum value: ");
                scanf("%d", &num2);
                printf("Random number between %d and %d: %d\n", num1, num2, rand_num(num1, num2));
                break;
            case '6':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}