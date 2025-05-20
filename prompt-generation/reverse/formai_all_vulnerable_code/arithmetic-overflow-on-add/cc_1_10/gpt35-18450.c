//FormAI DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of records: ");
    scanf("%d",&n);
    char name[n][20], address[n][50], phone[n][15], dob[n][15], email[n][30], acc_type[n][15];
    int acc_num[n], balance[n], choice, amount, i;
    //name, address, phone and dob is string type, email and acc_type are also string type, acc_num and balance is integer type
    for(i=0;i<n;i++)
    {
        printf("\nEnter the details for customer %d:\n",i+1);
        printf("Name: ");
        scanf("%s",&name[i]);
        printf("Address: ");
        scanf("%s",&address[i]);
        printf("Phone: ");
        scanf("%s",&phone[i]);
        printf("Date of Birth (YYYY-MM-DD): ");
        scanf("%s",&dob[i]);
        printf("Email: ");
        scanf("%s",&email[i]);
        printf("Account type: ");
        scanf("%s",&acc_type[i]);
        printf("Account number: ");
        scanf("%d",&acc_num[i]);
        printf("Balance: ");
        scanf("%d",&balance[i]);
    }
    printf("\nEnter the operation to be performed:\n");
    printf("1. View customer details\n2. Deposit money\n3. Withdraw money\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\nEnter the customer number: ");
            scanf("%d",&i);
            printf("Customer name: %s\nAddress: %s\nPhone: %s\nDate of Birth: %s\nEmail: %s\nAccount type: %s\nAccount number: %d\nBalance: %d\n",name[i-1],address[i-1],phone[i-1],dob[i-1],email[i-1],acc_type[i-1],acc_num[i-1],balance[i-1]);
            break;
        case 2:
            printf("\nEnter the customer number: ");
            scanf("%d",&i);
            printf("Enter the amount to deposit: ");
            scanf("%d",&amount);
            balance[i-1]+=amount;
            printf("New balance: %d\n",balance[i-1]);
            break;
        case 3:
            printf("\nEnter the customer number: ");
            scanf("%d",&i);
            printf("Enter the amount to withdraw: ");
            scanf("%d",&amount);
            if(balance[i-1]>=amount)
            {
                balance[i-1]-=amount;
                printf("New balance: %d\n",balance[i-1]);
            }
            else
            {
                printf("Insufficient balance\n");
            }
            break;
        default:
            printf("\nInvalid choice\n");
    }
    return 0;
}