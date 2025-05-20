//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
    char description[50];
    float amount;
    char type[10];
} Transaction;

void read_transaction(Transaction* transaction) {
    printf("Enter day, month, year (dd mm yyyy): ");
    scanf("%d %d %d", &transaction->day, &transaction->month, &transaction->year);
    printf("Enter description: ");
    scanf("%s", transaction->description);
    printf("Enter amount: ");
    scanf("%f", &transaction->amount);
    printf("Enter transaction type (expense or income): ");
    scanf("%s", transaction->type);
}

void print_transaction(const Transaction* transaction) {
    printf("%d/%d/%d %-15s %+6.2f %s\n", transaction->day, transaction->month, transaction->year, transaction->description, transaction->amount, transaction->type);
}

#define MAX_TRANSACTIONS 100

Transaction transactions[MAX_TRANSACTIONS];
int num_transactions = 0;

void calculate_totals(float* total_income, float* total_expenses) {
    *total_income = *total_expenses = 0;
    for (int i = 0; i < num_transactions; ++i) {
        if (strcmp(transactions[i].type, "expense") == 0) {
            *total_expenses += transactions[i].amount;
        } else {
            *total_income += transactions[i].amount;
        }
    }
}

void print_totals(const float total_income, const float total_expenses) {
    printf("\nTotal Income: %+.2f\n", total_income);
    printf("Total Expenses: %-.2f\n", total_expenses);
}

void print_menu() {
    printf("\nPersonal Finance Planner\n");
    printf("--------------------------\n");
    printf("1. Add Transaction\n");
    printf("2. Print Transactions\n");
    printf("3. Print Totals\n");
    printf("4. Quit\n");
}

int main() {
    int choice;
    float total_income, total_expenses;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_transactions < MAX_TRANSACTIONS) {
                    read_transaction(&transactions[num_transactions]);
                    num_transactions++;
                } else {
                    printf("Max transactions reached.\n");
                }
                break;
            case 2:
                for (int i = 0; i < num_transactions; ++i) {
                    print_transaction(&transactions[i]);
                }
                break;
            case 3:
                calculate_totals(&total_income, &total_expenses);
                print_totals(total_income, total_expenses);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}