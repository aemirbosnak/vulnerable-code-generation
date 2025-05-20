//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char input[20];
    int length;
    int i;

    srand(time(NULL));

    printf("Welcome to the Arithmetic Calculator!\n");

    while(1) {
        printf("Enter an arithmetic expression (e.g. 2 + 3 * 4): ");
        fgets(input, 20, stdin);

        length = strlen(input);

        // Remove newline character
        input[length - 1] = '\0';

        num1 = atoi(input);

        if(length > 1) {
            // Check for operator
            operator = input[length - 2];

            // Remove operator from input
            input[length - 2] = '\0';

            num2 = atoi(input);

            switch(operator) {
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
                    if(num2 == 0) {
                        printf("Error: Division by zero.\n");
                        continue;
                    }
                    result = num1 / num2;
                    break;
                default:
                    printf("Error: Invalid operator.\n");
                    continue;
            }

            printf("Result: %d\n", result);
        } else {
            // Handle single number input
            printf("Result: %d\n", num1);
        }
    }

    return 0;
}