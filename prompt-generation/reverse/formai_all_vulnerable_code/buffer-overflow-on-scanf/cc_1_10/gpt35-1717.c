//FormAI DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 500
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    int year;
    int month;
    int day;
    float amount;
    char description[MAX_DESCRIPTION_LENGTH];
} Transaction;

void print_menu() {
    printf("Expense Tracker\n\n");
    printf("1) Add transaction\n");
    printf("2) View transactions\n");
    printf("3) Exit\n");
}

int get_menu_choice() {
    int choice;
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_transaction(Transaction transactions[], int *num_transactions) {
    Transaction new_transaction;
    printf("\nEnter date (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &new_transaction.year, &new_transaction.month, &new_transaction.day);
    printf("Enter amount: ");
    scanf("%f", &new_transaction.amount);
    printf("Enter description: ");
    scanf(" %[^\n]", new_transaction.description);
    transactions[*num_transactions] = new_transaction;
    (*num_transactions)++;
}

void view_transactions(Transaction transactions[], int num_transactions) {
    printf("\nDate\t\tAmount\tDescription\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d-%02d-%02d\t$%.2f\t%s\n", 
            transactions[i].year, 
            transactions[i].month, 
            transactions[i].day,
            transactions[i].amount,
            transactions[i].description);
    }
}

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int num_transactions = 0;
    int choice;

    do {
        print_menu();
        choice = get_menu_choice();
        switch(choice) {
            case 1:
                add_transaction(transactions, &num_transactions);
                break;
            case 2:
                view_transactions(transactions, num_transactions);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}