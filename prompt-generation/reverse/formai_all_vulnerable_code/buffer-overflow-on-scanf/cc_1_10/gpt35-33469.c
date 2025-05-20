//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void menu();
void order(int*, int*, int*, int*);
void bill(int, int, int, int);

int main()
{
    int coffee = 0, tea = 0, pastry = 0, sandwich = 0;
    int choice, done = 0;
    
    while(!done)
    {
        menu();
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                order(&coffee, &tea, &pastry, &sandwich);
                break;
            case 2:
                bill(coffee, tea, pastry, sandwich);
                break;
            case 3:
                done = 1;
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    printf("Thank you for visiting our cafe!\n");
    
    return 0;
}

// function to display menu
void menu()
{
    printf("\n********* Cafe Menu *********\n\n");
    printf("1. Place an order\n");
    printf("2. Generate bill\n");
    printf("3. Exit\n");
    printf("\nEnter your choice: ");
}

// function to take order
void order(int* coffee, int* tea, int* pastry, int* sandwich)
{
    int choice, quantity;
    
    printf("\n***** Order Menu *****\n\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Pastry\n");
    printf("4. Sandwich\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    switch(choice)
    {
        case 1:
            *coffee += quantity;
            printf("You have ordered %d coffee(s).\n", quantity);
            break;
        case 2:
            *tea += quantity;
            printf("You have ordered %d tea(s).\n", quantity);
            break;
        case 3:
            *pastry += quantity;
            printf("You have ordered %d pastry(s).\n", quantity);
            break;
        case 4:
            *sandwich += quantity;
            printf("You have ordered %d sandwich(s).\n", quantity);
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}

// function to generate bill
void bill(int coffee, int tea, int pastry, int sandwich)
{
    int total = 0;
    
    printf("\n**** Cafe Bill ****\n\n");
    printf("Item\t\tQuantity\tPrice\n");
    printf("----------------------------------\n");
    
    if(coffee > 0)
    {
        printf("Coffee\t\t%d\t\t$%d\n", coffee, coffee * 2);
        total += coffee * 2;
    }
    
    if(tea > 0)
    {
        printf("Tea\t\t%d\t\t$%d\n", tea, tea * 1);
        total += tea * 1;
    }
    
    if(pastry > 0)
    {
        printf("Pastry\t\t%d\t\t$%d\n", pastry, pastry * 3);
        total += pastry * 3;
    }
    
    if(sandwich > 0)
    {
        printf("Sandwich\t%d\t\t$%d\n", sandwich, sandwich * 4);
        total += sandwich * 4;
    }
    
    printf("----------------------------------\n");
    printf("Total\t\t\t\t$%d\n", total);
}