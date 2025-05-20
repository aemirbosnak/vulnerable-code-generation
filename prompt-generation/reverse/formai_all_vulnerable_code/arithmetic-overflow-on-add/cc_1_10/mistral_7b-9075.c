//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define SMILE ":-D"
#define FROWNS ":-("

void arithmetic_operation(int num1, int num2, char operation) {
    int result;

    switch (operation) {
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
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("%s\n", FROWNS);
                printf("Error: Division by zero is not allowed.\n");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            printf("%s\n", FROWNS);
            printf("Error: Invalid operation.\n");
            exit(EXIT_FAILURE);
    }

    printf("%d %c %d = %d\n", num1, operation, num2, result);
}

int main() {
    int num1, num2;
    char operation;

    printf("%s\n", SMILE);
    printf("Welcome to the Cheerful Arithmetic Program!\n");
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);
    printf("Please enter an arithmetic operation (+, -, *, /): ");
    scanf(" %c", &operation);

    arithmetic_operation(num1, num2, operation);

    printf("%s\n", SMILE);
    printf("Thank you for using our Cheerful Arithmetic Program!");
    printf("Press ENTER to exit...");
    getchar();
    getchar();
    return EXIT_SUCCESS;
}