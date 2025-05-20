//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, choice, i, j;
    char operation;

    srand(time(NULL));
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    printf("Welcome to the Arithmetic Game!\n");
    printf("You will be given two numbers and an operation.\n");
    printf("Your task is to perform the operation on the numbers and enter the result.\n");
    printf("If your answer is correct, you will move on to the next level.\n");
    printf("If your answer is incorrect, the game will end.\n");

    do {
        result = 0;
        printf("\nLevel %d\n", rand() % 10 + 1);
        printf("Numbers: %d and %d\n", num1, num2);
        printf("Operation: ");
        scanf("%c", &operation);

        switch(operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if(num2!= 0) {
                    result = num1 / num2;
                } else {
                    printf("Error: Division by zero.\n");
                    exit(0);
                }
                break;
            default:
                printf("Error: Invalid operation.\n");
                exit(0);
        }

        printf("\nEnter your answer: ");
        scanf("%d", &choice);

        if(choice == result) {
            printf("Correct! Moving on to the next level.\n");
        } else {
            printf("Incorrect. Game over.\n");
            exit(0);
        }

        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
    } while(1);

    return 0;
}