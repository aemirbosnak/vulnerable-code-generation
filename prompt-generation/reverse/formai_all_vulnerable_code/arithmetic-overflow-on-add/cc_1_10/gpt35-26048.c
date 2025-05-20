//FormAI DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

//defining the structure of bank account
struct account
{
    char name[30];
    int acc_num;
    int balance;
}customer[10];

//function to deposit money
void deposit(int index, int amount)
{
    customer[index].balance += amount;
    printf("\nAmount deposited successfully!\n\n");
}

//function to withdraw money
void withdrawal(int index, int amount)
{
    if(customer[index].balance < amount)
    {
        printf("\nSorry! Insufficient balance!\n\n");
    }
    else
    {
        customer[index].balance -= amount;
        printf("\nAmount withdrawn successfully!\n\n");
    }
}

//function to display account details
void display(int index)
{
    printf("\n\nAccount holder name: %s\n",customer[index].name);
    printf("Account number: %d\n",customer[index].acc_num);
    printf("Balance: %d\n\n",customer[index].balance);
}

//main function
int main()
{
    int choice, account_no, amount, i, count=0;
    char name[30];
    
    //initializing the balances with 0
    for(i=0;i<10;i++)
    {
        customer[i].balance = 0;
    }
    
    while(1)
    {
        //displaying the menu
        printf("Enter your choice:\n");
        printf("1. Open new Account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Display account details\n");
        printf("5. Exit\n\n");
        
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                if(count>=10)
                {
                    printf("\n\nSorry! Maximum limit reached!\n\n");
                    break;
                }
                printf("\n\nEnter name of account holder:");
                scanf("%s",name);
                printf("Enter account number:");
                scanf("%d",&account_no);
                customer[count].acc_num = account_no;
                printf("\n\nAccount created successfully!\n\n");
                break;
                
            case 2:
                printf("\n\nEnter account number:");
                scanf("%d",&account_no);
                for(i=0;i<10;i++)
                {
                    if(customer[i].acc_num == account_no)
                    {
                        printf("\n\nEnter amount to be deposited:");
                        scanf("%d",&amount);
                        deposit(i, amount);
                        break;
                    }
                    if(i==9)
                    {
                        printf("\n\nAccount not found!\n\n");
                    }
                }
                break;
                
            case 3:
                printf("\n\nEnter account number:");
                scanf("%d",&account_no);
                for(i=0;i<10;i++)
                {
                    if(customer[i].acc_num == account_no)
                    {
                        printf("\n\nEnter amount to be withdrawn:");
                        scanf("%d",&amount);
                        withdrawal(i, amount);
                        break;
                    }
                    if(i==9)
                    {
                        printf("\n\nAccount not found!\n\n");
                    }
                }
                break;
                
            case 4:
                printf("\n\nEnter account number:");
                scanf("%d",&account_no);
                for(i=0;i<10;i++)
                {
                    if(customer[i].acc_num == account_no)
                    {
                        display(i);
                        break;
                    }
                    if(i==9)
                    {
                        printf("\n\nAccount not found!\n\n");
                    }
                }
                break;
                
            case 5:
                printf("\n\nThank you for using our services!\n\n");
                exit(0);
                
            default:
                printf("\n\nInvalid choice!\n\n");
                break;
        }
        
        count++;
    }
    return 0;
}