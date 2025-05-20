//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 100
#define MAX_HISTORY 100

typedef struct {
    char *history[MAX_HISTORY];
    int count;
} History;

void add_to_history(History *history, const char *entry) {
    if (history->count < MAX_HISTORY) {
        history->history[history->count] = strdup(entry);
        history->count++;
    } else {
        free(history->history[0]);
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            history->history[i] = history->history[i + 1];
        }
        history->history[MAX_HISTORY - 1] = strdup(entry);
    }
}

void print_history(const History *history) {
    printf("\n-- Operation History --\n");
    for (int i = 0; i < history->count; i++) {
        printf("%d: %s\n", i + 1, history->history[i]);
    }
    printf("-- End of History --\n");
}

double calculate(const char *input) {
    double result = 0.0;
    char operator = ' ';
    double num = 0.0;
    char *ptr = (char *)input;
    
    // Handle simple operations based on post-apocalyptic logic
    while (*ptr) {
        if (sscanf(ptr, "%lf", &num) == 1) {
            if (operator == ' ') {
                result = num;
            } else {
                switch (operator) {
                    case '+':
                        result += num;
                        break;
                    case '-':
                        result -= num;
                        break;
                    case '*':
                        result *= num;
                        break;
                    case '/':
                        if (num != 0) {
                            result /= num;
                        } else {
                            printf("Division by zero is forbidden in the wasteland!\n");
                        }
                        break;
                    case '^':
                        result = pow(result, num);
                        break;
                }
            }
            while (*ptr != ' ' && *ptr != '\0') ptr++;
            if (*ptr) ptr++; // Skip the space
        } else {
            sscanf(ptr, " %c", &operator);
            ptr++;
        }
    }
    return result;
}

int main() {
    History history = { .count = 0 };
    char input[MAX_INPUT];
    double result;

    printf("Welcome to the Wasteland Scientific Calculator!\n");
    printf("In this desolate world, knowledge is power. Use it wisely.\n");

    while (1) {
        printf("\nEnter your calculation (or type 'exit' to leave, 'history' to view past calculations): ");
        fgets(input, MAX_INPUT, stdin);
        
        // Remove newline character at the end if present
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Fleeing the wasteland. Until next time...\n");
            break;
        } else if (strcmp(input, "history") == 0) {
            print_history(&history);
            continue;
        }

        result = calculate(input);
        printf("Result: %.2f\n", result);

        // Add to history
        char history_entry[MAX_INPUT + 50];
        snprintf(history_entry, sizeof(history_entry), "%s = %.2f", input, result);
        add_to_history(&history, history_entry);
    }

    // Free allocated memory for history
    for (int i = 0; i < history.count; i++) {
        free(history.history[i]);
    }

    return 0;
}