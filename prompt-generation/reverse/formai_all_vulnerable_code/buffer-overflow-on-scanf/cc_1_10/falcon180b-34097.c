//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of transactions that can be stored
#define MAX_TRANSACTIONS 100

// Define the structure for a transaction
typedef struct {
    char date[10];
    char category[20];
    float amount;
} Transaction;

// Declare a global array to store transactions
Transaction transactions[MAX_TRANSACTIONS];

// Declare the number of transactions currently stored
int num_transactions = 0;

// Function to display the main menu
void display_menu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add transaction\n");
    printf("2. View transactions\n");
    printf("3. Edit transaction\n");
    printf("4. Delete transaction\n");
    printf("5. Exit\n");
}

// Function to add a transaction
void add_transaction() {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", transactions[num_transactions].date);

    printf("Enter category: ");
    scanf("%s", transactions[num_transactions].category);

    printf("Enter amount: ");
    scanf("%f", &transactions[num_transactions].amount);

    num_transactions++;
}

// Function to view all transactions
void view_transactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - %s - $%.2f\n", transactions[i].date, transactions[i].category, transactions[i].amount);
    }
}

// Function to edit a transaction
void edit_transaction() {
    printf("Enter the index of the transaction to edit: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= num_transactions) {
        printf("Error: Invalid transaction index.\n");
        return;
    }

    printf("Enter new date (YYYY-MM-DD): ");
    scanf("%s", transactions[index].date);

    printf("Enter new category: ");
    scanf("%s", transactions[index].category);

    printf("Enter new amount: ");
    scanf("%f", &transactions[index].amount);
}

// Function to delete a transaction
void delete_transaction() {
    printf("Enter the index of the transaction to delete: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= num_transactions) {
        printf("Error: Invalid transaction index.\n");
        return;
    }

    for (int i = index; i < num_transactions - 1; i++) {
        transactions[i] = transactions[i + 1];
    }

    num_transactions--;
}

// Main function
int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_transaction();
                break;
            case 2:
                view_transactions();
                break;
            case 3:
                edit_transaction();
                break;
            case 4:
                delete_transaction();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}