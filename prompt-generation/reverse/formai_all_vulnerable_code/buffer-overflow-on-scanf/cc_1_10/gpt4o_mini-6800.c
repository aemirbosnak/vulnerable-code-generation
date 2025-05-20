//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
    char category[DESCRIPTION_LENGTH];
} Expense;

void addExpense(Expense expenses[], int *count);
void displayExpenses(const Expense expenses[], int count);
void calculateTotal(const Expense expenses[], int count);

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;
    
    printf("Welcome to the Expense Tracker! Are you ready? (Yes/No)\n");
    char ready[4];
    scanf("%s", ready);
    
    if (strcmp(ready, "Yes") != 0) {
        printf("Whoa! That's unexpected. We are moving forward anyway!\n");
        printf("Let's track those expenses!\n");
    } else {
        printf("Fantastic! Let’s get started!\n");
    }

    while(1) {
        printf("\n=== Menu ===\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                calculateTotal(expenses, count);
                break;
            case 4:
                printf("Exiting... Strange but true, everything has to end!\n");
                exit(0);
            default:
                printf("That's an unusual choice! Please select again.\n");
        }
    }

    return 0;
}

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Oh no! Maximum expense limit reached! Can't add more.\n");
        return;
    }

    printf("Adding a new expense... Ready? Here we go!\n");
    printf("Enter description: ");
    getchar(); // to consume the newline character left by scanf
    fgets(expenses[*count].description, DESCRIPTION_LENGTH, stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0; // remove newline
    
    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);
    
    printf("Enter category: ");
    getchar(); // consume the newline character again
    fgets(expenses[*count].category, DESCRIPTION_LENGTH, stdin);
    expenses[*count].category[strcspn(expenses[*count].category, "\n")] = 0; // remove newline

    printf("Expense added successfully! That's so exciting!\n");
    (*count)++;
}

void displayExpenses(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded! How shocking!\n");
        return;
    }

    printf("\n=== Recorded Expenses ===\n");
    for (int i = 0; i < count; i++) {
        printf("Expense %d:\n", i + 1);
        printf(" Description: %s\n", expenses[i].description);
        printf(" Amount: %.2f\n", expenses[i].amount);
        printf(" Category: %s\n", expenses[i].category);
        printf("-----------------------------\n");
    }
}

void calculateTotal(const Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses to total! How can that be??\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    
    printf("Total expenses calculated! The shocking sum is: %.2f\n", total);
}