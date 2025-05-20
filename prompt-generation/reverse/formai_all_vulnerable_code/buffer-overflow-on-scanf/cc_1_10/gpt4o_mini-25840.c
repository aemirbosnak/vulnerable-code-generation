//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    float balance;
} FinancePlanner;

void initialize(FinancePlanner *planner) {
    planner->count = 0;
    planner->balance = 0.0;
}

void display_balance(FinancePlanner *planner) {
    printf("\nThou hast a total of %.2f gold coins in thy purse.\n", planner->balance);
}

void add_income(FinancePlanner *planner) {
    if (planner->count >= MAX_TRANSACTIONS) {
        printf("Alas! Thou hast reached the limit of transactions.\n");
        return;
    }

    char description[50];
    float amount;

    printf("Enter description of thy earnings (e.g., 'Loot from dragon'): ");
    getchar(); // to clear new line character
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = 0; // Remove trailing newline

    printf("Enter the amount of gold earned: ");
    scanf("%f", &amount);

    snprintf(planner->transactions[planner->count].description, sizeof(planner->transactions[planner->count].description), "%s", description);
    planner->transactions[planner->count].amount = amount;
    planner->balance += amount;
    planner->count++;

    printf("Thou hast added %.2f gold coins for: '%s'.\n", amount, description);
}

void add_expense(FinancePlanner *planner) {
    if (planner->count >= MAX_TRANSACTIONS) {
        printf("Alas! Thou hast reached the limit of transactions.\n");
        return;
    }

    char description[50];
    float amount;

    printf("Enter description of thy expenses (e.g., 'Feast with knights'): ");
    getchar(); // to clear new line character
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = 0; // Remove trailing newline

    printf("Enter the amount of gold spent: ");
    scanf("%f", &amount);

    snprintf(planner->transactions[planner->count].description, sizeof(planner->transactions[planner->count].description), "%s", description);
    planner->transactions[planner->count].amount = -amount; // Store as negative for expenses
    planner->balance -= amount;
    planner->count++;

    printf("Thou hast spent %.2f gold coins for: '%s'.\n", amount, description);
}

void view_transactions(FinancePlanner *planner) {
    printf("\nList of Thy Transactions:\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%d. %s: %.2f gold coins\n", i + 1, planner->transactions[i].description, planner->transactions[i].amount);
    }
}

void display_menu() {
    printf("\n--- The Grand Finance Planner ---\n");
    printf("1. Add Earnings\n");
    printf("2. Add Expenses\n");
    printf("3. View Balance\n");
    printf("4. View Transactions\n");
    printf("5. Exit\n");
    printf("Choose thy path (1-5): ");
}

int main() {
    FinancePlanner planner;
    initialize(&planner);

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_income(&planner);
                break;
            case 2:
                add_expense(&planner);
                break;
            case 3:
                display_balance(&planner);
                break;
            case 4:
                view_transactions(&planner);
                break;
            case 5:
                printf("Farewell, brave soul! May thy coin purse ever be full!\n");
                break;
            default:
                printf("Invalid choice, noble one! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}