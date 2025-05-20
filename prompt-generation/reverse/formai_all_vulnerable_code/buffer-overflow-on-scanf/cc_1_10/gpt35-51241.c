//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define PRICE_TEA  5.00
#define PRICE_COFFEE 8.00
#define PRICE_SANDWICH 10.00
#define TAX_RATE 0.05  //5% tax
#define SERVICE_CHARGE 0.10 //10% service charge
void display_menu(); //Function prototype to display menu
int main()
{
    char option[20], name[50], contact[15];
    int quantity;
    float subtotal, tax, sc, total, cash, change;

    printf("\t\tWelcome to the C Cafe\n\n");

    display_menu();

    printf("\n\nEnter the option you want to order: ");
    scanf("%s", option);

    if(strcmp(option, "1")==0)
    {
        printf("You have chosen tea\n");
        printf("Enter the quantity you want: ");
        scanf("%d", &quantity);
        subtotal = PRICE_TEA*quantity;
    }
    else if(strcmp(option, "2")==0)
    {
        printf("You have chosen coffee\n");
        printf("Enter the quantity you want: ");
        scanf("%d", &quantity);
        subtotal = PRICE_COFFEE*quantity;
    }
    else if(strcmp(option, "3")==0)
    {
        printf("You have chosen sandwich\n");
        printf("Enter the quantity you want: ");
        scanf("%d", &quantity);
        subtotal = PRICE_SANDWICH*quantity;
    }
    else
    {
        printf("You have entered an invalid option\n");
        return 0;
    }

    tax = subtotal*TAX_RATE;
    sc = subtotal*SERVICE_CHARGE;
    total = subtotal+tax+sc;

    printf("\n\nEnter your name: ");
    scanf("%s", name);
    printf("Enter your contact number: ");
    scanf("%s", contact);

    printf("\n\n\t\t  C Cafe Invoice\n");
    printf("\t\t------------------------\n");
    printf("\t\tItem: %s\n", option);
    printf("\t\tQuantity: %d\n", quantity);
    printf("\t\tSubtotal: $%.2f\n", subtotal);
    printf("\t\tTax: $%.2f\n", tax);
    printf("\t\tService Charge: $%.2f\n", sc);
    printf("\t\t------------------------\n");
    printf("\t\tTotal: $%.2f\n\n", total);

    printf("Enter the cash given: ");
    scanf("%f", &cash);
    change = cash-total;
    printf("Change: $%.2f\n\n", change);

    printf("Thank you %s for dining at C Cafe\n", name);
    printf("Contact number: %s\n\n", contact);

    return 0;
}

void display_menu()
{
    printf("\n\n\t\t  C Cafe Menu\n");
    printf("\t\t------------------------\n");
    printf("\t\t1. Tea        $%.2f\n", PRICE_TEA);
    printf("\t\t2. Coffee     $%.2f\n", PRICE_COFFEE);
    printf("\t\t3. Sandwich   $%.2f\n", PRICE_SANDWICH);
    printf("\t\t------------------------\n");
}