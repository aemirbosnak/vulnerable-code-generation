//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct customer
{
    char name[50];
    char account_number[20];
    float balance;
} customer;

void create_customer(customer *cust, char name[50], char account_number[20], float balance)
{
    strcpy(cust->name, name);
    strcpy(cust->account_number, account_number);
    cust->balance = balance;
}

void display_customer(customer *cust)
{
    printf("Customer Name: %s\n", cust->name);
    printf("Account Number: %s\n", cust->account_number);
    printf("Balance: %.2f\n", cust->balance);
}

void deposit(customer *cust, float amount)
{
    cust->balance += amount;
    printf("Deposit of %.2f successful. New balance is %.2f\n", amount, cust->balance);
}

void withdraw(customer *cust, float amount)
{
    if (cust->balance >= amount)
    {
        cust->balance -= amount;
        printf("Withdrawal of %.2f successful. New balance is %.2f\n", amount, cust->balance);
    }
    else
    {
        printf("Insufficient funds. Withdrawal not successful.\n");
    }
}

void main()
{
    srand(time(NULL));
    customer cust1, cust2;
    char name1[50] = "John Doe";
    char account_number1[20] = "1234567890";
    char name2[50] = "Jane Doe";
    char account_number2[20] = "9876543210";
    float balance1 = 1000.00;
    float balance2 = 2000.00;
    create_customer(&cust1, name1, account_number1, balance1);
    create_customer(&cust2, name2, account_number2, balance2);

    printf("Customer 1 Details:\n");
    display_customer(&cust1);

    printf("\nCustomer 2 Details:\n");
    display_customer(&cust2);

    printf("\nEnter the operation (d for deposit, w for withdrawal, q to quit): ");
    char op[20];
    scanf("%s", op);

    while (*op!= 'q')
    {
        if (*op == 'd')
        {
            float amount;
            printf("Enter the deposit amount: ");
            scanf("%f", &amount);
            deposit(&cust1, amount);
            deposit(&cust2, amount);
        }
        else if (*op == 'w')
        {
            float amount;
            printf("Enter the withdrawal amount: ");
            scanf("%f", &amount);
            withdraw(&cust1, amount);
            withdraw(&cust2, amount);
        }
        else
        {
            printf("Invalid operation. Please enter d or w\n");
        }

        printf("\nCustomer 1 Details:\n");
        display_customer(&cust1);

        printf("\nCustomer 2 Details:\n");
        display_customer(&cust2);

        printf("\nEnter the operation (d for deposit, w for withdrawal, q to quit): ");
        scanf("%s", op);
    }

    printf("\nThank you for using the Banking Record System.\n");
}