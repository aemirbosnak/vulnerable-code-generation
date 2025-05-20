//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define struct for cafe items and orders
typedef struct Menu_Item
{
    char name[30];
    float price;
} menu_item;

typedef struct Order_Item
{
    menu_item item;
    int quantity;
} order_item;

// Global variables
menu_item menu[10]; // array to store menu items
order_item order[10]; // array to store ordered items
int order_count = 0; // number of ordered items
float total_bill = 0.0; // total bill amount

// Function to display menu
void display_menu()
{
    printf("\n===== CAFE MENU =====\n\n");
    for(int i=0; i<10; i++)
    {
        printf("%d. %-20s Rs. %.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to add item to order
void add_to_order(int item_number, int quantity)
{
    order[order_count].item = menu[item_number-1];
    order[order_count].quantity = quantity;
    order_count++;
    printf("\n** Item added to order **\n");
}

// Function to display order
void display_order()
{
    printf("\n===== ORDER DETAILS =====\n\n");
    for(int i=0; i<order_count; i++)
    {
        printf("%d. %-20s x %d = Rs. %.2f\n", i+1, order[i].item.name, order[i].quantity, (order[i].item.price*order[i].quantity));
        total_bill += (order[i].item.price*order[i].quantity);
    }
    printf("\n=========================\nTotal bill amount: Rs. %.2f\n", total_bill);
}

int main()
{
    // Initialize menu items
    menu_item item1 = {"Black Coffee", 120.0};
    menu_item item2 = {"Cappuccino", 150.0};
    menu_item item3 = {"Espresso", 100.0};
    menu_item item4 = {"Latte", 170.0};
    menu_item item5 = {"Hot Chocolate", 130.0};
    menu_item item6 = {"Mochaccino", 160.0};
    menu_item item7 = {"Americano", 110.0};
    menu_item item8 = {"Iced Coffee", 140.0};
    menu_item item9 = {"Iced Tea", 90.0};
    menu_item item10 = {"Lemonade", 80.0};

    // Add menu items to array
    menu[0] = item1;
    menu[1] = item2;
    menu[2] = item3;
    menu[3] = item4;
    menu[4] = item5;
    menu[5] = item6;
    menu[6] = item7;
    menu[7] = item8;
    menu[8] = item9;
    menu[9] = item10;

    printf("Welcome to the Mind-Bending Cafe Billing System!\n\n");
    display_menu();

    int choice, quantity;
    char another;
    do
    {
        printf("\nEnter item number to order: ");
        scanf("%d", &choice);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        add_to_order(choice, quantity);

        printf("\nDo you want to order another item? (Y/N) ");
        scanf("%s", &another);

    } while(another == 'Y' || another == 'y');

    display_order();

    return 0;
}