//FormAI DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer 
{
    int accountNumber;
    char name[50];
    double balance;
} Customer;

void addCustomer(Customer *customers, int *numCustomers);
void editCustomer(Customer *customers, int numCustomers);
void deleteCustomer(Customer *customers, int *numCustomers);
void printAllCustomers(Customer *customers, int numCustomers);
void printSpecificCustomer(Customer *customers, int numCustomers);
void printMenu();
void clearBuffer();

int main()
{
    int numCustomers = 0;
    Customer customers[50];

    int choice;

    do
    {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clearBuffer();
        switch(choice)
        {
            case 1:
                addCustomer(customers, &numCustomers);
                break;
            case 2:
                editCustomer(customers, numCustomers);
                break;
            case 3:
                deleteCustomer(customers, &numCustomers);
                break;
            case 4:
                printAllCustomers(customers, numCustomers);
                break;
            case 5:
                printSpecificCustomer(customers, numCustomers);
                break;
            case 6:
                printf("\nThank you for using the banking record system!");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
        printf("\n\n");
    } while (choice != 6);

    return 0;
}

void addCustomer(Customer *customers, int *numCustomers)
{
    if (*numCustomers == 50)
    {
        printf("\nSorry, the maximum number of customers has been reached.\n");
        return;
    }

    Customer newCustomer;
    printf("\n---Add New Customer---\n");

    printf("\nEnter account number: ");
    scanf("%d", &newCustomer.accountNumber);
    clearBuffer();
    for (int i = 0; i < *numCustomers; ++i)
    {
        if (newCustomer.accountNumber == customers[i].accountNumber)
        {
            printf("\nSorry, an account with that number already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    fgets(newCustomer.name, 50, stdin);
    newCustomer.name[strcspn(newCustomer.name, "\n")] = 0;

    printf("Enter balance: ");
    scanf("%lf", &newCustomer.balance);
    clearBuffer();

    customers[*numCustomers] = newCustomer;
    (*numCustomers)++;
    printf("\nThe customer has been added to the record.");
}

void editCustomer(Customer *customers, int numCustomers)
{
    if (numCustomers == 0)
    {
        printf("\nSorry, there are no customers in the record.\n");
        return;
    }

    int accountNumber;
    printf("\n---Edit a Customer---\n");
    printf("Enter the account number of the customer you wish to edit: ");
    scanf("%d", &accountNumber);
    clearBuffer();

    int found = 0;
    for (int i = 0; i < numCustomers; ++i)
    {
        if (accountNumber == customers[i].accountNumber)
        {
            found = 1;
            char newName[50];
            double newBalance;
            printf("Enter new name: ");
            fgets(newName, 50, stdin);
            newName[strcspn(newName, "\n")] = 0;
            strcpy(customers[i].name, newName);

            printf("Enter new balance: ");
            scanf("%lf", &newBalance);
            clearBuffer();
            customers[i].balance = newBalance;

            printf("\nThe customer has been updated.");
            break;
        }
    }

    if (!found)
    {
        printf("\nSorry, no customer with that account number exists.\n");
    }
}

void deleteCustomer(Customer *customers, int *numCustomers)
{
    if (*numCustomers == 0)
    {
        printf("\nSorry, there are no customers in the record.\n");
        return;
    }

    int accountNumber;
    printf("\n---Delete a Customer---\n");
    printf("Enter the account number of the customer you wish to delete: ");
    scanf("%d", &accountNumber);
    clearBuffer();

    int found = 0;
    int deleteIndex = -1;
    for (int i = 0; i < *numCustomers; ++i)
    {
        if (accountNumber == customers[i].accountNumber)
        {
            found = 1;
            deleteIndex = i;
            break;
        }
    }

    if (found)
    {
        for (int i = deleteIndex; i < (*numCustomers - 1); ++i)
        {
            customers[i] = customers[i + 1];
        }
        (*numCustomers)--;
        printf("\nThe customer has been deleted from the record.");
    }

    if (!found)
    {
        printf("\nSorry, no customer with that account number exists.\n");
    }
}

void printAllCustomers(Customer *customers, int numCustomers)
{
    if (numCustomers == 0)
    {
        printf("\nSorry, there are no customers in the record.\n");
        return;
    }

    printf("\n---All Customers---\n");
    for (int i = 0; i < numCustomers; ++i)
    {
        printf("Account Number: %d\n", customers[i].accountNumber);
        printf("Name: %s\n", customers[i].name);
        printf("Balance: $%.2lf\n\n", customers[i].balance);
    }
}

void printSpecificCustomer(Customer *customers, int numCustomers)
{
    if (numCustomers == 0)
    {
        printf("\nSorry, there are no customers in the record.\n");
        return;
    }

    int accountNumber;
    printf("\n---Print Specific Customer---\n");
    printf("Enter the account number of the customer you wish to view: ");
    scanf("%d", &accountNumber);
    clearBuffer();

    int found = 0;
    for (int i = 0; i < numCustomers; ++i)
    {
        if (accountNumber == customers[i].accountNumber)
        {
            found = 1;
            printf("\n---Customer Information---\n");
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: $%.2lf\n", customers[i].balance);
            break;
        }
    }

    if (!found)
    {
        printf("\nSorry, no customer with that account number exists.\n");
    }
}

void printMenu()
{
    printf("---Banking Record System---\n\n");
    printf("1. Add a customer\n");
    printf("2. Edit a customer\n");
    printf("3. Delete a customer\n");
    printf("4. List all customers\n");
    printf("5. View specific customer's information\n");
    printf("6. Exit\n");
}

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}