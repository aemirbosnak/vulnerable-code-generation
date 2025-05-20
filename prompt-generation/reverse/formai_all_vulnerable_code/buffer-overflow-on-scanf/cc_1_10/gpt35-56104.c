//FormAI DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Customer structure
struct customer {
    int account_number;
    char name[50];
    float balance;
};

//Function to add a new customer to the record
void addCustomer(struct customer *customers, int *num_customers) {
    printf("\nEnter account number: ");
    scanf("%d", &customers[*num_customers].account_number);

    printf("Enter customer name: ");
    scanf("%s", customers[*num_customers].name);

    printf("Enter opening balance: ");
    scanf("%f", &customers[*num_customers].balance);

    (*num_customers)++;
    printf("\nCustomer added successfully.\n");
}

//Function to search for a customer given the account number
void searchCustomer(struct customer *customers, int num_customers) {
    int account_number, i;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);

    for(i = 0; i < num_customers; i++) {
        if(customers[i].account_number == account_number) {
            printf("\nAccount Number: %d\nName: %s\nBalance: %0.2f\n", customers[i].account_number, customers[i].name, customers[i].balance);
            return;
        }
    }

    printf("\nCustomer not found.\n");
}

//Function to deposit money into a customer's account
void depositMoney(struct customer *customers, int num_customers) {
    int account_number, i;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);

    for(i = 0; i < num_customers; i++) {
        if(customers[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            customers[i].balance += amount;
            printf("\n$%0.2f deposited successfully.\n", amount);
            printf("New balance: $%0.2f\n", customers[i].balance);
            return;
        }
    }

    printf("\nCustomer not found.\n");
}

//Function to withdraw money from a customer's account
void withdrawMoney(struct customer *customers, int num_customers) {
    int account_number, i;
    float amount;
    printf("\nEnter account number: ");
    scanf("%d", &account_number);

    for(i = 0; i < num_customers; i++) {
        if(customers[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount > customers[i].balance) {
                printf("\nInsufficient balance.\n");
                return;
            }

            customers[i].balance -= amount;
            printf("\n$%0.2f withdrawn successfully.\n", amount);
            printf("New balance: $%0.2f\n", customers[i].balance);
            return;
        }
    }

    printf("\nCustomer not found.\n");
}

int main() {
    struct customer customers[1000];
    int num_customers = 0, choice;

    while(1) {
        printf("\n---Banking Record System---\n");
        printf("1) Add Customer\n");
        printf("2) Search Customer\n");
        printf("3) Deposit Money\n");
        printf("4) Withdraw Money\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                addCustomer(customers, &num_customers);
                break;
            case 2:
                searchCustomer(customers, num_customers);
                break;
            case 3:
                depositMoney(customers, num_customers);
                break;
            case 4:
                withdrawMoney(customers, num_customers);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}