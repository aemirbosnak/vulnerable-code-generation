//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_HISTORY_SIZE 50

typedef struct {
    char* expression;
    double result;
} HistoryEntry;

int historyIndex = 0;
HistoryEntry history[MAX_HISTORY_SIZE];

char inputBuffer[MAX_LINE_LENGTH];

double evaluateExpression(char* expression) {
    double result = 0;
    char* token = strtok(expression, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            result += atof(token);
        } else {
            switch (token[0]) {
                case '+':
                    result += evaluateExpression(strtok(NULL, " "));
                    break;
                case '-':
                    result -= evaluateExpression(strtok(NULL, " "));
                    break;
                case '*':
                    result *= evaluateExpression(strtok(NULL, " "));
                    break;
                case '/':
                    result /= evaluateExpression(strtok(NULL, " "));
                    break;
                case '^':
                    result = pow(result, evaluateExpression(strtok(NULL, " ")));
                    break;
                default:
                    printf("Invalid operator: %c\n", token[0]);
                    exit(1);
            }
        }
        token = strtok(NULL, " ");
    }
    return result;
}

void saveToHistory(char* expression, double result) {
    if (historyIndex >= MAX_HISTORY_SIZE) {
        historyIndex = 0;
    }
    history[historyIndex].expression = strdup(expression);
    history[historyIndex].result = result;
    historyIndex++;
}

void printHistory() {
    printf("History:\n");
    for (int i = 0; i < historyIndex; i++) {
        printf("%d. %s = %.2f\n", i+1, history[i].expression, history[i].result);
    }
}

int main() {
    printf("Welcome to the C Scientific Calculator!\n");
    while (1) {
        printf("Enter an expression or type 'history' to view past calculations: ");
        fgets(inputBuffer, MAX_LINE_LENGTH, stdin);
        char* expression = strtok(inputBuffer, "\n");
        if (strcmp(expression, "history") == 0) {
            printHistory();
        } else {
            double result = evaluateExpression(expression);
            printf("Result: %.2f\n", result);
            saveToHistory(expression, result);
        }
    }
    return 0;
}