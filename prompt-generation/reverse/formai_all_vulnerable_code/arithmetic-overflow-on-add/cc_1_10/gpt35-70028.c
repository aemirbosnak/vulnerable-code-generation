//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: genious
#include <stdio.h>
#include <string.h>

// struct to store items in the menu
typedef struct Item
{
    char name[50];
    int price;
} Item;

// struct to store customer details and order
typedef struct Order
{
    char name[50];
    int table_number;
    Item items_ordered[10];
    int num_items_ordered;
} Order;

// function to calculate total bill amount
int calculate_bill(Order order)
{
    int total_price = 0;
    for (int i = 0; i < order.num_items_ordered; i++)
    {
        total_price += order.items_ordered[i].price;
    }
    return total_price;
}

int main()
{
    // create menu items
    Item menu[10];
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 100;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 80;
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 150;
    strcpy(menu[3].name, "Burger");
    menu[3].price = 200;
    strcpy(menu[4].name, "French Fries");
    menu[4].price = 100;
    strcpy(menu[5].name, "Coke");
    menu[5].price = 50;
    strcpy(menu[6].name, "Water");
    menu[6].price = 20;

    // take customer order details
    Order order;
    printf("Enter your name: ");
    scanf("%s", order.name);
    printf("Enter table number: ");
    scanf("%d", &order.table_number);
    printf("Enter number of items ordered: ");
    scanf("%d", &order.num_items_ordered);
    for (int i = 0; i < order.num_items_ordered; i++)
    {
        printf("Enter item %d (name price): ", i+1);
        scanf("%s %d", order.items_ordered[i].name, &order.items_ordered[i].price);
    }

    // calculate bill and print receipt
    int total_bill = calculate_bill(order);
    printf("\n\n******** C Cafe ********\n");
    printf("Customer Name: %s\n", order.name);
    printf("Table Number: %d\n", order.table_number);
    printf("---------------------------------\n");
    printf("Items Ordered:\n");
    for (int i = 0; i < order.num_items_ordered; i++)
    {
        printf("- %s\t%d\n", order.items_ordered[i].name, order.items_ordered[i].price);
    }
    printf("---------------------------------\n");
    printf("Total Bill: %d\n", total_bill);
    printf("Thank you for dining at C Cafe!");

    return 0;
}