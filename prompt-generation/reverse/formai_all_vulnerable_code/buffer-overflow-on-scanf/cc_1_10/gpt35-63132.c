//FormAI DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bank_account {
    char name[30];
    int account_number;
    float balance;
};

typedef struct bank_account Account;

void create_account(Account *accounts, int *count) {
    Account new_account;
    printf("Enter name of account holder: ");
    scanf("%s", new_account.name);
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter initial balance: ");
    scanf("%f", &new_account.balance);
    *(accounts + (*count)) = new_account;
    (*count)++;
    printf("Account created successfully!\n");
}

void display_account_info(Account account) {
    printf("Account holder name: %s\n", account.name);
    printf("Account number: %d\n", account.account_number);
    printf("Current balance: %f\n", account.balance);
}

void display_accounts(Account *accounts, int count) {
    printf("Total number of accounts: %d\n", count);
    for(int i=0; i<count; i++) {
        printf("=========================\n");
        display_account_info(*(accounts + i));
    }
}

void search_account(Account *accounts, int count) {
    int account_number;
    printf("Enter account number to search: ");
    scanf("%d", &account_number);
    for(int i=0; i<count; i++) {
        if((*(accounts + i)).account_number == account_number) {
            printf("=========================\n");
            display_account_info(*(accounts + i));
            return;
        }
    }
    printf("No account found with account number %d\n", account_number);
}

void update_account(Account *accounts, int count) {
    int account_number;
    printf("Enter account number of account to update: ");
    scanf("%d", &account_number);
    for(int i=0; i<count; i++) {
        if((*(accounts + i)).account_number == account_number) {
            printf("Enter new account holder name: ");
            scanf("%s", (*(accounts + i)).name);
            printf("Enter new balance: ");
            scanf("%f", &(*(accounts + i)).balance);
            printf("Account updated successfully!\n");
            return;
        }
    }
    printf("No account found with account number %d\n", account_number);
}

void delete_account(Account *accounts, int *count) {
    int account_number, found=0;
    printf("Enter account number to delete: ");
    scanf("%d", &account_number);
    for(int i=0; i<*count; i++) {
        if((*(accounts + i)).account_number == account_number) {
            found = 1;
            for(int j=i; j<*count-1; j++) {
                *(accounts + j) = *(accounts + j + 1);
            }
            (*count)--;
            break;
        }
    }
    if(found) {
        printf("Account deleted successfully!\n");
    } else {
        printf("No account found with account number %d\n", account_number);
    }
}

int main() {
    Account accounts[10];
    int count = 0;
    int choice;
    do {
        printf("\n=========================\n");
        printf("1. Create new account\n");
        printf("2. Display account details\n");
        printf("3. Search an account\n");
        printf("4. Update an account\n");
        printf("5. Delete an account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_account(accounts, &count);
                break;
            case 2:
                display_accounts(accounts, count);
                break;
            case 3:
                search_account(accounts, count);
                break;
            case 4:
                update_account(accounts, count);
                break;
            case 5:
                delete_account(accounts, &count);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice!=6);
    return 0;
}