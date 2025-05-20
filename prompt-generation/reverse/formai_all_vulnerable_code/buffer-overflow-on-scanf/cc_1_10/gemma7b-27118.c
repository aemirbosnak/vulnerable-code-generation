//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a coffee item
typedef struct CoffeeItem
{
    char name[20];
    float price;
    int quantity;
} CoffeeItem;

// Create an array of coffee items
CoffeeItem items[] = {
    {"Latte", 2.50, 0},
    {"Cappuccino", 3.00, 0},
    {"Americano", 2.00, 0},
    {"Mocha", 3.50, 0}
};

// Function to calculate the total cost of an order
float calculateTotalCost(CoffeeItem item, int quantity)
{
    return item.price * quantity;
}

// Function to display the menu
void displayMenu()
{
    printf("*** Coffee Menu ***\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s - $%.2f, Quantity: %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

// Function to take an order
void takeOrder()
{
    char item_name[20];
    int quantity;

    printf("Enter item name:");
    scanf("%s", item_name);

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(item_name, items[i].name) == 0)
        {
            printf("Enter quantity:");
            scanf("%d", &quantity);

            items[i].quantity += quantity;
            break;
        }
    }

    if (quantity == 0)
    {
        printf("Item not found.\n");
    }
}

// Function to checkout
void checkout()
{
    float total_cost = 0.0;

    for (int i = 0; i < 4; i++)
    {
        total_cost += calculateTotalCost(items[i], items[i].quantity);
    }

    printf("Total cost: $%.2f\n", total_cost);

    for (int i = 0; i < 4; i++)
    {
        items[i].quantity = 0;
    }
}

int main()
{
    displayMenu();
    takeOrder();
    checkout();

    return 0;
}