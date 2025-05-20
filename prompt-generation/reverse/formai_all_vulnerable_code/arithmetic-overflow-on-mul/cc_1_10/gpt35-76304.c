//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <string.h>

// Structure for items in the cafe menu
typedef struct item {
    char name[50];
    int price;
} Item;

// Global variables
Item menu[10];
int total_items = 0;
int total_bill = 0;

// Function to add items to the menu
void add_item(char name[50], int price) {
    strcpy(menu[total_items].name, name);
    menu[total_items].price = price;
    total_items++;
}

// Function to display the menu
void display_menu() {
    printf("Welcome to Cafe Medieval!\n\n");
    printf("Menu:\n");
    for (int i=0; i<total_items; i++) {
        printf("%d. %s - %d gold coins\n", i+1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

// Function to place an order
void place_order() {
    int choice, quantity;
    printf("Enter the item number: ");
    scanf("%d", &choice);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    total_bill += menu[choice-1].price * quantity;
}

// Function to display the total bill
void display_bill() {
    printf("Your total bill is %d gold coins.\n", total_bill);
}

int main() {
    // Add items to the menu
    add_item("Roasted Chicken", 50);
    add_item("Beef Stew", 40);
    add_item("Fish and Chips", 30);
    
    // Display the menu
    display_menu();
    
    // Take the order
    char choice;
    do {
        place_order();
        printf("Do you want to order anything else? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    // Display the total bill
    display_bill();
    
    return 0;
}