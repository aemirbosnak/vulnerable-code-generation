//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense { // struct for expense data
    char category[30];
    float amount;
    char date[11];
};

void addExpense(struct Expense *expenseList, int *numExpenses) {
    struct Expense newExpense;
    printf("Enter the category: ");
    scanf("%29s", newExpense.category);
    printf("Enter the amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%10s", newExpense.date);
    expenseList[*numExpenses] = newExpense;
    (*numExpenses)++;
    printf("Expense added!\n");
}

void listExpenses(struct Expense *expenseList, int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses to display.\n");
        return;
    }
    printf("%-15s %-10s %-10s\n", "Category", "Amount", "Date");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-15s $%-9.2f %-10s\n", expenseList[i].category, expenseList[i].amount, expenseList[i].date);
    }
}

void exportExpenses(struct Expense *expenseList, int numExpenses, char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    fprintf(fp, "%-15s %-10s %-10s\n", "Category", "Amount", "Date");
    for (int i = 0; i < numExpenses; i++) {
        fprintf(fp, "%-15s $%-9.2f %-10s\n", expenseList[i].category, expenseList[i].amount, expenseList[i].date);
    }
    fclose(fp);
    printf("Expenses exported to %s\n", filename);
}

int main() {
    int option;
    int numExpenses = 0;
    struct Expense *expenseList = malloc(sizeof(struct Expense));
    char filename[100];

    while (1) { // while loop to display menu
        printf("\nExpense Tracker Menu\n"
               "1. Add Expense\n"
               "2. List Expenses\n"
               "3. Export Expenses\n"
               "4. Exit\n"
               "Enter Option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addExpense(expenseList, &numExpenses);
                expenseList = realloc(expenseList, (numExpenses + 1) * sizeof(struct Expense));
                break;
            case 2:
                listExpenses(expenseList, numExpenses);
                break;
            case 3:
                printf("Enter filename to export to: ");
                scanf("%99s", filename);
                exportExpenses(expenseList, numExpenses, filename);
                break;
            case 4:
                free(expenseList);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}