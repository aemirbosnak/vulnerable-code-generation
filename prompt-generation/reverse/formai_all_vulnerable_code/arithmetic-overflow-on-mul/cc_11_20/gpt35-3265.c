//FormAI DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int num1, num2;
    char op;
    bool valid_input = false;

    printf("Please enter two numbers and an operator (+, -, *, /):\n");

    do {
        printf("Enter the first number: ");
        if(scanf("%d", &num1) != 1){
            printf("Invalid input, please enter an integer.\n");
            while(getchar() != '\n');
        }
        else {
            valid_input = true;
        }
    } while(!valid_input);

    valid_input = false;

    do {
        printf("Enter the second number: ");
        if(scanf("%d", &num2) != 1){
            printf("Invalid input, please enter an integer.\n");
            while(getchar() != '\n');
        }
        else {
            valid_input = true;
        }
    } while(!valid_input);

    valid_input = false;

    do {
        printf("Enter the operator (+, -, *, /): ");
        if(scanf(" %c", &op) != 1) {
            printf("Invalid input, please enter a valid operator.\n");
            while(getchar() != '\n');
        }
        else if (op != '+' && op != '-' && op != '*' && op != '/') {
            printf("Invalid input, please enter a valid operator.\n");
            while(getchar() != '\n');
        }
        else {
            valid_input = true;
        }
    } while(!valid_input);

    switch(op){
        case '+':
            printf("%d + %d = %d", num1, num2, num1+num2);
            break;
        case '-':
            printf("%d - %d = %d", num1, num2, num1-num2);
            break;
        case '*':
            printf("%d * %d = %d", num1, num2, num1*num2);
            break;
        case '/':
            if(num2 == 0){
                printf("Cannot divide by zero.");
            }
            else {
                printf("%d / %d = %d", num1, num2, num1/num2);
            }
            break;
    }

    return 0;
}