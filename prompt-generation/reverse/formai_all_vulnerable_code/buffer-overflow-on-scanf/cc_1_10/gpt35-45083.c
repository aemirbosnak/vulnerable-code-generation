//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50

// Struct to hold details about an item
typedef struct {
    char name[20];
    int price;
    int quantity;
} Item;

// Struct to hold details about a bill
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    int total_price;
} Bill;

// Function to create and return a new item with given details
Item create_item(char name[], int price, int quantity) {
    Item item;
    sprintf(item.name, "%s", name);
    item.price = price;
    item.quantity = quantity;
    return item;
}

// Function to add an item to the given bill
void add_item(Bill *bill, Item item) {
    bill->items[bill->num_items++] = item;
    bill->total_price += (item.price * item.quantity);
}

// Function to print the input prompt and return the user's input
int get_input(char prompt[]) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

int main() {
    // Create a new bill
    Bill bill = { .total_price = 0, .num_items = 0 };

    // Display welcome message and main menu
    printf("Welcome to Brave Cafe Billing System!\n");
    printf("1. Add Item to Bill\n");
    printf("2. View Bill Total\n");
    printf("3. Exit\n");

    // Get user input
    int choice = get_input("Enter your choice: ");

    // Handle user's choice
    while (choice != 3) {
        switch (choice) {
            case 1: {
                // Get item details from user
                char name[20];
                printf("Enter name of item: ");
                scanf("%s", name);
                int price = get_input("Enter price of item: ");
                int quantity = get_input("Enter quantity of item: ");

                // Add item to bill
                Item item = create_item(name, price, quantity);
                add_item(&bill, item);
                printf("Item added successfully!\n\n");
                break;
            }
            case 2: {
                // Print total price of bill
                printf("Total Price: $%d\n\n", bill.total_price);
                break;
            }
            default: {
                // Invalid choice
                printf("Invalid Choice! Please select a valid option.\n\n");
                break;
            }
        }
        // Display main menu and get user input again
        printf("1. Add Item to Bill\n");
        printf("2. View Bill Total\n");
        printf("3. Exit\n");
        choice = get_input("Enter your choice: ");
    }

    // Exit program
    printf("Thank you for using Brave Cafe Billing System!\n");
    return 0;
}