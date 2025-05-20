//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 20
#define MAX_PIN_LENGTH 4

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float balance;
    char pin[MAX_PIN_LENGTH];
} Account;

void create_account(Account accounts[], int *num_accounts) {
    Account new_account;
    
    printf("Enter name: ");
    scanf("%s", new_account.name);
    
    printf("Enter starting balance: ");
    scanf("%f", &new_account.balance);
    
    printf("Enter 4-digit PIN: ");
    scanf("%s", new_account.pin);
    
    new_account.id = *num_accounts + 1;
    
    accounts[*num_accounts] = new_account;
    
    printf("Account created with ID %d\n", new_account.id);
    
    (*num_accounts)++;
}

void deposit(Account accounts[], int num_accounts) {
    int id;
    float amount;
    
    printf("Enter account ID: ");
    scanf("%d", &id);
    
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].id == id) {
            accounts[i].balance += amount;
            printf("Deposited $%.2f into account %d\n", amount, id);
            return;
        }
    }
    
    printf("Account not found\n");
}

void withdraw(Account accounts[], int num_accounts) {
    int id;
    float amount;
    char pin[MAX_PIN_LENGTH];
    
    printf("Enter account ID: ");
    scanf("%d", &id);
    
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    
    printf("Enter 4-digit PIN: ");
    scanf("%s", pin);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].id == id) {
            if (strcmp(accounts[i].pin, pin) == 0) {
                if (accounts[i].balance >= amount) {
                    accounts[i].balance -= amount;
                    printf("Withdrew $%.2f from account %d\n", amount, id);
                    return;
                } else {
                    printf("Insufficient funds\n");
                    return;
                }
            } else {
                printf("Incorrect PIN\n");
                return;
            }
        }
    }
    
    printf("Account not found\n");
}

void display_balance(Account accounts[], int num_accounts) {
    int id;
    
    printf("Enter account ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].id == id) {
            printf("Balance for account %d: $%.2f\n", id, accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found\n");
}

void list_accounts(Account accounts[], int num_accounts) {
    printf("ID\tName\tBalance\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%d\t%s\t$%.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int choice;
    
    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display balance\n");
        printf("5. List accounts\n");
        printf("6. Quit\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                create_account(accounts, &num_accounts);
                break;
            case 2:
                deposit(accounts, num_accounts);
                break;
            case 3:
                withdraw(accounts, num_accounts);
                break;
            case 4:
                display_balance(accounts, num_accounts);
                break;
            case 5:
                list_accounts(accounts, num_accounts);
                break;
            case 6:
                printf("Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}