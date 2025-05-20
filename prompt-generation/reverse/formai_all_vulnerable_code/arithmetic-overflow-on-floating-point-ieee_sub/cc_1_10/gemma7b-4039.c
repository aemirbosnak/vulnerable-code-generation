//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a bank account
typedef struct bank_account {
    char name[50];
    int account_number;
    double balance;
    struct bank_account *next;
} bank_account;

// Function to insert a new account into the bank
void insert_account(bank_account **head) {
    bank_account *new_account = (bank_account *)malloc(sizeof(bank_account));
    printf("Enter your name: ");
    scanf("%s", new_account->name);
    printf("Enter your account number: ");
    scanf("%d", &new_account->account_number);
    printf("Enter your initial balance: ");
    scanf("%lf", &new_account->balance);
    new_account->next = *head;
    *head = new_account;
}

// Function to withdraw money from an account
void withdraw_money(bank_account *account) {
    double withdrawal;
    printf("Enter the amount you want to withdraw: ");
    scanf("%lf", &withdrawal);
    if (withdrawal > account->balance) {
        printf("Error: Insufficient funds.");
    } else {
        account->balance -= withdrawal;
        printf("Withdrawal successful.");
    }
}

// Function to display account information
void display_account(bank_account *account) {
    printf("Name: %s", account->name);
    printf("\nAccount Number: %d", account->account_number);
    printf("\nBalance: %.2lf", account->balance);
}

// Main function
int main() {
    bank_account *head = NULL;
    int choice;

    // Display menu options
    printf("1. Insert Account\n");
    printf("2. Withdraw Money\n");
    printf("3. Display Account Information\n");
    printf("Enter your choice: ");

    // Get the user's choice
    scanf("%d", &choice);

    // Process the user's choice
    switch (choice) {
        case 1:
            insert_account(&head);
            break;
        case 2:
            withdraw_money(head);
            break;
        case 3:
            display_account(head);
            break;
        default:
            printf("Invalid choice.");
    }

    return 0;
}