//FormAI DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char date[11];
    char description[100];
    float amount;
} Expense;

int readExpense(Expense *expensePtr);
void printExpense(Expense expense);
void printExpenses(Expense expenses[], int n);
void saveExpenses(Expense expenses[], int n);
int loadExpenses(Expense expenses[]);

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = loadExpenses(expenses);

    printf("Welcome to the Expense Tracker!\n\n");

    while (1) {
        printf("What would you like to do today?\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. Exit\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached!\n\n");
                    break;
                }

                Expense expense;
                printf("\nAdd an expense:\n");
                readExpense(&expense);
                expenses[count++] = expense;
                printf("Expense added successfully!\n\n");

                saveExpenses(expenses, count);
                break;

            case 2:
                printf("\nExpenses:\n");

                if (count == 0) {
                    printf("No expenses to display!\n\n");
                    break;
                }

                printExpenses(expenses, count);
                printf("\n");

                break;

            case 3:
                printf("\nThank you for using the Expense Tracker!\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    }

    return 0;
}

int readExpense(Expense *expensePtr) {
    printf("Enter date of expense (in DD/MM/YYYY format): ");
    scanf("%s", expensePtr->date);

    printf("Enter expense description: ");
    scanf("%s", expensePtr->description);

    printf("Enter expense amount: ");
    scanf("%f", &expensePtr->amount);

    return 0;
}

void printExpense(Expense expense) {
    printf("%-12s %-50s %.2f\n", expense.date, expense.description, expense.amount);
}

void printExpenses(Expense expenses[], int n) {
    printf("%-12s %-50s %s\n", "Date", "Description", "Amount");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printExpense(expenses[i]);
    }
}

void saveExpenses(Expense expenses[], int n) {
    FILE *fp;

    if ((fp = fopen("expenses.txt", "w")) == NULL) {
        printf("Error creating file!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s,%s,%.2f\n", expenses[i].date, expenses[i].description, expenses[i].amount);
    }

    fclose(fp);
}

int loadExpenses(Expense expenses[]) {
    FILE *fp;

    if ((fp = fopen("expenses.txt", "r")) == NULL) {
        printf("No expenses found!\n");
        return 0;
    }

    int count = 0;

    while (!feof(fp)) {
        char buf[111];
        fgets(buf, 111, fp);

        if (strlen(buf) < 5) {
            continue;
        }

        char *date = strtok(buf, ",");
        char *description = strtok(NULL, ",");
        char *amount_str = strtok(NULL, ",");

        Expense expense;
        strcpy(expense.date, date);
        strcpy(expense.description, description);
        expense.amount = atof(amount_str);

        expenses[count++] = expense;

        if (count >= MAX_EXPENSES) {
            break;
        }
    }

    fclose(fp);

    return count;
}