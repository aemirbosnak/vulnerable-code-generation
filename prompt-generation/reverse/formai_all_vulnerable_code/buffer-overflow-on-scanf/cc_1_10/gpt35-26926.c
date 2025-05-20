//FormAI DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct customer {
    int account_number;
    char name[50];
    float balance;
};

struct customer customer_data[MAX_CUSTOMERS];
int num_of_customers = 0;

void create_account() {
    printf("Enter account number: ");
    scanf("%d", &customer_data[num_of_customers].account_number);
    printf("Enter name: ");
    scanf("%s", customer_data[num_of_customers].name);
    printf("Enter initial balance: ");
    scanf("%f", &customer_data[num_of_customers].balance);
    num_of_customers++;
    printf("Account created successfully.\n");
}

void deposit() {
    int account_number;
    float deposit_amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for(int i=0; i<num_of_customers; i++) {
        if(customer_data[i].account_number == account_number) {
            printf("Enter deposit amount: ");
            scanf("%f", &deposit_amount);
            customer_data[i].balance += deposit_amount;
            printf("Deposit successful.\n");
            return;
        }
    }
    printf("Invalid account number.\n");
}

void withdraw() {
    int account_number;
    float withdraw_amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for(int i=0; i<num_of_customers; i++) {
        if(customer_data[i].account_number == account_number) {
            printf("Enter withdraw amount: ");
            scanf("%f", &withdraw_amount);
            if(customer_data[i].balance >= withdraw_amount) {
                customer_data[i].balance -= withdraw_amount;
                printf("Withdraw successful.\n");
                return;
            }
            else {
                printf("Insufficient balance.\n");
                return;
            }
        }
    }
    printf("Invalid account number.\n");
}

void balance_enquiry() {
    int account_number;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for(int i=0; i<num_of_customers; i++) {
        if(customer_data[i].account_number == account_number) {
            printf("Account holder name: %s\n", customer_data[i].name);
            printf("Account balance: %f\n", customer_data[i].balance);
            return;
        }
    }
    printf("Invalid account number.\n");
}

void display_all() {
    printf("-----------------------------------------------\n");
    printf("| Account No. | Account Holder Name | Balance |\n");
    printf("-----------------------------------------------\n");
    for(int i=0; i<num_of_customers; i++) {
        printf("| %11d | %19s | %7.2f |\n", customer_data[i].account_number, customer_data[i].name, customer_data[i].balance);
    }
    printf("-----------------------------------------------\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n");
        printf("Welcome to XYZ Bank\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance enquiry\n");
        printf("5. Display all\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create_account();
                    break;
            case 2: deposit();
                    break;
            case 3: withdraw();
                    break;
            case 4: balance_enquiry();
                    break;
            case 5: display_all();
                    break;
            case 6: printf("Thank you for banking with us.\n");
                    exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}