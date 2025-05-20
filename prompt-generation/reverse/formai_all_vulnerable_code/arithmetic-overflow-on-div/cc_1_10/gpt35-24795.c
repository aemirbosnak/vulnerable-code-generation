//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>

int main() {
    // ASCII art to display on start-up
    printf("***********************************************\n"
           "*                                             *\n"
           "*           RETRO ARITHMETIC PROGRAM           *\n"
           "*              coded by Chatbot                *\n"
           "*                                             *\n"
           "***********************************************\n\n");

    int num1, num2, result;
    char operation;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter operation to perform (+, -, *, /, %%, ^): ");
    scanf(" %c", &operation);

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
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero.\n");
                return 1;
            }
            break;
        case '%':
            result = num1 % num2;
            break;
        case '^':
            result = 1;
            for(int i=0; i<num2; i++) {
                result *= num1;
            }
            break;
        default:
            printf("Error: Invalid operation.\n");
            return 1;
    }

    printf("\nResult: %d %c %d = %d\n", num1, operation, num2, result);

    // ASCII art to display on program exit
    printf("\n***********************************************\n"
           "*                                             *\n"
           "*            Thank you for using               *\n"
           "*           RETRO ARITHMETIC PROGRAM           *\n"
           "*              coded by Chatbot                *\n"
           "*                                             *\n"
           "***********************************************\n");

    return 0;
}