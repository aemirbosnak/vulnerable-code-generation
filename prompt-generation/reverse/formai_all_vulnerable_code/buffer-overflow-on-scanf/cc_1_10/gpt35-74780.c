//FormAI DATASET v1.0 Category: Expense Tracker ; Style: dynamic
// C Expense Tracker Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char name[50];
    float amount;
};

void addExpense(struct expense *expenses, int *count);
void viewExpenses(struct expense *expenses, int count);
void saveExpenses(struct expense *expenses, int count);

int main () {
    struct expense expenses[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n\n");
        printf("Expense Tracker\n");
        printf("===============\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Save Expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&expenses[count], &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                saveExpenses(expenses, count);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addExpense(struct expense *expenses, int *count) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*count].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    printf("Expense added successfully!\n");
    (*count)++;
}

void viewExpenses(struct expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses found!\n");
        return;
    }

    printf("Expenses\n");
    printf("========\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void saveExpenses(struct expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses found!\n");
        return;
    }

    char filename[50];
    printf("Enter filename to save expenses: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%.2f\n", expenses[i].name, expenses[i].amount);
    }

    fclose(fp);
    printf("Expenses saved to %s successfully!\n", filename);
}