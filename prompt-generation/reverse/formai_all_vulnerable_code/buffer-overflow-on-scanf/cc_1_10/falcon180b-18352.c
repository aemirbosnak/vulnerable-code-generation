//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char names[MAX][50];
int count=0;

void addCustomer()
{
    char name[50];
    printf("Enter the name of the customer: ");
    scanf("%s",name);
    strcpy(names[count],name);
    count++;
}

void displayCustomers()
{
    int i;
    for(i=0;i<count;i++)
    {
        printf("\n%s",names[i]);
    }
}

void placeOrder()
{
    char order[50];
    int i,j=0,k=0;
    float amount=0.0;
    printf("\nEnter the order: ");
    scanf("%s",order);

    for(i=0;i<strlen(order);i++)
    {
        if(isalpha(order[i]))
        {
            j++;
        }
        else if(isdigit(order[i]))
        {
            k++;
        }
    }

    if(j==k)
    {
        printf("\nOrder placed successfully!");
        amount = (float)rand()/RAND_MAX*100;
        printf("\nAmount to be paid: %.2f",amount);
    }
    else
    {
        printf("\nInvalid order!");
    }
}

void payBill()
{
    float amount;
    printf("\nEnter the amount to be paid: ");
    scanf("%f",&amount);

    if(amount>=0 && amount<=100)
    {
        printf("\nPayment successful!");
    }
    else
    {
        printf("\nInvalid amount!");
    }
}

int main()
{
    int choice;
    do
    {
        printf("\nCafe Billing System\n");
        printf("\n1. Add customer");
        printf("\n2. Display customers");
        printf("\n3. Place order");
        printf("\n4. Pay bill");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addCustomer();
                break;

            case 2:
                displayCustomers();
                break;

            case 3:
                placeOrder();
                break;

            case 4:
                payBill();
                break;

            case 5:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice!");
        }

    }while(1);

    return 0;
}