//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
    char date[20];
    char category[20];
} Expense;

void inputExpense(Expense *expense) {
    printf("Enter expense name: ");
    scanf(" %[^\n]s", expense->name);
    printf("Enter expense amount: ");
    scanf("%f", &(expense->amount));
    printf("Enter expense date (yyyy-mm-dd): ");
    scanf(" %[^\n]s", expense->date);
    printf("Enter expense category: ");
    scanf(" %[^\n]s", expense->category);
}

void displayExpenses(Expense *expenses, int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("  Name: %s\n", expenses[i].name);
        printf("  Amount: %.2f\n", expenses[i].amount);
        printf("  Date: %s\n", expenses[i].date);
        printf("  Category: %s\n", expenses[i].category);
    }
}

void saveExpensesToFile(Expense *expenses, int numExpenses, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    for (int i = 0; i < numExpenses; i++) {
        fprintf(file, "%s,%.2f,%s,%s\n", expenses[i].name, expenses[i].amount, expenses[i].date, expenses[i].category);
    }
    fclose(file);
    printf("Expenses saved to file %s.\n", filename);
}

int loadExpensesFromFile(Expense *expenses, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return 0;
    }
    int count = 0;
    char temp[200];
    while (fgets(temp, 200, file) != NULL) {
        char *name = strtok(temp, ",");
        float amount = atof(strtok(NULL, ","));
        char *date = strtok(NULL, ",");
        char *category = strtok(NULL, ",");
        strcpy(expenses[count].name, name);
        expenses[count].amount = amount;
        strcpy(expenses[count].date, date);
        strcpy(expenses[count].category, category);
        count++;
    }
    fclose(file);
    printf("Loaded %d expenses from file %s.\n", count, filename);
    return count;
}

void searchExpensesByCategory(Expense *expenses, int numExpenses) {
    char category[20];
    printf("Enter category to search: ");
    scanf(" %[^\n]s", category);
    int found = 0;
    printf("Expenses in category %s:\n", category);
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("  Name: %s\n", expenses[i].name);
            printf("  Amount: %.2f\n", expenses[i].amount);
            printf("  Date: %s\n", expenses[i].date);
            found = 1;
        }
    }
    if (!found) {
        printf("No expenses found in category %s.\n", category);
    }
}

int main() {
    Expense expenses[100];
    int numExpenses = 0;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Save expenses to file\n");
        printf("4. Load expenses from file\n");
        printf("5. Search expenses by category\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (numExpenses == 100) {
                printf("Error: Maximum number of expenses reached.\n");
                continue;
            }
            inputExpense(&expenses[numExpenses]);
            numExpenses++;
        }
        else if (choice == 2) {
            displayExpenses(expenses, numExpenses);
        }
        else if (choice == 3) {
            char filename[50];
            printf("Enter filename to save expenses to: ");
            scanf(" %[^\n]s", filename);
            saveExpensesToFile(expenses, numExpenses, filename);
        }
        else if (choice == 4) {
            char filename[50];
            printf("Enter filename to load expenses from: ");
            scanf(" %[^\n]s", filename);
            numExpenses = loadExpensesFromFile(expenses, filename);
        }
        else if (choice == 5) {
            searchExpensesByCategory(expenses, numExpenses);
        }
        else if (choice == 6) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}