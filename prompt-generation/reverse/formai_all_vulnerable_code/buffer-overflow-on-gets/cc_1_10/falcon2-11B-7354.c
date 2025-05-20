//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
    int choice,bill_no,food_no,food_amt,bill_amt,tax_rate,service_charge,discount,total_amt;
    char name[50],food_name[50],food_type[50];
    struct bill_details
    {
        int bill_no;
        char name[50];
        char food_name[50];
        char food_type[50];
        int food_no;
        float food_amt;
        float tax_rate;
        float service_charge;
        float discount;
        float total_amt;
    };
    struct bill_details bill[100];
    int i=0;
    while(1)
    {
        printf("\nWelcome to the Decentralized Cafe Billing System");
        printf("\nPlease enter your choice:\n1.Customer Details\n2.Add New Bill\n3.View Bills\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nCustomer Details\n");
                printf("\nPlease enter your name:");
                gets(name);
                printf("\nYour name is %s\n",name);
                break;
            case 2:
                printf("\nAdd New Bill\n");
                printf("\nPlease enter your bill number:");
                scanf("%d",&bill_no);
                printf("\nPlease enter your name:");
                gets(name);
                printf("\nPlease enter your food name:");
                gets(food_name);
                printf("\nPlease enter your food type:");
                gets(food_type);
                printf("\nPlease enter your food number:");
                scanf("%d",&food_no);
                printf("\nPlease enter your food amount:");
                scanf("%f",&food_amt);
                printf("\nPlease enter your tax rate:");
                scanf("%f",&tax_rate);
                printf("\nPlease enter your service charge:");
                scanf("%f",&service_charge);
                printf("\nPlease enter your discount:");
                scanf("%f",&discount);
                printf("\nPlease enter your total amount:");
                scanf("%f",&total_amt);
                bill[i].bill_no=bill_no;
                strcpy(bill[i].name,name);
                strcpy(bill[i].food_name,food_name);
                strcpy(bill[i].food_type,food_type);
                bill[i].food_no=food_no;
                bill[i].food_amt=food_amt;
                bill[i].tax_rate=tax_rate;
                bill[i].service_charge=service_charge;
                bill[i].discount=discount;
                bill[i].total_amt=total_amt;
                printf("\nBill Number %d added successfully\n",bill_no);
                break;
            case 3:
                printf("\nView Bills\n");
                for(i=0;i<100;i++)
                {
                    printf("\nBill Number %d\n",bill[i].bill_no);
                    printf("\nCustomer Name %s\n",bill[i].name);
                    printf("\nFood Name %s\n",bill[i].food_name);
                    printf("\nFood Type %s\n",bill[i].food_type);
                    printf("\nFood Number %d\n",bill[i].food_no);
                    printf("\nFood Amount %.2f\n",bill[i].food_amt);
                    printf("\nTax Rate %.2f\n",bill[i].tax_rate);
                    printf("\nService Charge %.2f\n",bill[i].service_charge);
                    printf("\nDiscount %.2f\n",bill[i].discount);
                    printf("\nTotal Amount %.2f\n",bill[i].total_amt);
                    printf("\n\n");
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice\n");
                break;
        }
    }
    return 0;
}