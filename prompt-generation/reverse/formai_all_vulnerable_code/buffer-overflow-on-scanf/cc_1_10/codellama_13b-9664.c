//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
/*
* C Cafe Billing System Example Program
*
* This program demonstrates a simple Cafe Billing System using the C programming language.
*/

#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
#define MENU_ITEM1 "Coffee"
#define MENU_ITEM2 "Tea"
#define MENU_ITEM3 "Espresso"
#define MENU_ITEM4 "Lemonade"
#define MENU_ITEM5 "Cappuccino"

// Define the prices for each menu item
#define PRICE_ITEM1 2.50
#define PRICE_ITEM2 1.50
#define PRICE_ITEM3 3.00
#define PRICE_ITEM4 2.00
#define PRICE_ITEM5 4.00

// Define the struct for a Cafe Order
struct order {
    char menu_item[20];
    float price;
};

// Define the struct for a Cafe Customer
struct customer {
    char name[20];
    int age;
    struct order order;
};

// Function to display the menu
void display_menu() {
    printf("Welcome to the Cafe! Here's our menu:\n");
    printf("%s - %0.2f\n", MENU_ITEM1, PRICE_ITEM1);
    printf("%s - %0.2f\n", MENU_ITEM2, PRICE_ITEM2);
    printf("%s - %0.2f\n", MENU_ITEM3, PRICE_ITEM3);
    printf("%s - %0.2f\n", MENU_ITEM4, PRICE_ITEM4);
    printf("%s - %0.2f\n", MENU_ITEM5, PRICE_ITEM5);
}

// Function to handle an order
void handle_order(struct customer *cust) {
    printf("What would you like to order? ");
    scanf("%s", cust->order.menu_item);
    printf("How many would you like to order? ");
    scanf("%f", &cust->order.price);
}

// Function to display the bill
void display_bill(struct customer *cust) {
    printf("Your total bill is: %0.2f\n", cust->order.price);
}

int main() {
    // Create a new customer
    struct customer cust;
    // Set the customer's name and age
    printf("What is your name? ");
    scanf("%s", cust.name);
    printf("How old are you? ");
    scanf("%d", &cust.age);
    // Handle the customer's order
    handle_order(&cust);
    // Display the bill
    display_bill(&cust);
    return 0;
}