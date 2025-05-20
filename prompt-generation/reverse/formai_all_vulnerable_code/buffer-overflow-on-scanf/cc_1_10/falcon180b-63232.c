//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    double cost;
} ExpenseItem;

int main() {
    int numItems = 0;
    ExpenseItem expenses[MAX_ITEMS];
    char input[100];

    do {
        printf("Enter expense name (or 'done' to finish):\n");
        fgets(input, 100, stdin);

        if (strcmp(input, "done") == 0) {
            break;
        }

        if (numItems >= MAX_ITEMS) {
            printf("Error: Maximum number of items reached.\n");
            exit(1);
        }

        strcpy(expenses[numItems].name, input);
        printf("Enter expense category:\n");
        fgets(input, 100, stdin);
        strcpy(expenses[numItems].category, input);
        printf("Enter expense cost:\n");
        scanf("%lf", &expenses[numItems].cost);
        numItems++;

    } while (1);

    printf("Expense Tracker\n");
    printf("================\n");

    for (int i = 0; i < numItems; i++) {
        printf("%-30s %-30s %10.2f\n", expenses[i].name, expenses[i].category, expenses[i].cost);
    }

    return 0;
}