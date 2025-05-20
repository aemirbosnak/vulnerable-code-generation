//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine
{
    char name[50];
    int quantity;
    float price;
};

struct bill
{
    char name[50];
    int quantity;
    float price;
    float total;
};

void add_medicine(struct medicine *m);
void view_medicine(struct medicine *m);
void sale_medicine(struct medicine *m, struct bill *b);
void print_bill(struct bill *b, int count, float total);

int main()
{
    struct medicine m[50];
    struct bill b[50];
    int choice;
    int i=0,n=0;
    float total=0;
    int count=0;

    do
    {
        printf("\n\t\t\t***** MEDICAL STORE MANAGEMENT SYSTEM *****\n");
        printf("\n\t1.Add Medicine\n\t2.View Medicine\n\t3.Sale Medicine\n\t4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: add_medicine(&m[i]);
                    i++;
                    n++;
                    break;

            case 2: view_medicine(&m[0]);
                    break;

            case 3: sale_medicine(&m[0],&b[count]);
                    total+=b[count].price;
                    count++;
                    break;

            case 4: exit(0);
        }
    } while(choice != 4);

    print_bill(&b[0],count,total);

    return 0;
}

void add_medicine(struct medicine *m)
{
    printf("\nEnter the medicine name: ");
    scanf("%s",m->name);
    printf("\nEnter the medicine quantity: ");
    scanf("%d",&m->quantity);
    printf("\nEnter the medicine price: ");
    scanf("%f",&m->price);
}

void view_medicine(struct medicine *m)
{
    int i;
    printf("\n\t\t\t***** VIEW MEDICINE *****\n");
    printf("\nMedicine Name\t\tMedicine Quantity\t\tMedicine Price\n");

    for(i=0;i<50;i++)
    {
        if(m[i].quantity != 0)
        {
            printf("%s\t\t\t%d\t\t\t%.2f\n",m[i].name,m[i].quantity,m[i].price);
        }
        else
        {
            break;
        }
    }
}

void sale_medicine(struct medicine *m, struct bill *b)
{
    int i;
    char name[50];
    printf("\nEnter the medicine name to buy: ");
    scanf("%s",name);

    for(i=0;i<50;i++)
    {
        if(strcmp(name,m[i].name) == 0)
        {
            printf("\nEnter the medicine Quantity: ");
            scanf("%d",&b->quantity);
            if(b->quantity <= m[i].quantity)
            {
                strcpy(b->name,m[i].name);
                b->price = b->quantity * m[i].price;
                m[i].quantity -= b->quantity;
            }
            else
            {
                printf("\nNot enough medicine quantity is in stock to buy.\n");
            }
            break;
        }
    }

    if(i == 50)
    {
        printf("\nMedicine not found in stock.\n");
    }
}

void print_bill(struct bill *b, int count, float total)
{
    int i;
    printf("\n\t\t\t***** BILLING DETAILS *****\n");
    printf("\nMedicine Name\t\tMedicine Quantity\t\tMedicine Price\n");

    for(i=0;i<count;i++)
    {
        printf("%s\t\t\t%d\t\t\t%.2f\n",b[i].name,b[i].quantity,b[i].price);
    }

    printf("\nTotal Bill Amount: %.2f\n",total);
}