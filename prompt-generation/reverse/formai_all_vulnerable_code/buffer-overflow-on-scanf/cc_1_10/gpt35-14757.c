//FormAI DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CUSTOMERS 100

typedef struct 
{
    char name[50];
    int account_number;
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void add_customer()
{
    if (num_customers == MAX_CUSTOMERS)
    {
        printf("Maximum number of customers reached.\n");
        return;
    }

    Customer new_customer;

    printf("Enter customer name: ");
    scanf("%s", new_customer.name);

    printf("Enter account number: ");
    scanf("%d", &new_customer.account_number);

    printf("Enter balance: ");
    scanf("%f", &new_customer.balance);

    customers[num_customers] = new_customer;
    num_customers++;
}

void view_customer(int account_number)
{
    for (int i = 0; i < num_customers; i++)
    {
        if (customers[i].account_number == account_number)
        {
            printf("Customer name: %s\n", customers[i].name);
            printf("Account number: %d\n", customers[i].account_number);
            printf("Balance: %.2f\n", customers[i].balance);
            return;
        }
    }

    printf("No customer found with account number %d.\n", account_number);
}

void deposit(int account_number, float amount)
{
    for (int i = 0; i < num_customers; i++)
    {
        if (customers[i].account_number == account_number)
        {
            customers[i].balance += amount;
            printf("Deposit successful. Account balance is now %.2f.\n", customers[i].balance);
            return;
        }
    }

    printf("No customer found with account number %d.\n", account_number);
}

void withdraw(int account_number, float amount)
{
    for (int i = 0; i < num_customers; i++)
    {
        if (customers[i].account_number == account_number)
        {
            if (customers[i].balance < amount)
            {
                printf("Withdrawal failed. Insufficient funds.\n");
                return;
            }

            customers[i].balance -= amount;
            printf("Withdrawal successful. Account balance is now %.2f.\n", customers[i].balance);
            return;
        }
    }

    printf("No customer found with account number %d.\n", account_number);
}

void menu()
{
    printf("Welcome to the C Banking Record System!\n\n");

    while (1)
    {
        printf("Main Menu\n");
        printf("1. Add Customer\n");
        printf("2. View Customer\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_customer();
                break;

            case 2:
                printf("Enter account number: ");
                int account_number;
                scanf("%d", &account_number);
                view_customer(account_number);
                break;

            case 3:
                printf("Enter account number: ");
                int deposit_account_number;
                scanf("%d", &deposit_account_number);

                printf("Enter amount to deposit: ");
                float deposit_amount;
                scanf("%f", &deposit_amount);

                deposit(deposit_account_number, deposit_amount);
                break;

            case 4:
                printf("Enter account number: ");
                int withdraw_account_number;
                scanf("%d", &withdraw_account_number);

                printf("Enter amount to withdraw: ");
                float withdraw_amount;
                scanf("%f", &withdraw_amount);

                withdraw(withdraw_account_number, withdraw_amount);
                break;

            case 5:
                printf("Thank you for using the C Banking Record System. Goodbye!\n");
                return;

            default:
                printf("Invalid choice. Please enter a number from 1-5.\n");
                break;
        }

        printf("\n");
    }
}

int main()
{
    menu();
    return 0;
}