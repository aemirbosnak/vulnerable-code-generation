//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine
{
    char name[50];
    int price;
    int quantity;
};

typedef struct medicine med;

void addMedicine(med* pmed, int* pcount)
{
    int i, flag=0, added=0;
    char name[50];
    int price, quantity;

    printf("Enter the name of the medicine: ");
    scanf("%s", name);

    for(i=0; i<*pcount; i++)
    {
        if(strcmp(name, (pmed+i)->name)==0)
        {
            printf("\nMedicine already exists...");
            printf("\nQuantity available: %d", (pmed+i)->quantity);
            printf("\nEnter quantity to add: ");
            scanf("%d", &quantity);
            (pmed+i)->quantity+=(quantity);
            printf("\nQuantity updated successfully!");
            added=1;
            break;
        }
    }

    if(added==0)
    {
        printf("\nEnter the price per unit of the medicine: ");
        scanf("%d", &price);

        printf("\nEnter the quantity in stock of the medicine: ");
        scanf("%d", &quantity);

        (pmed+*pcount)->price=price;
        (pmed+*pcount)->quantity=quantity;

        strcpy((pmed+*pcount)->name, name);
        (*pcount)++;
        printf("\nMedicine added successfully!");
    }

    return;
}

void sellMedicine(med* pmed, int* pcount)
{
    int i, flag=0, sold=0;
    char name[50];
    int quantity;

    printf("Enter the name of the medicine: ");
    scanf("%s", name);

    for(i=0; i<*pcount; i++)
    {
        if(strcmp(name, (pmed+i)->name)==0)
        {
            printf("\nQuantity available: %d", (pmed+i)->quantity);
            printf("\nEnter quantity to sell: ");
            scanf("%d", &quantity);

            if(quantity<=((pmed+i)->quantity))
            {
                printf("\nSelling %d units of %s at Rs%d per unit...", quantity, (pmed+i)->name, (pmed+i)->price);
                printf("\nTotal amount: %d", (quantity*(pmed+i)->price));
                (pmed+i)->quantity-=(quantity);
                printf("\nThank you for shopping with us!");
                sold=1;
                break;
            }

            else
            {
                printf("\nInsufficient quantity available...");
            }
        }
    }

    if(sold==0)
    {
        printf("\nMedicine not found...");
    }

    return;
}

void displayMedicine(med* pmed, int* pcount)
{
    int i;

    if(*pcount==0)
    {
        printf("\nNo medicine added yet...");
        return;
    }

    printf("\nMedicine list:\n\n");

    for(i=0; i<*pcount; i++)
    {
        printf("\nName: %s", (pmed+i)->name);
        printf("\nPrice per unit: %d", (pmed+i)->price);
        printf("\nQuantity in stock: %d\n", (pmed+i)->quantity);
    }

    return;
}

void main()
{
    med medlist[50];
    int count=0, exit=0, choice;

    printf("\n---Welcome to the Medical Store Management System---");

    while(!exit)
    {
        printf("\n\n---Main Menu---");
        printf("\n1. Add medicine");
        printf("\n2. Sell medicine");
        printf("\n3. Display medicine");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addMedicine(medlist, &count); break;
            case 2: sellMedicine(medlist, &count); break;
            case 3: displayMedicine(medlist, &count); break;
            case 4: exit=1; break;
            default: printf("\nInvalid choice..."); break;
        }
    }

    printf("\nThank you for using the Medical Store Management System...");
    return;
}