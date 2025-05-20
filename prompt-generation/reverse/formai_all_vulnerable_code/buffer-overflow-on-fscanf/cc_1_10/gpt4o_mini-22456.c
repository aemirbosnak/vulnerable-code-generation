//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXP_LENGTH 256
#define MAX_HISTORY 10
#define CYBER_GLOW "\033[1;32m"
#define RESET "\033[0m"

typedef struct {
    char history[MAX_HISTORY][MAX_EXP_LENGTH];
    int count;
} History;

void clear_input_buffer() {
    while (getchar() != '\n');
}

void add_history(History *h, const char *exp) {
    if (h->count < MAX_HISTORY) {
        strncpy(h->history[h->count], exp, MAX_EXP_LENGTH);
        h->history[h->count][MAX_EXP_LENGTH - 1] = '\0';
        h->count++;
    } else {
        for (int i = 1; i < MAX_HISTORY; i++)
            strncpy(h->history[i - 1], h->history[i], MAX_EXP_LENGTH);
        strncpy(h->history[MAX_HISTORY - 1], exp, MAX_EXP_LENGTH);
        h->history[MAX_HISTORY - 1][MAX_EXP_LENGTH - 1] = '\0';
    }
}

void print_history(const History *h) {
    printf(CYBER_GLOW "Calculation History:\n" RESET);
    for (int i = 0; i < h->count; i++) {
        printf("%d: %s\n", i + 1, h->history[i]);
    }
}

double evaluate_expression(const char *expression) {
    // Placeholder implementation to evaluate a mathematical expression
    // A real implementation would use a library or parser for complex expressions
    // For demonstration purposes, we're just using eval via a system call (unsafe)
    char cmd[MAX_EXP_LENGTH + 20];
    snprintf(cmd, sizeof(cmd), "echo \"%s\" | bc -l", expression);
    double result;
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen failed");
        return 0;
    }
    fscanf(fp, "%lf", &result);
    pclose(fp);
    return result;
}

void display_menu() {
    printf(CYBER_GLOW "============================\n" RESET);
    printf(CYBER_GLOW "   Cybernetic Calculator    \n" RESET);
    printf(CYBER_GLOW "============================\n" RESET);
    printf("1. Calculate Expression\n");
    printf("2. Show History\n");
    printf("3. Exit\n");
    printf(CYBER_GLOW "============================\n" RESET);
    printf("Choose an option: ");
}

int main() {
    char expression[MAX_EXP_LENGTH];
    History history = { .count = 0 };
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);
        clear_input_buffer();

        switch (option) {
            case 1:
                printf("Enter expression (e.g., 3 + 4 * 2): ");
                fgets(expression, MAX_EXP_LENGTH, stdin);
                expression[strcspn(expression, "\n")] = '\0'; // Remove newline

                double result = evaluate_expression(expression);
                printf(CYBER_GLOW "Result: %.2lf\n" RESET, result);
                
                add_history(&history, expression);
                break;
            case 2:
                print_history(&history);
                break;
            case 3:
                printf(CYBER_GLOW "Exiting the Cybernetic Calculator. Stay sharp!\n" RESET);
                return 0;
            default:
                printf(CYBER_GLOW "Invalid option, try again!\n" RESET);
                break;
        }
    }
    return 0;
}