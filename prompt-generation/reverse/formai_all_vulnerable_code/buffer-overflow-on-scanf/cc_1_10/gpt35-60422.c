//FormAI DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct customer {
    char name[50];
    int account_num;
    char account_type[20];
    float balance;
};

struct customer customers[MAX];
int num_of_customers = 0;

void create_customer() {
    printf("\nEnter customer name: ");
    scanf("%s", customers[num_of_customers].name);
    printf("Enter account number: ");
    scanf("%d", &customers[num_of_customers].account_num);
    printf("Enter account type (savings/current): ");
    scanf("%s", customers[num_of_customers].account_type);
    printf("Enter starting account balance: ");
    scanf("%f", &customers[num_of_customers].balance);
    num_of_customers++;
    printf("\nAccount created successfully!\n");
}

void deposit_money(int account_num) {
    int i;
    float amount;
    for (i = 0; i < num_of_customers; i++) {
        if (customers[i].account_num == account_num) {
            printf("\nEnter deposit amount: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("\nDeposit successful!\n");
            return;
        }
    }
    printf("\nAccount not found!\n");
}

void withdraw_money(int account_num) {
    int i;
    float amount;
    for (i = 0; i < num_of_customers; i++) {
        if (customers[i].account_num == account_num) {
            printf("\nEnter withdrawal amount: ");
            scanf("%f", &amount);
            if (amount > customers[i].balance) {
                printf("\nInsufficient balance!\n");
                return;
            } else {
                customers[i].balance -= amount;
                printf("\nWithdrawal successful!\n");
                return;
            }
        }
    }
    printf("\nAccount not found!\n");
}

void check_balance(int account_num) {
    int i;
    for (i = 0; i < num_of_customers; i++) {
        if (customers[i].account_num == account_num) {
            printf("\nAccount balance: %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("\nAccount not found!\n");
}

void display_all_accounts() {
    int i;
    printf("\n%-20s%-20s%-20s%-20s\n", "Name", "Account Number", "Account Type", "Balance");
    for (i = 0; i < num_of_customers; i++) {
        printf("%-20s%-20d%-20s%-20.2f\n", customers[i].name, customers[i].account_num, customers[i].account_type, customers[i].balance);
    }
}

int main() {
    int choice, account_num;
    while (1) {
        printf("\n*** Banking Record System ***\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit Program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_customer();
                break;
            case 2:
                printf("\nEnter account number: ");
                scanf("%d", &account_num);
                deposit_money(account_num);
                break;
            case 3:
                printf("\nEnter account number: ");
                scanf("%d", &account_num);
                withdraw_money(account_num);
                break;
            case 4:
                printf("\nEnter account number: ");
                scanf("%d", &account_num);
                check_balance(account_num);
                break;
            case 5:
                display_all_accounts();
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid input!\n");
                break;
        }
    }
    return 0;
}