//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256

void display_welcome() {
    printf("\n===========================\n");
    printf("  Cybernetic Scientific Calc\n");
    printf("===========================\n");
    printf("In a world overshadowed by neon lights and synthetic dreams,\n");
    printf("The power of mathematics resides in your hands.\n");
    printf("Enter your calculations, and transcend the ordinary.\n");
    printf("Type 'exit' to escape this reality.\n\n");
}

double calculate(char *input) {
    double result = 0.0;
    char operation;
    double num1, num2;

    // Tokenize input based on spaces
    char *token = strtok(input, " ");
    if (token != NULL) {
        sscanf(token, "%lf", &num1);
        token = strtok(NULL, " ");
    }

    if (token != NULL) {
        operation = token[0];
        token = strtok(NULL, " ");
    }

    if (token != NULL) {
        sscanf(token, "%lf", &num2);
    } else {
        num2 = 0; // Default to 0 if no second operand
    }

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
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                result = NAN; // Not a Number
            } else {
                result = num1 / num2;
            }
            break;
        case '^':
            result = pow(num1, num2);
            break;
        case 's':
            result = sin(num1);
            break;
        case 'c':
            result = cos(num1);
            break;
        case 't':
            result = tan(num1);
            break;
        case 'l':
            result = log(num1);
            break;
        default:
            printf("Error: Unknown operation '%c'.\n", operation);
            result = NAN; // Not a Number
            break;
    }

    return result;
}

void clear_buffer() {
    while ((getchar()) != '\n');
}

int main() {
    char input[MAX_INPUT];
    display_welcome();

    while (1) {
        printf(">>> ");
        if (!fgets(input, sizeof(input), stdin)) {
            // Input error or EOF
            break;
        }

        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Escaping the neon grid...\n");
            break;
        }

        double result = calculate(input);
        if (!isnan(result)) {
            printf("Result: %.2f\n", result);
        }
        
        clear_buffer();
    }

    return 0;
}