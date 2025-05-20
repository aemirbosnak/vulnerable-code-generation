//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_HISTORY 100

typedef struct {
    char operation[20];
    double operand1;
    double operand2;
    double result;
} HistoryEntry;

typedef struct {
    HistoryEntry entries[MAX_HISTORY];
    int count;
} CalculatorHistory;

CalculatorHistory history;

void add_to_history(const char *operation, double operand1, double operand2, double result) {
    if (history.count < MAX_HISTORY) {
        snprintf(history.entries[history.count].operation, 20, "%s", operation);
        history.entries[history.count].operand1 = operand1;
        history.entries[history.count].operand2 = operand2;
        history.entries[history.count].result = result;
        history.count++;
    } else {
        printf("History is full, cannot add another entry!\n");
    }
}

void show_history() {
    printf("\n--- Calculation History ---\n");
    for (int i = 0; i < history.count; i++) {
        printf("%d: %s %.2f and %.2f = %.2f\n", i + 1, 
                history.entries[i].operation, 
                history.entries[i].operand1, 
                history.entries[i].operand2, 
                history.entries[i].result);
    }
}

double add(double a, double b) {
    double result = a + b;
    add_to_history("Addition", a, b, result);
    return result;
}

double subtract(double a, double b) {
    double result = a - b;
    add_to_history("Subtraction", a, b, result);
    return result;
}

double multiply(double a, double b) {
    double result = a * b;
    add_to_history("Multiplication", a, b, result);
    return result;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return NAN; // Not a Number
    }
    double result = a / b;
    add_to_history("Division", a, b, result);
    return result;
}

double calculate_square_root(double a) {
    if (a < 0) {
        printf("Error: Cannot take the square root of a negative number!\n");
        return NAN;
    }
    double result = sqrt(a);
    add_to_history("Square Root", a, 0, result);
    return result;
}

void paranoid_user_input(char *input, int length) {
    // Seriously take care of those inputs
    if (length < 1) {
        printf("Insufficient buffer length!\n");
        exit(EXIT_FAILURE);
    }
    printf("User, please enter your value (be careful): ");
    fgets(input, length, stdin);
}

bool validate_input(const char *input) {
    char *endptr;
    strtod(input, &endptr);
    return *endptr == '\n' || *endptr == '\0'; // only accept valid numbers
}

void perform_calculation() {
    char input1[20], input2[20];
    char operation;

    printf("Welcome to the Paranoid Scientific Calculator!\n");
    printf("Select operation (+, -, *, /, r for sqrt): ");
    operation = getchar();
    getchar(); // consume newline

    if (operation == 'r') {
        paranoid_user_input(input1, sizeof(input1));
        if (validate_input(input1)) {
            double num = strtod(input1, NULL);
            double result = calculate_square_root(num);
            printf("Result: %.2f\n", result);
        } else {
            printf("Invalid input detected!\n");
        }
    } else {
        paranoid_user_input(input1, sizeof(input1));
        paranoid_user_input(input2, sizeof(input2));
        if (validate_input(input1) && validate_input(input2)) {
            double num1 = strtod(input1, NULL);
            double num2 = strtod(input2, NULL);
            double result;

            switch (operation) {
                case '+':
                    result = add(num1, num2);
                    break;
                case '-':
                    result = subtract(num1, num2);
                    break;
                case '*':
                    result = multiply(num1, num2);
                    break;
                case '/':
                    result = divide(num1, num2);
                    break;
                default:
                    printf("Invalid operation!\n");
                    return;
            }
            printf("Result: %.2f\n", result);
        } else {
            printf("Invalid inputs detected!\n");
        }
    }

    // Show history if user wants to
    char showHistory;
    printf("Do you want to see the calculation history? (y/n): ");
    scanf(" %c", &showHistory);
    if (showHistory == 'y') {
        show_history();
    }
}

int main() {
    history.count = 0;

    while (true) {
        perform_calculation();
        char continueCalc;
        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &continueCalc);
        if (continueCalc != 'y') {
            printf("Goodbye! Stay safe and happy calculating!\n");
            break;
        }
    }

    return 0;
}