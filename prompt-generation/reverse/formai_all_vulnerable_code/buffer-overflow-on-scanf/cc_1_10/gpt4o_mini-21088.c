//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define TRANSACTION_NAME_LENGTH 50

typedef struct {
    char name[TRANSACTION_NAME_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    float total_income;
    float total_expenses;
    float balance;
} FinancePlanner;

void addTransaction(FinancePlanner *planner, char name[], float amount) {
    if (planner->count < MAX_TRANSACTIONS) {
        strncpy(planner->transactions[planner->count].name, name, TRANSACTION_NAME_LENGTH);
        planner->transactions[planner->count].amount = amount;
        planner->count++;
    } else {
        printf("Wow! You've reached the maximum number of transactions. Please remove some before adding more.\n");
    }
}

void displayTransactions(const FinancePlanner *planner) {
    printf("\n--- Your Transactions ---\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%s: %.2f\n", planner->transactions[i].name, planner->transactions[i].amount);
    }
}

void calculateTotals(FinancePlanner *planner) {
    planner->total_income = 0;
    planner->total_expenses = 0;
    for (int i = 0; i < planner->count; i++) {
        if (planner->transactions[i].amount >= 0) {
            planner->total_income += planner->transactions[i].amount;
        } else {
            planner->total_expenses += -planner->transactions[i].amount;  // Make expenses positive
        }
    }
    planner->balance = planner->total_income - planner->total_expenses;
}

void displaySummary(const FinancePlanner *planner) {
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", planner->total_income);
    printf("Total Expenses: %.2f\n", planner->total_expenses);
    printf("Current Balance: %.2f\n", planner->balance);
}

void welcomeMessage() {
    printf("Welcome to your Personal Finance Planner!\n");
    printf("We appreciate you taking the time to manage your finances.\n");
    printf("Let's work together towards a brighter financial future!\n");
}

void farewellMessage() {
    printf("\nThank you for using the Personal Finance Planner!\n");
    printf("Keep up the great work managing your finances!\n");
    printf("Remember, every small step counts toward achieving your goals!\n");
}

int main() {
    FinancePlanner planner = { .count = 0, .total_income = 0.0, .total_expenses = 0.0, .balance = 0.0 };
    int choice;
    
    welcomeMessage();

    do {
        printf("\nMenu:\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Transactions\n");
        printf("4. View Summary\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        char name[TRANSACTION_NAME_LENGTH];
        float amount;

        switch(choice) {
            case 1:
                printf("Enter income source: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addTransaction(&planner, name, amount);
                printf("Thank you for adding your income! Your effort is truly appreciated.\n");
                break;
                
            case 2:
                printf("Enter expense description: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addTransaction(&planner, name, -amount);  // Negate to signify expense
                printf("Thank you for tracking your expenses. This will help you budget wisely!\n");
                break;
                
            case 3:
                displayTransactions(&planner);
                break;
                
            case 4:
                calculateTotals(&planner);
                displaySummary(&planner);
                break;

            case 5:
                farewellMessage();
                break;

            default:
                printf("Oops! Please choose a valid option.\n");
        }
    } while (choice != 5);
    return 0;
}