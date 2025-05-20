//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void add_item(void);
void view_stock(void);
void billing(void);
void generate_bill();

int count=0;

struct Item
{
    char name[20];
    int qty;
    float price;
};

struct Item item_list[100];

void main()
{
    int choice=0;

    printf("\n\t\t       C CAFE\n");
    printf("\t\t---BILLING SYSTEM---\n");

    while(choice!=4)
    {
        printf("\n\nSelect an option from the below menu:\n");
        printf("1. Add Items to the Stock\n");
        printf("2. View Stock\n");
        printf("3. Generate Billing\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add_item();
                break;
            case 2:
                view_stock();
                break;
            case 3:
                billing();
                break;
            case 4:
                printf("\nThank You for using C CAFE Billing System!\n");
                break;
            default:
                printf("\nInvalid Option. Please try again!\n");
        }
    }
}

void add_item()
{
    printf("\nEnter the details of the Item:\n");
    printf("Name: ");
    scanf("%s",&item_list[count].name);
    printf("Price: ");
    scanf("%f",&item_list[count].price);
    printf("Quantity: ");
    scanf("%d",&item_list[count].qty);
    count++;
    printf("\nItem Added Successfully!\n");
}

void view_stock()
{
    if(count==0)
    {
        printf("\nNo Items in Stock.\n");
    }
    else
    {
        printf("\n\t\t   STOCK DETAILS\n");
        printf("=======================================================\n");
        printf("S.No.\tItem Name\tPrice\tQuantity\n");
        printf("=======================================================\n");
        for(int i=0;i<count;i++)
        {
            printf("%d\t%s\t\t%.2f\t%d\n",i+1,item_list[i].name,item_list[i].price,item_list[i].qty);
        }
        printf("=======================================================\n");
    }
}

void billing()
{
    int bill_choice=0;
    float discount=0,total=0;

    printf("\nSelect the Items to be billed:\n");
    view_stock();
    printf("Enter 0 to Stop Selecting Items.\n");

    do
    {
        printf("Enter the S.No. of Item %d: ",bill_choice+1);
        scanf("%d",&bill_choice);

        if((bill_choice<1) || (bill_choice>count))
        {
            printf("\nInvalid Selection. Please try again!\n");
        }
        else if(item_list[bill_choice-1].qty<=0)
        {
            printf("\nSorry! Item out of Stock.\n");
            bill_choice=0;
        }
        else
        {
            total+=item_list[bill_choice-1].price;
            item_list[bill_choice-1].qty--;
            printf("\nItem Added to Bill!\n");
        }

    }while(bill_choice!=0);

    printf("\n=============================================\n");
    printf("\t\tBILL\n");
    printf("=============================================\n");
    printf("S.No.\tItem Name\tQuantity\tPrice\n");
    printf("=============================================\n");

    for(int i=0;i<count;i++)
    {
        if(item_list[i].qty!=0)
        {
            printf("%d\t%s\t\t%d\t\t%.2f\n",i+1,item_list[i].name,item_list[i].qty,item_list[i].price);
        }   
    }

    printf("=============================================\n");
    printf("\nTotal Amount: %.2f\n",total);

    if(total>=500)
    {
        discount=total*0.1;
        printf("Discount (10%%): -%.2f\n",discount);
        total-=discount;
    }

    printf("=============================================\n");
    printf("Net Payable Amount: %.2f\n",total);
    printf("=============================================\n");
}