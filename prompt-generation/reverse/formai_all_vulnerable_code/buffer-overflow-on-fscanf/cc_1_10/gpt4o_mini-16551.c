//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

Expense expenses[MAX_ENTRIES];
int expense_count = 0;

void addExpense() {
    if(expense_count >= MAX_ENTRIES) {
        printf("The ocean of expenses is full. No more fish can swim!\n");
        return;
    }

    printf("Enter the poetic description of the expense: ");
    scanf(" %[^\n]", expenses[expense_count].description);

    printf("Enter the amount, as if whispering it to the wind: ");
    scanf("%f", &expenses[expense_count].amount);

    printf("Bathe the expense in time, enter the date (YYYY-MM-DD): ");
    scanf("%s", expenses[expense_count].date);

    expense_count++;
    printf("Ah! The expense has danced its way into the ledger!\n");
}

void viewExpenses() {
    if (expense_count == 0) {
        printf("The ledger is as empty as a dream forgotten.\n");
        return;
    }

    printf("\n--- Clippings of Reality: Expenses ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Expense %d:\n", i + 1);
        printf("  Description: %s\n", expenses[i].description);
        printf("  Amount: $%.2f\n", expenses[i].amount);
        printf("  Date: %s\n", expenses[i].date);
    }
    printf("-------------------------------------\n");
}

void deleteExpense() {
    if (expense_count == 0) {
        printf("There is no shadow to remove from the ledger!\n");
        return;
    }

    int index;
    printf("Which entry would you like to be consumed by the void? (Enter a number 1-%d): ", expense_count);
    scanf("%d", &index);

    if(index < 1 || index > expense_count) {
        printf("The number slips through your fingers like grains of sand.\n");
        return;
    }

    for (int i = index - 1; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;
    printf("The entry has vanished into the ether.\n");
}

void saveExpenses() {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("The quill has run dry! Unable to write to the parchment...\n");
        return;
    }
    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "%s,%.2f,%s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
    fclose(file);
    printf("Ledger saved, like a secret tucked away in the folds of time.\n");
}

void loadExpenses() {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("The fates deny us access to the past. No ledger found.\n");
        return;
    }
    while (fscanf(file, " %49[^,],%f,%10s\n", expenses[expense_count].description, &expenses[expense_count].amount, expenses[expense_count].date) != EOF) {
        expense_count++;
        if (expense_count >= MAX_ENTRIES) break;
    }
    fclose(file);
    printf("The memories of expenses have woven themselves back into reality.\n");
}

int main() {
    int choice;

    do {
        printf("\n--- The Surreal Expense Tracker ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Save Expenses\n");
        printf("5. Load Expenses\n");
        printf("0. Exit to the Realm of Silence\n");
        printf("Enter your choice (0-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: deleteExpense(); break;
            case 4: saveExpenses(); break;
            case 5: loadExpenses(); break;
            case 0: printf("Wander well, till we meet among the clouds of mystery.\n"); break;
            default: printf("You have wandered off the path of reason. Try again.\n");
        }
    } while(choice != 0);

    return 0;
}