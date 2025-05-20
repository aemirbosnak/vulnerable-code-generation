//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 100

typedef struct {
    char operation[20];
    double operand1;
    double operand2;
    double result;
} HistoryRecord;

HistoryRecord history[MAX_HISTORY];
int history_count = 0;

void add_to_history(const char* operation, double op1, double op2, double res) {
    if (history_count < MAX_HISTORY) {
        snprintf(history[history_count].operation, sizeof(history[history_count].operation), "%s", operation);
        history[history_count].operand1 = op1;
        history[history_count].operand2 = op2;
        history[history_count].result = res;
        history_count++;
    } else {
        printf("Error: History is full!\n");
    }
}

void print_history() {
    printf("\n--- Adventure Log ---\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s of %.2lf and %.2lf = %.2lf\n", 
               i + 1, history[i].operation, 
               history[i].operand1, history[i].operand2, history[i].result);
    }
    printf("----------------------\n");
}

double safe_divide(double numerator, double denominator) {
    if (denominator == 0) {
        printf("Oh no! The Math Wizard cannot divide by zero! 🧙‍♂️\n");
        exit(EXIT_FAILURE);  // Catastrophic failure, end quest
    }
    return numerator / denominator;
}

void perform_operation() {
    double num1, num2, result;
    char operation[20];
    
    printf("Enter the first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Error: Invalid input for first number! Only numbers are accepted.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Error: Invalid input for second number! Only numbers are accepted.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Magic operation (divide or add): ");
    if (scanf("%s", operation) != 1) {
        printf("Error: Invalid operation! Must input 'divide' or 'add'.\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(operation, "divide") == 0) {
        result = safe_divide(num1, num2);
        printf("The result of your division is: %.2lf\n", result);
        add_to_history("Division", num1, num2, result);
    
    } else if (strcmp(operation, "add") == 0) {
        result = num1 + num2;
        printf("The result of your addition is: %.2lf\n", result);
        add_to_history("Addition", num1, num2, result);
    
    } else {
        printf("Error: Unknown operation '%s'! The Math Wizard is puzzled! 🤔\n", operation);
        exit(EXIT_FAILURE);
    }
}

int main() {
    printf("Welcome to the magical land of math with the Math Wizard! 🌟\n");

    while (1) {
        perform_operation();

        char continue_choice;
        printf("Do you wish to perform another operation? (y/n): ");
        scanf(" %c", &continue_choice);
        
        if (continue_choice == 'n' || continue_choice == 'N') {
            printf("The Math Wizard thanks you for your company! 🧙‍♂️✨\n");
            print_history();
            break;
        } else if (continue_choice != 'y' && continue_choice != 'Y') {
            printf("Error: Invalid choice! Only 'y' or 'n' are valid options.\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}