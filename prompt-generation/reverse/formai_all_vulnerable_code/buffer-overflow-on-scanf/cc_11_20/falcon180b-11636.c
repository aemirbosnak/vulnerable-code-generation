//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char choice;

    srand(time(NULL));
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    printf("Welcome to the Arithmetic Game!\n\n");
    printf("You will be given two numbers and an operator.\n");
    printf("Your task is to perform the operation and get the correct answer.\n\n");

    do {
        operator = rand() % 4;
        switch(operator) {
            case 0:
                printf("The operation is addition.\n");
                result = num1 + num2;
                break;
            case 1:
                printf("The operation is subtraction.\n");
                result = num1 - num2;
                break;
            case 2:
                printf("The operation is multiplication.\n");
                result = num1 * num2;
                break;
            case 3:
                printf("The operation is division.\n");
                if(num2 == 0) {
                    printf("Cannot divide by zero. Try again.\n");
                    continue;
                }
                result = num1 / num2;
                break;
        }

        printf("The numbers are: %d and %d\n", num1, num2);
        printf("The operator is: ");
        switch(operator) {
            case 0:
                printf("+");
                break;
            case 1:
                printf("-");
                break;
            case 2:
                printf("*");
                break;
            case 3:
                printf("/");
                break;
        }
        printf("\nEnter your answer: ");
        scanf("%d", &choice);

        if(choice == result) {
            printf("Correct! You win!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", result);
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    return 0;
}