//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Function prototypes
void menu();
void display();
void billing();

// Global variables
char cafeName[] = "C Cafe";
int americanCoffeePrice = 50;
int cappuccinoPrice = 80;
int lattePrice = 70;
int sandwichPrice = 100;
int cakePrice = 120;
int total = 0;

int main()
{
    int choice, cont;
    char name[20];

    printf("Welcome to %s, my lord or lady!\n", cafeName);

    do
    {
        printf("What may I offer thee, fair customer?\n");
        printf("[1] View Menu\n");
        printf("[2] Place Order\n");
        printf("[3] View Bill\n");
        printf("[4] Exit\n");

        printf("Enter your choice, sweet customer: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // View Menu
            display();
            break;
        case 2: // Place Order
            billing();
            break;
        case 3: // View Bill
            printf("Your bill is %d coins of gold, fair %s.\n", total, name);
            break;
        case 4: // Exit
            printf("Farewell, fair %s. May the gods smile upon you.\n", name);
            return 0;
        default:
            printf("I cannot understand what you mean, sweet customer. Please try again.\n");
            break;
        }

        printf("Would you like to continue, sweet %s? [1] Yes [0] No: ", name);
        scanf("%d", &cont);
    } while (cont != 0);

    printf("Farewell, fair %s. May the gods smile upon you.\n", name);
    return 0;
}

void menu()
{
    printf("========== %s MENU ==========\n", cafeName);
    printf("[1] American Coffee - %d coins of gold\n", americanCoffeePrice);
    printf("[2] Cappuccino - %d coins of gold\n", cappuccinoPrice);
    printf("[3] Latte - %d coins of gold\n", lattePrice);
    printf("[4] Sandwich - %d coins of gold\n", sandwichPrice);
    printf("[5] Cake - %d coins of gold\n", cakePrice);
}

void display()
{
    printf("Greetings, fair customer. Here is the menu of our %s.\n", cafeName);
    menu();
}

void billing()
{
    int qty, itemPrice;
    char order[20];

    printf("What would you like to order, sweet customer?\n");
    printf("Please enter the item code: ");
    scanf("%s", order);

    if (strcmp(order, "1") == 0)
    {
        qty = 1;
        itemPrice = americanCoffeePrice;
    }
    else if (strcmp(order, "2") == 0)
    {
        qty = 1;
        itemPrice = cappuccinoPrice;
    }
    else if (strcmp(order, "3") == 0)
    {
        qty = 1;
        itemPrice = lattePrice;
    }
    else if (strcmp(order, "4") == 0)
    {
        qty = 1;
        itemPrice = sandwichPrice;
    }
    else if (strcmp(order, "5") == 0)
    {
        qty = 1;
        itemPrice = cakePrice;
    }
    else
    {
        printf("Sorry, sweet customer. We do not have that item in our menu.\n");
        return;
    }

    total += qty * itemPrice;

    printf("%d coins of gold added to your bill, fair customer.\n", qty * itemPrice);
}