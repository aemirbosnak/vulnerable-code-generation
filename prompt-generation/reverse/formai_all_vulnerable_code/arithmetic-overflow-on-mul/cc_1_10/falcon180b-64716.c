//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, choice, result;
    char playAgain;

    srand(time(NULL));
    num1 = rand() % 20 + 1;
    num2 = rand() % 20 + 1;

    printf("Two households, both alike in dignity,\n");
    printf("In fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n\n");

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("\nThe result is: %d\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("\nThe result is: %d\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("\nThe result is: %d\n", result);
            break;
        case 4:
            if (num2 == 0) {
                printf("\nCannot divide by zero!\n");
            } else {
                result = num1 / num2;
                printf("\nThe result is: %d\n", result);
            }
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    printf("\nDo you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        printf("\nExiting program...\n");
        return 0;
    }
}