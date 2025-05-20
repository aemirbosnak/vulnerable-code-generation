//FormAI DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float balance;
} Account;

void show_menu() {
    printf("**********************\n");
    printf("* BANKING RECORD SYSTEM *\n");
    printf("**********************\n\n");
    printf("1. Add New Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n\n");
}

void add_account(Account *account) {
    printf("Please enter account name: ");
    scanf("%s", account->name);
    printf("Please enter initial balance: ");
    scanf("%f", &account->balance);
}

void deposit_money(Account *account) {
    float amount;
    printf("Please enter deposit amount: ");
    scanf("%f", &amount);
    account->balance += amount;
    printf("Deposit successful! New balance is %.2f\n", account->balance);
}

void withdraw_money(Account *account) {
    float amount;
    printf("Please enter withdrawal amount: ");
    scanf("%f", &amount);
    if(amount > account->balance) {
        printf("Sorry, insufficient balance to withdraw\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful! New balance is %.2f\n", account->balance);
    }
}

void check_balance(Account *account) {
    printf("Current account balance is %.2f\n", account->balance);
}

int main() {
    Account *accounts = NULL;
    int choice;
    int num_accounts = 0;
    while(1) {
        show_menu();
        printf("Please enter a choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                accounts = (Account*)realloc(accounts, (num_accounts + 1) * sizeof(Account));
                add_account(&accounts[num_accounts]);
                num_accounts++;
                break;
            case 2:
                printf("Please enter account name: ");
                char search_name[50];
                scanf("%s", search_name);
                for(int i=0; i<num_accounts; i++) {
                    if(strcmp(search_name, accounts[i].name) == 0) {
                        deposit_money(&accounts[i]);
                    }
                }
                break;
            case 3:
                printf("Please enter account name: ");
                char search_name2[50];
                scanf("%s", search_name2);
                for(int i=0; i<num_accounts; i++) {
                    if(strcmp(search_name2, accounts[i].name) == 0) {
                        withdraw_money(&accounts[i]);
                    }
                }
                break;
            case 4:
                printf("Please enter account name: ");
                char search_name3[50];
                scanf("%s", search_name3);
                for(int i=0; i<num_accounts; i++) {
                    if(strcmp(search_name3, accounts[i].name) == 0) {
                        check_balance(&accounts[i]);
                    }
                }
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
        printf("\n");
    }
    free(accounts);
    return 0;
}