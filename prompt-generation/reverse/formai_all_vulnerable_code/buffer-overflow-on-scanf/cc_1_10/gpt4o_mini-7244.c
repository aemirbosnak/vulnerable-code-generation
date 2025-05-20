//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} Expense;

// The wild garden where expenses bloom and wither
Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense(const char *name, float amount) {
    if (expenseCount < MAX_EXPENSES) {
        strcpy(expenses[expenseCount].name, name);
        expenses[expenseCount].amount = amount;
        expenseCount++;
        printf("Added a fleeting expense: %s of the twilight amount $%.2f\n", name, amount);
    } else {
        printf("The garden has too many clouds; cannot plant more expenses!\n");
    }
}

void viewExpenses() {
    printf("\nIn this dreamscape, here are the expenses:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("Expense #%d: A whisper named '%s' - $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
    }
}

void totalExpenses() {
    float total = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    printf("\nIn the echoes of time, the total expenses dance at $%.2f\n", total);
}

void freeMemory() {
    printf("\nAs the clock ticks backward, the garden shall now be emptied...\n");
    expenseCount = 0;
    memset(expenses, 0, sizeof(expenses));
}

void surrealMenu() {
    printf("\n--- The Surreal Expense Tracker ---\n");
    printf("1. Add Expense (A flower in the garden)\n");
    printf("2. View Expenses (Savannah of memories)\n");
    printf("3. Total Expenses (A cascade of coins)\n");
    printf("4. Clear All Expenses (Return to the void)\n");
    printf("5. Exit (The final curtain)\n");
}

int main() {
    int choice;
    char name[50];
    float amount;

    while (1) {
        surrealMenu();
        printf("Choose your destiny: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Plant the name of the flower (expense): ");
                scanf("%s", name);
                printf("Now, pour the dew (amount): ");
                scanf("%f", &amount);
                addExpense(name, amount);
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                totalExpenses();
                break;
            case 4:
                freeMemory();
                break;
            case 5:
                printf("As the sun sets, you retreat into the shadows...\n");
                return 0;
            default:
                printf("The stars have misaligned; choose a valid path!\n");
        }
    }

    return 0;
}