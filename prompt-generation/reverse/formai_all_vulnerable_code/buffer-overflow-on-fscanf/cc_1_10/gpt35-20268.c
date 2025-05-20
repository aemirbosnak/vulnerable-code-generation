//FormAI DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define a structure to hold customer banking details
struct customer {
    char name[30];
    int account_number;
    float balance;
}customer;

//function declarations
void add_customer();
void view_details();
void update_balance();
void delete_account();

int main()
{
    int choice;
    printf("\n\n\t\tWelcome to the Banking Record System\n");
    printf("\n\t\tChoose from the following options:\n\n");
    printf("\t\t1. Add a new customer\n");
    printf("\t\t2. View customer details\n");
    printf("\t\t3. Update customer balance\n");
    printf("\t\t4. Delete a customer account\n");
    printf("\t\t5. Exit\n\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            add_customer();
            break;
        case 2:
            view_details();
            break;
        case 3:
            update_balance();
            break;
        case 4:
            delete_account();
            break;
        case 5:
            printf("\n\t\tThank you for using the Banking Record System. Goodbye!\n\n");
            break;
        default:
            printf("\n\t\tInvalid choice. Please select again.\n");
            break;
    }

    return 0;
}

//function to add a new customer
void add_customer()
{
    FILE *fp;
    fp = fopen("bank_records.txt", "a");
    if(fp == NULL)
    {
        printf("\n\t\tError opening file. Please try again later.\n");
        return;
    }

    printf("\n\t\tEnter the customer name: ");
    scanf("%s", customer.name);
    printf("\t\tEnter the account number: ");
    scanf("%d", &customer.account_number);
    printf("\t\tEnter the starting balance: ");
    scanf("%f", &customer.balance);

    fprintf(fp, "%s %d %.2f\n", customer.name, customer.account_number, customer.balance);

    printf("\n\t\tCustomer details added successfully!\n");

    fclose(fp);
}

//function to view customer details
void view_details()
{
    FILE *fp;
    fp = fopen("bank_records.txt", "r");
    if(fp == NULL)
    {
        printf("\n\t\tError opening file. Please try again later.\n");
        return;
    }

    printf("\n\t\tCustomer Details\n");
    printf("\t\t----------------\n");

    while(fscanf(fp, "%s %d %f", customer.name, &customer.account_number, &customer.balance) != EOF)
    {
        printf("\t\tName: %s\n", customer.name);
        printf("\t\tAccount Number: %d\n", customer.account_number);
        printf("\t\tBalance: $%.2f\n", customer.balance);
        printf("\t\t----------------\n");
    }

    fclose(fp);
}

//function to update customer balance
void update_balance()
{
    FILE *fp, *ft;
    char name[30];
    int account_number;
    float balance;
    int found = 0;

    fp = fopen("bank_records.txt", "r");
    if(fp == NULL)
    {
        printf("\n\t\tError opening file. Please try again later.\n");
        return;
    }

    ft = fopen("temp.txt", "w");
    if(ft == NULL)
    {
        printf("\n\t\tError opening file. Please try again later.\n");
        return;
    }

    printf("\n\t\tEnter the customer name: ");
    scanf("%s", name);
    printf("\n\t\tEnter the account number: ");
    scanf("%d", &account_number);

    while(fscanf(fp, "%s %d %f", customer.name, &customer.account_number, &customer.balance) != EOF)
    {
        if(strcmp(name, customer.name) == 0 && account_number == customer.account_number)
        {
            printf("\n\t\tCurrent Balance: $%.2f\n", customer.balance);
            printf("\n\t\tEnter the new balance: $");
            scanf("%f", &balance);
            customer.balance = balance;
            found = 1;
        }

        fprintf(ft, "%s %d %.2f\n", customer.name, customer.account_number, customer.balance);

    }

    if(found == 0)
        printf("\n\t\tRecord not found. Please try again.\n");
    else
        printf("\n\t\tBalance updated successfully!");

    fclose(fp);
    fclose(ft);

    remove("bank_records.txt");
    rename("temp.txt", "bank_records.txt");
}

//function to delete a customer account
void delete_account()
{
    FILE *fp, *ft;
    char name[30];
    int account_number;
    int found = 0;

    fp = fopen("bank_records.txt", "r");
    if(fp == NULL)
    {
        printf("\n\t\tError opening file. Please try again later.\n");
        return;
    }

    ft = fopen("temp.txt", "w");
    if(ft == NULL)
    {
        printf("\n\t\tError opening file. Please try again later.\n");
        return;
    }

    printf("\n\t\tEnter the customer name: ");
    scanf("%s", name);
    printf("\n\t\tEnter the account number: ");
    scanf("%d", &account_number);

    while(fscanf(fp, "%s %d %f", customer.name, &customer.account_number, &customer.balance) != EOF)
    {
        if(strcmp(name, customer.name) == 0 && account_number == customer.account_number)
        {
            printf("\n\t\tRecord deleted successfully!\n");
            found = 1;
        }
        else
            fprintf(ft, "%s %d %.2f\n", customer.name, customer.account_number, customer.balance);
    }

    if(found == 0)
        printf("\n\t\tRecord not found. Please try again.\n");

    fclose(fp);
    fclose(ft);

    remove("bank_records.txt");
    rename("temp.txt", "bank_records.txt");
}