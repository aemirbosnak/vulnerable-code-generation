//FormAI DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for the Account
struct Account {
    char name[100];
    int acc_no;
    float bal;
};

// Function prototypes
void display_menu();
void display_all_accounts(struct Account accounts[], int size);
void add_new_account(struct Account accounts[], int size);
void deposit_money(struct Account accounts[], int size);
void withdraw_money(struct Account accounts[], int size);

int main() {
    int option, size = 0;
    struct Account accounts[100];

    do {
        display_menu();
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                display_all_accounts(accounts, size);
                break;
            case 2:
                add_new_account(accounts, size);
                size++;
                break;
            case 3:
                deposit_money(accounts, size);
                break;
            case 4:
                withdraw_money(accounts, size);
                break;
            case 5:
                printf("Thank you for using the program!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);

    return 0;
}

// Function to display the menu
void display_menu() {
    printf("========================\n");
    printf(" C BANKING RECORD SYSTEM \n");
    printf("========================\n");
    printf("1. Display all accounts\n");
    printf("2. Add a new account\n");
    printf("3. Deposit money\n");
    printf("4. Withdraw money\n");
    printf("5. Exit\n");
}

// Function to display all accounts
void display_all_accounts(struct Account accounts[], int size) {
    if (size == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("All accounts:\n");
    printf("Name\tAccount No.\tBalance\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t\t%.2f\n",
            accounts[i].name, accounts[i].acc_no, accounts[i].bal);
    }
}

// Function to add a new account
void add_new_account(struct Account accounts[], int size) {
    printf("Enter the name of the account holder: ");
    scanf("%s", accounts[size].name);
    printf("Enter the account number: ");
    scanf("%d", &accounts[size].acc_no);
    printf("Enter the balance: ");
    scanf("%f", &accounts[size].bal);

    printf("New account added successfully.\n");
}

// Function to deposit money to an account
void deposit_money(struct Account accounts[], int size) {
    int acc_no;
    float amount;

    printf("Enter the account number: ");
    scanf("%d", &acc_no);

    int i;
    for (i = 0; i < size; i++) {
        if (accounts[i].acc_no == acc_no) {
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);

            accounts[i].bal += amount;
            printf("Money deposited successfully.\n");
            break;
        }
    }

    if (i == size) {
        printf("Account not found.\n");
    }
}

// Function to withdraw money from an account
void withdraw_money(struct Account accounts[], int size) {
    int acc_no;
    float amount;

    printf("Enter the account number: ");
    scanf("%d", &acc_no);

    int i;
    for (i = 0; i < size; i++) {
        if (accounts[i].acc_no == acc_no) {
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > accounts[i].bal) {
                printf("Insufficient balance.\n");
            } else {
                accounts[i].bal -= amount;
                printf("Money withdrawn successfully.\n");
            }

            break;
        }
    }

    if (i == size) {
        printf("Account not found.\n");
    }
}