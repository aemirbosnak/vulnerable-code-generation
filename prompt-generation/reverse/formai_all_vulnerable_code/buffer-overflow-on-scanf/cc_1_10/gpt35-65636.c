//FormAI DATASET v1.0 Category: Banking Record System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

/* Struct that defines a customer record */
typedef struct
{
    char name[50];
    char address[100];
    int accountNumber;
    double balance;
} Customer;

/* Function prototypes */
int menu();
void createAccount(Customer customers[], int *numCustomers);
void displayAccount(Customer customer);
int findAccount(Customer customers[], int numCustomers, int accountNumber);
void deposit(Customer customers[], int numCustomers, int accountNumber);
void withdraw(Customer customers[], int numCustomers, int accountNumber);
void displayAllAccounts(Customer customers[], int numCustomers);

/* Main function */
int main()
{
    int choice, accountNumber;
    Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;

    do
    {
        choice = menu();

        switch (choice)
        {
            case 1:
                createAccount(customers, &numCustomers);
                break;

            case 2:
                printf("\nEnter the account number: ");
                scanf("%d", &accountNumber);

                if (findAccount(customers, numCustomers, accountNumber) == -1)
                {
                    printf("\nAccount not found!\n");
                }
                else
                {
                    displayAccount(customers[findAccount(customers, numCustomers, accountNumber)]);
                }

                break;

            case 3:
                printf("\nEnter the account number: ");
                scanf("%d", &accountNumber);

                if (findAccount(customers, numCustomers, accountNumber) == -1)
                {
                    printf("\nAccount not found!\n");
                }
                else
                {
                    deposit(customers, numCustomers, accountNumber);
                }

                break;

            case 4:
                printf("\nEnter the account number: ");
                scanf("%d", &accountNumber);

                if (findAccount(customers, numCustomers, accountNumber) == -1)
                {
                    printf("\nAccount not found!\n");
                }
                else
                {
                    withdraw(customers, numCustomers, accountNumber);
                }

                break;

            case 5:
                displayAllAccounts(customers, numCustomers);
                break;

            case 0:
                printf("\nThanks for using our Banking Record System!");
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

/* Function for displaying menu */
int menu()
{
    int choice;

    printf("\n=========================\n");
    printf("Banking Record System Menu\n");
    printf("=========================\n\n");
    printf("1. Create Account\n");
    printf("2. Display Account Information\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Display All Accounts\n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

/* Function for creating a new account */
void createAccount(Customer customers[], int *numCustomers)
{
    Customer customer;

    printf("\nEnter customer name: ");
    scanf("%s", customer.name);

    printf("Enter customer address: ");
    scanf("%s", customer.address);

    printf("Enter account number: ");
    scanf("%d", &customer.accountNumber);

    printf("Enter balance: ");
    scanf("%lf", &customer.balance);

    customers[*numCustomers] = customer;
    *numCustomers += 1;

    printf("\nAccount created successfully!\n");
}

/* Function for displaying a single account */
void displayAccount(Customer customer)
{
    printf("\n%s's Account Information:", customer.name);
    printf("\nAccount number: %d", customer.accountNumber);
    printf("\nAddress: %s", customer.address);
    printf("\nBalance: $%.2lf", customer.balance);
}

/* Function for finding an account in the array */
int findAccount(Customer customers[], int numCustomers, int accountNumber)
{
    int i;
    for (i = 0; i < numCustomers; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            return i;
        }
    }

    return -1;
}

/* Function for depositing money into an account */
void deposit(Customer customers[], int numCustomers, int accountNumber)
{
    double amount;
    int index;

    printf("\nEnter deposit amount: ");
    scanf("%lf", &amount);

    index = findAccount(customers, numCustomers, accountNumber);
    customers[index].balance += amount;

    printf("\nDeposit successful! New balance is $%.2lf", customers[index].balance);
}

/* Function for withdrawing money from an account */
void withdraw(Customer customers[], int numCustomers, int accountNumber)
{
    double amount;
    int index;

    printf("\nEnter withdrawal amount: ");
    scanf("%lf", &amount);

    index = findAccount(customers, numCustomers, accountNumber);

    if (customers[index].balance < amount)
    {
        printf("\nNot enough funds!");
    }
    else
    {
        customers[index].balance -= amount;
        printf("\nWithdrawal successful! New balance is $%.2lf", customers[index].balance);
    }
}

/* Function for displaying all accounts */
void displayAllAccounts(Customer customers[], int numCustomers)
{
    int i;

    printf("\nAll Accounts:\n");

    for (i = 0; i < numCustomers; i++)
    {
        displayAccount(customers[i]);
        printf("\n\n");
    }
}