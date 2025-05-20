//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

// Defining the structure for the Bank Account
typedef struct account
{
    int acc_no;
    char name[50];
    float balance;
}account;

// Creating a function to display the menu
void menu()
{
    printf("\n\t\tBANKING SYSTEM\n");
    printf("\n1. Create Account");
    printf("\n2. Deposit Money");
    printf("\n3. Withdraw Money");
    printf("\n4. Check Balance");
    printf("\n5. Exit");
}

int main()
{
    int choice;
    account *ptr;

    // Initializing the pointer
    ptr = NULL;

    // Starting the program
    do
    {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        // Performing the operation based on the choice
        switch(choice)
        {
            case 1:
                // Creating a new account
                ptr = (account*)malloc(sizeof(account));
                if(ptr == NULL)
                {
                    printf("\nMemory not available!");
                    exit(0);
                }
                else
                {
                    printf("\nEnter the account number: ");
                    scanf("%d",&ptr->acc_no);
                    printf("\nEnter your name: ");
                    scanf("%s",ptr->name);
                    printf("\nAccount created successfully!");
                }
                break;

            case 2:
                // Depositing money
                if(ptr == NULL)
                {
                    printf("\nNo account found!");
                }
                else
                {
                    printf("\nEnter the amount to deposit: ");
                    scanf("%f",&ptr->balance);
                    printf("\nAmount deposited successfully!");
                }
                break;

            case 3:
                // Withdrawing money
                if(ptr == NULL)
                {
                    printf("\nNo account found!");
                }
                else
                {
                    printf("\nEnter the amount to withdraw: ");
                    scanf("%f",&ptr->balance);
                    printf("\nAmount withdrawn successfully!");
                }
                break;

            case 4:
                // Checking balance
                if(ptr == NULL)
                {
                    printf("\nNo account found!");
                }
                else
                {
                    printf("\nYour current balance is: %.2f",ptr->balance);
                }
                break;

            case 5:
                // Exiting the program
                printf("\nExiting the program...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    }while(choice!= 5);

    return 0;
}