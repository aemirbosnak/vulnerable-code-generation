//FormAI DATASET v1.0 Category: Expense Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANS 1000 // Maximum number of transactions
#define FILE_NAME "Expenses.txt" // File name to store transactions

// Transaction structure
typedef struct {
    char description[50];
    float amount;
    int day, month, year;
} Transaction;

int num_trans = 0; // number of transactions
Transaction transactions[MAX_TRANS]; // Array of transactions

// Function to display main menu
void display_menu() {
    printf("\n---- EXPENSE TRACKER ----\n");
    printf("1. Add transaction\n");
    printf("2. View transactions\n");
    printf("3. Export to file\n");
    printf("4. Exit\n");
}

// Function to get user input for a new transaction
void get_transaction() {
    Transaction trans;
    printf("\nEnter description: ");
    scanf("%s", trans.description);
    printf("Enter amount: ");
    scanf("%f", &trans.amount);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &trans.day, &trans.month, &trans.year);
    transactions[num_trans++] = trans; // Add transaction to array
}

// Function to display list of transactions
void view_transactions() {
    printf("\n---- TRANSACTIONS ----\n");
    printf("Description\tAmount\tDate\n");
    for(int i = 0; i < num_trans; i++) {
        Transaction trans = transactions[i];
        printf("%s\t\t%.2f\t%d/%d/%d\n", trans.description, trans.amount, trans.day, trans.month, trans.year);
    }
}

// Function to export transactions to a file
void export_file() {
    FILE *fp;
    fp = fopen(FILE_NAME, "w");
    if(fp == NULL) { // Check if file was created successfully
        printf("\nError creating file.");
        return;
    }
    fprintf(fp, "Description\tAmount\tDate\n");
    for(int i = 0; i < num_trans; i++) {
        Transaction trans = transactions[i];
        fprintf(fp, "%s\t%.2f\t%d/%d/%d\n", trans.description, trans.amount, trans.day, trans.month, trans.year);
    }
    fclose(fp);
    printf("\nTransactions exported to file \"%s\".", FILE_NAME);
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                get_transaction();
                break;
            case 2:
                view_transactions();
                break;
            case 3:
                export_file();
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice, please try again.");
                break;
        }
    } while(choice != 4);
    return 0;
}