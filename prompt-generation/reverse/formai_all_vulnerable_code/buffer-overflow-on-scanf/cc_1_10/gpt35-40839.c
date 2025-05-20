//FormAI DATASET v1.0 Category: Banking Record System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer
{
    char account_num[10];
    char name[30];
    char address[50];
    char phone_num[15];
    float balance;
};

struct customer bank[100];
int num_of_customers = 0;

void create_account()
{
    system("clear");
    printf("-----------------------\n");
    printf("Creating a new account!\n");
    printf("-----------------------\n\n");

    printf("Enter account number: ");
    scanf("%s", bank[num_of_customers].account_num);
    printf("Enter name: ");
    scanf("%s", bank[num_of_customers].name);
    printf("Enter address: ");
    getchar();
    fgets(bank[num_of_customers].address, sizeof(bank[num_of_customers].address), stdin);
    printf("Enter phone number: ");
    scanf("%s", bank[num_of_customers].phone_num);
    printf("Enter initial balance: ");
    scanf("%f", &bank[num_of_customers].balance);

    printf("\nAccount created successfully!\n\n");
    num_of_customers++;
    char option;
    printf("Would you like to create another account? (y/n): ");
    scanf(" %c", &option);
    if (option == 'y')
        create_account();
}

void view_accounts()
{
    system("clear");
    if (num_of_customers == 0)
    {
        printf("No accounts to display!\n\n");
        return;
    }

    printf("-----------------------------------------\n");
    printf("Accounts in the Banking Record System:\n");
    printf("-----------------------------------------\n\n");

    for (int i = 0; i < num_of_customers; i++)
    {
        printf("Account number: %s\n", bank[i].account_num);
        printf("Name: %s\n", bank[i].name);
        printf("Address: %s", bank[i].address);
        printf("Phone number: %s\n", bank[i].phone_num);
        printf("Balance: %.2f\n\n", bank[i].balance);
    }
}

void search_account()
{
    system("clear");
    if (num_of_customers == 0)
    {
        printf("No accounts to search for!\n\n");
        return;
    }

    char account_num[10];
    printf("Enter account number to search: ");
    scanf("%s", account_num);
    for (int i = 0; i < num_of_customers; i++)
    {
        if (strcmp(account_num, bank[i].account_num) == 0)
        {
            printf("--------------------------------------\n");
            printf("Details of Account %s:\n", account_num);
            printf("--------------------------------------\n\n");
            printf("Name: %s\n", bank[i].name);
            printf("Address: %s", bank[i].address);
            printf("Phone number: %s\n", bank[i].phone_num);
            printf("Balance: %.2f\n\n", bank[i].balance);
            return;
        }
    }
    printf("Account %s not found!\n\n", account_num);
}

void update_account()
{
    system("clear");
    if (num_of_customers == 0)
    {
        printf("No accounts to update!\n\n");
        return;
    }

    char account_num[10];
    printf("Enter account number to update: ");
    scanf("%s", account_num);
    for (int i = 0; i < num_of_customers; i++)
    {
        if (strcmp(account_num, bank[i].account_num) == 0)
        {
            printf("-----------------------------------------\n");
            printf("Updating details of Account %s:\n", account_num);
            printf("-----------------------------------------\n\n");
            printf("Enter name: ");
            scanf("%s", bank[i].name);
            printf("Enter address: ");
            getchar();
            fgets(bank[i].address, sizeof(bank[i].address), stdin);
            printf("Enter phone number: ");
            scanf("%s", bank[i].phone_num);
            printf("Enter balance: ");
            scanf("%f", &bank[i].balance);
            printf("\nAccount updated successfully!\n\n");
            return;
        }
    }
    printf("Account %s not found!\n\n", account_num);
}

void delete_account()
{
    system("clear");
    if (num_of_customers == 0)
    {
        printf("No accounts to delete!\n\n");
        return;
    }

    char account_num[10];
    printf("Enter account number to delete: ");
    scanf("%s", account_num);
    for (int i = 0; i < num_of_customers; i++)
    {
        if (strcmp(account_num, bank[i].account_num) == 0)
        {
            for (int j = i; j < num_of_customers - 1; j++)
                bank[j] = bank[j + 1];
            num_of_customers--;
            printf("\nAccount %s deleted successfully!\n\n", account_num);
            return;
        }
    }
    printf("\nAccount %s not found!\n\n", account_num);
}

int main()
{
    int option;
    do
    {
        printf("*********************************************\n");
        printf("Welcome to the Banking Record System!\n");
        printf("*********************************************\n");
        printf("\nWhat would you like to do?\n\n");
        printf("1. Create a new account\n");
        printf("2. View all accounts\n");
        printf("3. Search for account\n");
        printf("4. Update account\n");
        printf("5. Delete account\n");
        printf("6. Exit\n\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                create_account();
                break;
            case 2:
                view_accounts();
                break;
            case 3:
                search_account();
                break;
            case 4:
                update_account();
                break;
            case 5:
                delete_account();
                break;
            case 6:
                printf("\nThank you for using the Banking Record System!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again!\n\n");
        }
    } while (1);
    return 0;
}