//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

typedef struct bank
{
    char name[50];
    char account_number[10];
    char type[10];
    float balance;
}bank;

void main()
{
    int choice,i;
    bank b[MAX];
    int n=0;
    char ch;

    do
    {
        printf("\n\nWELCOME TO THE BANKING SYSTEM\n");
        printf("\n1.CREATE ACCOUNT\n2.DEPOSIT MONEY\n3.WITHDRAW MONEY\n4.CHECK BALANCE\n5.EXIT\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nENTER YOUR NAME: ");
                scanf("%s",b[n].name);
                printf("\nENTER YOUR ACCOUNT NUMBER: ");
                scanf("%s",b[n].account_number);
                printf("\nENTER YOUR ACCOUNT TYPE (SAVINGS/CURRENT): ");
                scanf("%s",b[n].type);
                b[n].balance=0;
                n++;
                break;

            case 2:
                printf("\nENTER YOUR ACCOUNT NUMBER: ");
                scanf("%s",ch);
                for(i=0;i<n;i++)
                {
                    if(strcmp(ch,b[i].account_number)==0)
                    {
                        printf("\nENTER THE AMOUNT TO BE DEPOSITED: ");
                        scanf("%f",&b[i].balance);
                        printf("\nAMOUNT DEPOSITED SUCCESSFULLY\n");
                    }
                }
                break;

            case 3:
                printf("\nENTER YOUR ACCOUNT NUMBER: ");
                scanf("%s",ch);
                for(i=0;i<n;i++)
                {
                    if(strcmp(ch,b[i].account_number)==0)
                    {
                        printf("\nENTER THE AMOUNT TO BE WITHDRAWN: ");
                        scanf("%f",&b[i].balance);
                        if(b[i].balance>=0)
                        {
                            printf("\nAMOUNT WITHDRAWN SUCCESSFULLY\n");
                        }
                        else
                        {
                            printf("\nINSUFFICIENT BALANCE\n");
                        }
                    }
                }
                break;

            case 4:
                printf("\nENTER YOUR ACCOUNT NUMBER: ");
                scanf("%s",ch);
                for(i=0;i<n;i++)
                {
                    if(strcmp(ch,b[i].account_number)==0)
                    {
                        printf("\nYOUR CURRENT BALANCE IS: %.2f\n",b[i].balance);
                    }
                }
                break;

            case 5:
                printf("\nTHANK YOU FOR USING OUR SERVICES\n");
                exit(0);

            default:
                printf("\nINVALID CHOICE\n");
        }

    }while(1);
}