//Falcon-180B DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, num1, num2, result;
    char playAgain;

    srand(time(0));
    printf("Welcome to the Cyberpunk Calculator!\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;
            result = num1 + num2;
            printf("Result: %d + %d = %d\n", num1, num2, result);
            break;
        case 2:
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;
            result = num1 - num2;
            printf("Result: %d - %d = %d\n", num1, num2, result);
            break;
        case 3:
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;
            result = num1 * num2;
            printf("Result: %d * %d = %d\n", num1, num2, result);
            break;
        case 4:
            num1 = rand() % 100 + 1;
            num2 = rand() % 100 + 1;
            if(num2 == 0) {
                printf("Error: Division by zero!\n");
            } else {
                result = num1 / num2;
                printf("Result: %d / %d = %d\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("Play again? (y/n): ");
    scanf(" %c", &playAgain);
    if(playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        printf("Exiting...\n");
    }

    return 0;
}