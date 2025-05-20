//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float amount;
} ExpenseItem;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    ExpenseItem *expenses = malloc(MAX_ITEMS * sizeof(ExpenseItem));
    int num_items = 0;

    while (fscanf(file, "%s %f", expenses[num_items].name, &expenses[num_items].amount) == 2) {
        num_items++;
    }

    fclose(file);

    if (num_items > MAX_ITEMS) {
        printf("Error: Too many expenses\n");
        free(expenses);
        return 1;
    }

    printf("Expense Tracker\n");
    printf("==============\n");

    for (int i = 0; i < num_items; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }

    char command[10];
    while (1) {
        printf("\nEnter command (add/total/quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            ExpenseItem new_expense;
            printf("Enter expense name: ");
            scanf("%s", new_expense.name);
            printf("Enter expense amount: ");
            scanf("%f", &new_expense.amount);

            expenses = realloc(expenses, (num_items + 1) * sizeof(ExpenseItem));
            expenses[num_items++] = new_expense;
        } else if (strcmp(command, "total") == 0) {
            float total = 0.0;
            for (int i = 0; i < num_items; i++) {
                total += expenses[i].amount;
            }
            printf("Total expenses: $%.2f\n", total);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    free(expenses);

    return 0;
}