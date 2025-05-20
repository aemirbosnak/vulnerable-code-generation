//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_HISTORY 10

typedef struct {
    char expression[MAX_INPUT_LENGTH];
    double result;
} Calculation;

Calculation history[MAX_HISTORY];
int history_count = 0;

void add_to_history(const char* expression, double result) {
    if (history_count < MAX_HISTORY) {
        strncpy(history[history_count].expression, expression, MAX_INPUT_LENGTH);
        history[history_count].result = result;
        history_count++;
    } else {
        // Shift history left if we reach limit
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        strncpy(history[MAX_HISTORY - 1].expression, expression, MAX_INPUT_LENGTH);
        history[MAX_HISTORY - 1].result = result;
    }
}

void display_history() {
    printf("\nCalculation History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s = %.2f\n", i + 1, history[i].expression, history[i].result);
    }
    printf("\n");
}

double evaluate_expression(const char* expression) {
    // A basic implementation to evaluate simple expressions
    double result = 0;
    char operator;
    double operand;
    const char* ptr = expression;
    
    sscanf(ptr, "%lf", &result);
    
    while (*ptr) {
        operator = *ptr++;
        sscanf(ptr, "%lf", &operand);
        switch (operator) {
            case '+': result += operand; break;
            case '-': result -= operand; break;
            case '*': result *= operand; break;
            case '/': 
                if (operand != 0) result /= operand; 
                else {
                    printf("Error: Division by zero.\n");
                    return 0;
                }
                break;
            case '^': result = pow(result, operand); break;
            default:
                printf("Unknown operator: %c\n", operator);
                return 0;
        }
        ptr += strcspn(ptr, "0123456789-.") + strcspn(ptr, " +-*^/");
    }
    return result;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Welcome to the Sherlock Holmes Scientific Calculator!\n");
    printf("Type your calculation (e.g., 3 + 5 * 2) or 'history' to view past calculations.\n");
    printf("Type 'exit' to leave this realm of mathematical inquiry.\n");

    while (1) {
        printf("\nEnter calculation: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "history") == 0) {
            display_history();
            continue;
        }

        double result = evaluate_expression(input);
        if (result != 0) {
            add_to_history(input, result);
            printf("Result: %.2f\n", result);
        }
    }
    
    printf("Farewell! Until we meet again...\n");
    return 0;
}