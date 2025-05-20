//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define CATEGORY_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    double amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} FinancePlanner;

void initializePlanner(FinancePlanner* planner) {
    planner->count = 0;
}

void addExpense(FinancePlanner* planner, const char* name, const char* category, double amount) {
    if (planner->count < MAX_ENTRIES) {
        strncpy(planner->expenses[planner->count].name, name, NAME_LENGTH);
        strncpy(planner->expenses[planner->count].category, category, CATEGORY_LENGTH);
        planner->expenses[planner->count].amount = amount;
        planner->count++;
        printf("Expense added successfully.\n");
    } else {
        printf("Error: Cannot add more expenses, limit reached.\n");
    }
}

void viewExpenses(const FinancePlanner* planner) {
    if (planner->count == 0) {
        printf("No expenses to display.\n");
        return;
    }
    printf("\n--- Expense Summary ---\n");
    printf("%-20s %-15s %s\n", "Name", "Category", "Amount");
    for (int i = 0; i < planner->count; i++) {
        printf("%-20s %-15s %.2f\n", planner->expenses[i].name, planner->expenses[i].category, planner->expenses[i].amount);
    }
    printf("-----------------------\n");
}

void calculateTotal(const FinancePlanner* planner) {
    double total = 0.0;
    for (int i = 0; i < planner->count; i++) {
        total += planner->expenses[i].amount;
    }
    printf("Total expenses: %.2f\n", total);
}

void saveToFile(const FinancePlanner* planner) {
    FILE* file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error: Could not save to file.\n");
        return;
    }
    for (int i = 0; i < planner->count; i++) {
        fprintf(file, "%s %s %.2f\n", planner->expenses[i].name, planner->expenses[i].category, planner->expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void loadFromFile(FinancePlanner* planner) {
    FILE* file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No previous expenses found, starting fresh.\n");
        return;
    }
    while (!feof(file) && planner->count < MAX_ENTRIES) {
        Expense temp;
        if (fscanf(file, "%s %s %lf", temp.name, temp.category, &temp.amount) == 3) {
            addExpense(planner, temp.name, temp.category, temp.amount);
        }
    }
    fclose(file);
}

int main() {
    FinancePlanner planner;
    initializePlanner(&planner);
    loadFromFile(&planner);

    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Save Expenses to File\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character
        
        switch (choice) {
            case 1: {
                char name[NAME_LENGTH];
                char category[CATEGORY_LENGTH];
                double amount;

                printf("Enter expense name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline

                printf("Enter expense category: ");
                fgets(category, CATEGORY_LENGTH, stdin);
                category[strcspn(category, "\n")] = 0; // remove newline

                printf("Enter expense amount: ");
                scanf("%lf", &amount);
                addExpense(&planner, name, category, amount);
                break;
            }
            case 2:
                viewExpenses(&planner);
                break;
            case 3:
                calculateTotal(&planner);
                break;
            case 4:
                saveToFile(&planner);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please select again.\n");
        }

    } while (choice != 5);

    return 0;
}