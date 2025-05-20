//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 10

struct Bank_account {
    char acc_name[20];
    int balance;
};

struct User {
    char name[20];
    struct Bank_account accounts[MAX_ACCOUNTS];
    int num_accounts;
};

// Function prototypes
void create_account(struct User *user);
void deposit(struct User *user);
void withdraw(struct User *user);
void display_accounts(struct User *user);

int main() {
    struct User user;
    user.num_accounts = 0;
    
    printf("Welcome to Personal Finance Planner!\n\n");
    
    // Get user input for name
    printf("Please enter your name: ");
    scanf("%s", user.name);
    
    // Main menu loop
    char choice;
    do {
        printf("\nMAIN MENU\n");
        printf("1. Create a new account\n");
        printf("2. Deposit into an account\n");
        printf("3. Withdraw from an account\n");
        printf("4. Display all accounts and balances\n");
        printf("Q. Quit\n");
        printf("\nYour choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                create_account(&user);
                break;
            case '2':
                deposit(&user);
                break;
            case '3':
                withdraw(&user);
                break;
            case '4':
                display_accounts(&user);
                break;
            case 'q':
            case 'Q':
                printf("Thank you for using Personal Finance Planner!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'q' && choice != 'Q');
    
    return 0;
}

// Function to create a new account for the user
void create_account(struct User *user) {
    if (user->num_accounts >= MAX_ACCOUNTS) {
        printf("Sorry, you have reached the maximum number of accounts (%d).\n",
               MAX_ACCOUNTS);
    } else {
        printf("\nCreating new account...\n");
        printf("Please enter account name: ");
        scanf("%s", user->accounts[user->num_accounts].acc_name);
        printf("Please enter initial balance: ");
        scanf("%d", &user->accounts[user->num_accounts].balance);
        
        printf("New account '%s' created with balance $%d.\n",
               user->accounts[user->num_accounts].acc_name,
               user->accounts[user->num_accounts].balance);
        
        user->num_accounts++;
    }
}

// Function to deposit into an account
void deposit(struct User *user) {
    char acc_name[20];
    int amount;
    int found_acc = 0;
    
    printf("\nDepositing money into an account...\n");
    printf("Please enter account name: ");
    scanf("%s", acc_name);
    
    for (int i = 0; i < user->num_accounts; i++) {
        if (strcmp(user->accounts[i].acc_name, acc_name) == 0) {
            printf("Please enter amount to deposit: ");
            scanf("%d", &amount);
            user->accounts[i].balance += amount;
            printf("$%d deposited into account '%s'.\n",
                   amount, user->accounts[i].acc_name);
            found_acc = 1;
            break;
        }
    }
    
    if (!found_acc) {
        printf("Sorry, account '%s' not found.\n", acc_name);
    }
}

// Function to withdraw from an account
void withdraw(struct User *user) {
    char acc_name[20];
    int amount;
    int found_acc = 0;
    
    printf("\nWithdrawing money from an account...\n");
    printf("Please enter account name: ");
    scanf("%s", acc_name);
    
    for (int i = 0; i < user->num_accounts; i++) {
        if (strcmp(user->accounts[i].acc_name, acc_name) == 0) {
            printf("Please enter amount to withdraw: ");
            scanf("%d", &amount);
            if (user->accounts[i].balance >= amount) {
                user->accounts[i].balance -= amount;
                printf("$%d withdrawn from account '%s'.\n",
                       amount, user->accounts[i].acc_name);
            } else {
                printf("Sorry, not enough funds in account '%s'.\n",
                       user->accounts[i].acc_name);
            }
            found_acc = 1;
            break;
        }
    }
    
    if (!found_acc) {
        printf("Sorry, account '%s' not found.\n", acc_name);
    }
}

// Function to display all accounts and their balances
void display_accounts(struct User *user) {
    printf("\nDisplaying all accounts and balances...\n");
    if (user->num_accounts == 0) {
        printf("You have not created any accounts yet.\n");
    } else {
        for (int i = 0; i < user->num_accounts; i++) {
            printf("Account '%s': $%d\n",
                   user->accounts[i].acc_name,
                   user->accounts[i].balance);
        }
    }
}