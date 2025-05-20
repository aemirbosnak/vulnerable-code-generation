//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

void greet_user() {
    printf("🎉 Welcome to the Cheerful C Expression Evaluator! 🎉\n");
    printf("✨ Let's evaluate some simple mathematical expressions! ✨\n");
}

void goodbye_message() {
    printf("🌈 Thank you for using the Cheerful C Expression Evaluator! See you next time! 🌈\n");
}

int parse_and_evaluate(const char *expression) {
    int num1, num2;
    char operator;

    // Read the expression
    if (sscanf(expression, "%d %c %d", &num1, &operator, &num2) != 3) {
        printf("😢 Oops! It seems there was an error parsing your expression.\n");
        return 0;
    }

    // Perform the operation based on the operator
    int result;
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("🎈 The result of %d + %d is: %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("🎈 The result of %d - %d is: %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("🎈 The result of %d * %d is: %d\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("😱 Oh no! Division by zero is not allowed!\n");
                return 0;
            }
            result = num1 / num2;
            printf("🎈 The result of %d / %d is: %d\n", num1, num2, result);
            break;
        default:
            printf("🤔 Hmm... That's not a valid operator!\n");
            return 0;
    }
    return 1;
}

int main() {
    greet_user();

    char expression[MAX_LEN];
    while (1) {
        printf("📝 Please enter a simple expression (e.g., 3 + 2), or type 'exit' to quit: ");
        fgets(expression, sizeof(expression), stdin);

        // Check for exit condition
        if (strncmp(expression, "exit", 4) == 0) {
            goodbye_message();
            break;
        }

        // Parse and evaluate the expression
        parse_and_evaluate(expression);
    }

    return 0;
}