//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct medicine
{
    char name[20], manufacturer[20], category[10];
    float price;
    int quantity;
}med;

med m[50]; //Array of structure to store the medicine details
int count = 0;

void add_medicine() //Function to add a new medicine
{
    printf("\nEnter the name of the medicine: ");
    scanf("%s", m[count].name);
    printf("\nEnter the name of the manufacturer: ");
    scanf("%s", m[count].manufacturer);
    printf("\nEnter the category: ");
    scanf("%s", m[count].category);
    printf("\nEnter the price: ");
    scanf("%f", &m[count].price);
    printf("\nEnter the quantity: ");
    scanf("%d", &m[count].quantity);
    printf("\nMedicine added successfully!\n");
    count++;
}

void search_medicine() //Function to search for a medicine
{
    char name[20];
    int flag = 0;
    printf("\nEnter the name of the medicine to search: ");
    scanf("%s", name);
    for(int i=0; i<count; i++)
    {
        if(strcmp(name, m[i].name) == 0)
        {
            printf("\nName: %s\n", m[i].name);
            printf("Manufacturer: %s\n", m[i].manufacturer);
            printf("Category: %s\n", m[i].category);
            printf("Price: %.2f\n", m[i].price);
            printf("Quantity: %d\n", m[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("\nMedicine not found!\n");
}

void display_medicines() //Function to display all the available medicines
{
    printf("\n---Medicine Details---\n\n");
    printf("| %-18s | %-18s | %-10s | %-8s | %-8s |\n", "Name", "Manufacturer", "Category", "Price", "Quantity");
    for(int i=0; i<count; i++)
    {
        printf("| %-18s | %-18s | %-10s | %-8.2f | %-8d |\n", m[i].name, m[i].manufacturer, m[i].category, m[i].price, m[i].quantity);
    }
}

void sell_medicine() //Function to sell a medicine
{
    char name[20];
    int quantity, flag = 0;
    printf("\nEnter the name of the medicine to sell: ");
    scanf("%s", name);
    for(int i=0; i<count; i++)
    {
        if(strcmp(name, m[i].name) == 0)
        {
            printf("\nEnter the quantity to sell: ");
            scanf("%d", &quantity);
            if(m[i].quantity >= quantity)
            {
                m[i].quantity -= quantity;
                printf("\nMedicine sold successfully!\n");
                printf("Total price: %.2f\n", m[i].price*quantity);
            }
            else
                printf("\nSorry, Insufficient stock!\n");
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("\nMedicine not found!\n");
}

void menu() //Function to display the main menu
{
    int choice;
    do
    {
        printf("\n---Main Menu---\n\n");
        printf("1. Add a new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Display all the available medicines\n");
        printf("4. Sell a medicine\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: add_medicine();
                    break;
            case 2: search_medicine();
                    break;
            case 3: display_medicines();
                    break;
            case 4: sell_medicine();
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }while(1);
}

int main()
{
    printf("\n---Welcome to the Medical Store Management System---\n");
    menu();
    return 0;
}