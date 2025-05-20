//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct account
{
    int acc_no;
    char name[50];
    char address[100];
    float balance;
};

void main()
{
    int choice,i;
    char ch;

    struct account bank[MAX];

    for(i=0;i<MAX;i++)
    {
        bank[i].acc_no=i+1;
        strcpy(bank[i].name," ");
        strcpy(bank[i].address," ");
        bank[i].balance=0.0;
    }

    while(1)
    {
        printf("\n\nWELCOME TO BANKING RECORD SYSTEM\n");
        printf("------------------------------------\n");
        printf("1.Create Account\n");
        printf("2.Deposit Amount\n");
        printf("3.Withdraw Amount\n");
        printf("4.Check Balance\n");
        printf("5.Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter account number: ");
                scanf("%d",&i);

                if(bank[i].acc_no!=0)
                {
                    printf("This account already exists.\n");
                }
                else
                {
                    printf("Enter name: ");
                    scanf("%s",bank[i].name);

                    printf("Enter address: ");
                    scanf("%s",bank[i].address);

                    printf("Account created successfully.\n");
                }
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%d",&i);

                if(bank[i].acc_no==0)
                {
                    printf("This account does not exist.\n");
                }
                else
                {
                    printf("Enter amount to be deposited: ");
                    scanf("%f",&bank[i].balance);
                    bank[i].balance+=bank[i].balance;
                    printf("Amount deposited successfully.\n");
                }
                break;

            case 3:
                printf("Enter account number: ");
                scanf("%d",&i);

                if(bank[i].acc_no==0)
                {
                    printf("This account does not exist.\n");
                }
                else if(bank[i].balance<1000)
                {
                    printf("You cannot withdraw more than your balance.\n");
                }
                else
                {
                    printf("Enter amount to be withdrawn: ");
                    scanf("%f",&ch);
                    bank[i].balance-=ch;
                    printf("Amount withdrawn successfully.\n");
                }
                break;

            case 4:
                printf("Enter account number: ");
                scanf("%d",&i);

                if(bank[i].acc_no==0)
                {
                    printf("This account does not exist.\n");
                }
                else
                {
                    printf("Your balance is: %.2f\n",bank[i].balance);
                }
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}