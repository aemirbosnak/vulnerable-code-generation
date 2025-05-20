//FormAI DATASET v1.0 Category: Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the most pointless calculator ever!\n\n");

    int num1, num2, result, choice, i;
    char operator;

    printf("Please enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    printf("\nChoose an operation:\n");
    printf("1. Add (+)\n");
    printf("2. Subtract (-)\n");
    printf("3. Multiply (*)\n");
    printf("4. Divide (/)\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            operator = '+';
            result = num1 + num2;
            break;
        case 2:
            operator = '-';
            result = num1 - num2;
            break;
        case 3:
            operator = '*';
            result = num1 * num2;
            break;
        case 4:
            if (num2 != 0) {
                operator = '/';
                result = num1 / num2;
            } else {
                printf("You can't divide by zero, silly!\n");
                return 0;
            }
            break;
        default:
            printf("Invalid choice, sorry!\n");
            return 0;
    }

    printf("\nCalculating...\n");

    for (i = 0; i < 3; i++) {
        printf(".");
        sleep(1);
    }

    printf("\n\nThe answer is: %d %c %d = %d\n\n", num1, operator, num2, result);

    printf("I hope you're satisfied with this completely unnecessary calculation!\n");

    return 0;
}