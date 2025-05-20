//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold the expense data
struct expense {
    char category[50];
    float amount;
    char notes[200];
};

// function prototypes
void addExpense(struct expense exp[], int *numExpenses);
void viewExpenses(struct expense exp[], int numExpenses);
void saveExpenses(struct expense exp[], int numExpenses);

int main() {
    // declare variables
    int choice = 0;
    struct expense expenses[100];
    int numExpenses = 0;

    // load saved expenses from file
    FILE *fp;
    fp = fopen("expenses.txt", "r");
    if (fp != NULL) {
        fread(&numExpenses, sizeof(numExpenses), 1, fp);
        fread(expenses, sizeof(expenses), 1, fp);
        fclose(fp);
    }

    // display menu and get user choice
    while (choice != 4) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Save expenses\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                saveExpenses(expenses, numExpenses);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// function to add an expense
void addExpense(struct expense exp[], int *numExpenses) {
    // declare variables
    char category[50];
    float amount;
    char notes[200];
    struct expense newExpense;

    // get expense details from user
    printf("\nEnter expense category: ");
    scanf("%s", category);
    printf("Enter expense amount: ");
    scanf("%f", &amount);
    printf("Enter notes (optional): ");
    scanf("%s", notes);

    // set new expense struct values
    strcpy(newExpense.category, category);
    newExpense.amount = amount;
    strcpy(newExpense.notes, notes);

    // add new expense to array and increment number of expenses
    exp[*numExpenses] = newExpense;
    *numExpenses += 1;

    printf("Expense added successfully.\n");
}

// function to view expenses
void viewExpenses(struct expense exp[], int numExpenses) {
    // display header
    printf("\nExpenses\n");
    printf("%-20s %-10s %-20s\n", "Category", "Amount", "Notes");

    // loop through expenses and display each one
    for (int i = 0; i < numExpenses; i++) {
        printf("%-20s $%-9.2f %-20s\n", exp[i].category, exp[i].amount, exp[i].notes);
    }
}

// function to save expenses to file
void saveExpenses(struct expense exp[], int numExpenses) {
    // open file for writing and write number of expenses and expense array to file
    FILE *fp;
    fp = fopen("expenses.txt", "w");
    fwrite(&numExpenses, sizeof(numExpenses), 1, fp);
    fwrite(exp, sizeof(exp[0]), numExpenses, fp);
    fclose(fp);

    printf("Expenses saved successfully.\n");
}