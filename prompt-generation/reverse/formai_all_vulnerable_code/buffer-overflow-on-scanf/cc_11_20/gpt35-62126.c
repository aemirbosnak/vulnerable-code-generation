//FormAI DATASET v1.0 Category: Banking Record System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
struct Bank_Record
{
    char customer_name[50];
    int account_number;
    float balance;
}bank[100];

int main()
{
    int n,i,choice,account_number;
    char customer_name[50];
    float balance;
    printf("Enter the number of customers:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter customer name:");
        scanf("%s",&bank[i].customer_name);
        printf("Enter account number:");
        scanf("%d",&bank[i].account_number);
        printf("Enter balance:");
        scanf("%f",&bank[i].balance);
        printf("\n");
    }
    while(1)
    {
        printf("\n1.Display all records\n2.Search a record\n3.Update a record\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nAll Bank Records Are Listed Below:");
                printf("\nCUSTOMER NAME\tACCOUNT NUMBER\tBALANCE\n");
                for(i=0;i<n;i++)
                    printf("%s\t\t%d\t\t%f\n",bank[i].customer_name,bank[i].account_number,bank[i].balance);
                break;
            case 2:
                printf("\nEnter the account number you want to search:");
                scanf("%d",&account_number);
                for(i=0;i<n;i++)
                {
                    if(bank[i].account_number==account_number)
                    {
                        printf("\nRecord Found:\n");
                        printf("CUSTOMER NAME\tACCOUNT NUMBER\tBALANCE\n");
                        printf("%s\t\t%d\t\t%f\n",bank[i].customer_name,bank[i].account_number,bank[i].balance);
                    }
                    else
                        printf("\nRecord Not Found.");
                }
                break;
            case 3:
                printf("\nEnter the account number you want to update:");
                scanf("%d",&account_number);
                for(i=0;i<n;i++)
                {
                    if(bank[i].account_number==account_number)
                    {
                        printf("\nEnter new customer name:");
                        scanf("%s",&bank[i].customer_name);
                        printf("Enter new balance:");
                        scanf("%f",&bank[i].balance);
                        printf("\nRecord Updated Successfully!");
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice");
        }
    }
    return 0;
}