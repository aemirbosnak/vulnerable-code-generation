//FormAI DATASET v1.0 Category: Banking Record System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bank_record {
    char name[50];
    int account_no;
    double balance;
} customers[100]; // maximum of 100 customers

int customer_count = 0; // initial customer count

void add_customer() {
    printf("Enter customer name: ");
    scanf("%s", customers[customer_count].name);
    printf("Enter account number: ");
    scanf("%d", &customers[customer_count].account_no);
    printf("Enter initial balance: ");
    scanf("%lf", &customers[customer_count].balance);
    customer_count++; // increment customer count
    printf("Customer added!\n");
}

void display_all_customers() {
    if (customer_count == 0) {
        printf("No customers added yet.\n");
    } else {
        printf("All customers:\n");
        for (int i = 0; i < customer_count; i++) {
            printf("%s, account no.: %d, balance: %.2lf\n", customers[i].name, customers[i].account_no, customers[i].balance);
        }
    }
}

void search_customer() {
    int search_account_no;
    printf("Enter account number to search: ");
    scanf("%d", &search_account_no);
    int found = 0; // customer not found
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].account_no == search_account_no) {
            printf("Customer found!\n");
            printf("%s, account no.: %d, balance: %.2lf\n", customers[i].name, customers[i].account_no, customers[i].balance);
            found = 1; // customer found
            break; // stop searching
        }
    }
    if (found == 0) {
        printf("Customer not found.\n");
    }
}

void deposit() {
    int deposit_account_no, deposit_amount;
    printf("Enter account number to deposit: ");
    scanf("%d", &deposit_account_no);
    int found = 0; // customer not found
    int i;
    for (i = 0; i < customer_count; i++) {
        if (customers[i].account_no == deposit_account_no) {
            printf("Customer found!\n");
            printf("%s, account no.: %d, balance: %.2lf\n", customers[i].name, customers[i].account_no, customers[i].balance);
            printf("Enter amount to deposit: ");
            scanf("%d", &deposit_amount);
            customers[i].balance += deposit_amount; // increase balance
            found = 1; // customer found
            break; // stop searching
        }
    }
    if (found == 0) {
        printf("Customer not found.\n");
    } else {
        printf("Deposit successful.\n");
        printf("New balance: %.2lf\n", customers[i].balance);
    }
}

void withdraw() {
    int withdraw_account_no, withdraw_amount;
    printf("Enter account number to withdraw: ");
    scanf("%d", &withdraw_account_no);
    int found = 0; // customer not found
    int i;
    for (i = 0; i < customer_count; i++) {
        if (customers[i].account_no == withdraw_account_no) {
            printf("Customer found!\n");
            printf("%s, account no.: %d, balance: %.2lf\n", customers[i].name, customers[i].account_no, customers[i].balance);
            printf("Enter amount to withdraw: ");
            scanf("%d", &withdraw_amount);
            if (withdraw_amount <= customers[i].balance) {
                customers[i].balance -= withdraw_amount; // decrease balance
                printf("Withdrawal successful.\n");
                printf("New balance: %.2lf\n", customers[i].balance);
            } else {
                printf("Insufficient funds.\n");
            }
            found = 1; // customer found
            break; // stop searching
        }
    }
    if (found == 0) {
        printf("Customer not found.\n");
    }
}

int main() {
    int option;
    do {
        printf("\n----------Bank Record System----------\n");
        printf("1. Add customer\n");
        printf("2. Display all customers\n");
        printf("3. Search customer\n");
        printf("4. Deposit\n");
        printf("5. Withdraw\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_customer();
                break;
            case 2:
                display_all_customers();
                break;
            case 3:
                search_customer();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    } while (option != 6);
    return 0;
}