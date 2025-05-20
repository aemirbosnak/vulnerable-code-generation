//FormAI DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer{
    char name[50];
    int accountNumber;
    double balance;
};

void createAccount(struct Customer *customer){
    printf("Enter Customer Name: ");
    scanf("%s", customer->name);
    printf("Enter Account Number: ");
    scanf("%d", &customer->accountNumber);
    printf("Enter Initial Balance: ");
    scanf("%lf", &customer->balance);
    printf("\nAccount created successfully!\n\n");
}

void deposit(struct Customer *customer){
    double amount;
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);
    customer->balance += amount;
    printf("\nDeposit successful!\n\n");
}

void withdraw(struct Customer *customer){
    double amount;
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);
    if(amount > customer->balance){
        printf("Insufficient balance! Withdrawal failed.\n\n");
    }else{
        customer->balance -= amount;
        printf("\nWithdrawal successful!\n\n");
    }
}

void checkBalance(struct Customer *customer){
    printf("Balance: %.2lf\n\n", customer->balance);
}

void printCustomerDetails(struct Customer *customer){
    printf("Name: %s\n", customer->name);
    printf("Account Number: %d\n", customer->accountNumber);
    printf("Balance: %.2lf\n", customer->balance);
}

int main(){

    //create 5 initial customers
    struct Customer customers[5];
    strcpy(customers[0].name, "John");
    customers[0].accountNumber = 10234;
    customers[0].balance = 5000.00;

    strcpy(customers[1].name, "Rachel");
    customers[1].accountNumber = 23895;
    customers[1].balance = 10000.00;

    strcpy(customers[2].name, "Sam");
    customers[2].accountNumber = 58672;
    customers[2].balance = 3500.00;

    strcpy(customers[3].name, "Mary");
    customers[3].accountNumber = 98762;
    customers[3].balance = 2000.00;

    strcpy(customers[4].name, "David");
    customers[4].accountNumber = 12596;
    customers[4].balance = 8000.00;

    int choice, accountNumber;
    struct Customer *customer;

    while(1){
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Customer Details\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                customer = malloc(sizeof(struct Customer));
                createAccount(customer);
                memcpy(&customers[customer->accountNumber%1000], customer, sizeof(struct Customer));
                free(customer);
                break;

            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                customer = &customers[accountNumber%1000];
                deposit(customer);
                break;

            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                customer = &customers[accountNumber%1000];
                withdraw(customer);
                break;

            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                customer = &customers[accountNumber%1000];
                checkBalance(customer);
                break;

            case 5:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                customer = &customers[accountNumber%1000];
                printCustomerDetails(customer);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }

    return 0;
}