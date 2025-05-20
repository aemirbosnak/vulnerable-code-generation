//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct menu_item {  // structure to hold cafe menu items
    char name[50];
    float price;
};

struct order {  // structure to hold order details
    char name[50];
    int quantity;
};

int main() {
    struct menu_item menu[5];  // menu with 5 items
    struct order orders[10];  // store upto 10 orders
    
    // populating the menu
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 2.50;
    strcpy(menu[1].name, "Tea");
    menu[1].price = 2.00;
    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 3.50;
    strcpy(menu[3].name, "Muffin");
    menu[3].price = 1.50;
    strcpy(menu[4].name, "Brownie");
    menu[4].price = 1.75;
    
    // variables to hold total bill
    float total_cost = 0.0;
    float item_cost = 0.0;
    
    int order_count = 0;
    
    // prompt customer for order
    int order_continue = 1;
    int item_number = 0;
    while (order_continue) {
        printf("\nMenu:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s - %.2f\n", i+1, menu[i].name, menu[i].price);
        }
        printf("Enter item number to order (-1 to finish): ");
        scanf("%d", &item_number);
        if (item_number == -1) {
            order_continue = 0;
            break;
        }
        item_number = item_number - 1;
        printf("Enter quantity: ");
        scanf("%d", &orders[order_count].quantity);
        strcpy(orders[order_count].name, menu[item_number].name);
        order_count++;
    }
    
    // print customer's order
    printf("\nYour Order:\n");
    for (int i = 0; i < order_count; i++) {
        item_cost = orders[i].quantity * menu[0].price;
        printf("%d. %s x %d - %.2f\n", i+1, orders[i].name, orders[i].quantity, item_cost);
        total_cost += item_cost;
    }
    
    // generate bill
    printf("\nTotal Bill: %.2f\n", total_cost);
    
    // exit program
    return 0;
}