//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC 100

typedef struct {
    char description[MAX_DESC];
    float amount;
    char category[MAX_DESC];
    char date[MAX_DESC];
} Expense;

void displayExp(Expense expense) {
    printf("Description: %s\n", expense.description);
    printf("Amount: $%.2f\n", expense.amount);
    printf("Category: %s\n", expense.category);
    printf("Date: %s\n", expense.date);
    printf("-------------------------\n");
}

void addExpense(Expense *expenses, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("We have too many memories to hold right now!\n");
        return;
    }
    
    printf("Tell me about your lovely expense, my dear...\n");
    
    printf("Enter the description of your heart's transaction: ");
    getchar(); // Clear newline from previous input
    fgets(expenses[*count].description, MAX_DESC, stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0; // Removing newline

    printf("How much did it cost your love? $");
    scanf("%f", &expenses[*count].amount);
    
    printf("In which category does this love belong? ");
    getchar(); // Clear newline
    fgets(expenses[*count].category, MAX_DESC, stdin);
    expenses[*count].category[strcspn(expenses[*count].category, "\n")] = 0; // Removing newline

    printf("When did this sweet memory happen? (DD/MM/YYYY): ");
    fgets(expenses[*count].date, MAX_DESC, stdin);
    expenses[*count].date[strcspn(expenses[*count].date, "\n")] = 0; // Removing newline

    (*count)++;
    printf("Your expense has been etched in our history!\n");
}

void displayAllExpenses(Expense *expenses, int count) {
    printf("Here are the cherished memories of your expenditures:\n");
    for (int i = 0; i < count; i++) {
        displayExp(expenses[i]);
    }
}

void saveExpenses(Expense *expenses, int count) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Oh no! We couldn't save our beautiful memories!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%.2f\n%s\n%s\n",
                expenses[i].description,
                expenses[i].amount,
                expenses[i].category,
                expenses[i].date);
    }

    fclose(file);
    printf("Our memories are now saved forever!\n");
}

void loadExpenses(Expense *expenses, int *count) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("It appears we have no memories to recall...\n");
        return;
    }

    while (fscanf(file, "%[^\n]\n%f\n%[^\n]\n%[^\n]\n", 
                  expenses[*count].description, 
                  &expenses[*count].amount, 
                  expenses[*count].category, 
                  expenses[*count].date) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Our precious memories are back in our hearts!\n");
}

int main() {
    Expense expenses[MAX_ENTRIES];
    int count = 0;
    int choice;

    loadExpenses(expenses, &count);

    do {
        printf("\nWelcome to our lovely Expense Tracker!\n");
        printf("1. Add an Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Save Expenses\n");
        printf("4. Exit\n");
        printf("Choose your desire: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayAllExpenses(expenses, count);
                break;
            case 3:
                saveExpenses(expenses, count);
                break;
            case 4:
                printf("May your heart be ever full of love. Farewell!\n");
                break;
            default:
                printf("Ah, my love, that choice was a bit too whimsical...\n");
                break;
        }
    } while (choice != 4);

    return 0;
}