//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, num1, num2, result;
    char playAgain;

    srand(time(NULL));
    printf("Welcome to the Cyberpunk Arithmetic Game!\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 2:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 3:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 4:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("Result: %d\n", result);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if(playAgain == 'y' || playAgain == 'Y') {
        main();
    } else {
        printf("Exiting...\n");
        return 0;
    }
}