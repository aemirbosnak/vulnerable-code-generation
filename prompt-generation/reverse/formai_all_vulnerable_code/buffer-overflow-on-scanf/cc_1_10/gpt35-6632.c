//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to hold item information
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Global variables
int num_items;
Item items[MAX_ITEMS];

// Function prototypes
void print_menu();
void add_item();
void remove_item();
void display_inventory();
void calculate_value();

// Main function
int main() {
    char option;

    // Initialize inventory
    num_items = 0;

    // Display menu and get user input
    print_menu();
    printf("Enter option (Q to quit): ");
    scanf(" %c", &option);

    // Loop until user quits
    while (option != 'Q' && option != 'q') {
        switch (option) {
            case 'A':
            case 'a':
                add_item();
                break;
            case 'R':
            case 'r':
                remove_item();
                break;
            case 'D':
            case 'd':
                display_inventory();
                break;
            case 'V':
            case 'v':
                calculate_value();
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        // Display menu and get user input
        print_menu();
        printf("Enter option (Q to quit): ");
        scanf(" %c", &option);
    }

    printf("Goodbye!\n");

    return 0;
}

// Function to display menu
void print_menu() {
    printf("Warehouse Management System\n");
    printf("----------------------------------\n");
    printf("A) Add item\n");
    printf("R) Remove item\n");
    printf("D) Display inventory\n");
    printf("V) Calculate total inventory value\n");
    printf("----------------------------------\n");
}

// Function to add item to inventory
void add_item() {
    Item item;

    // Get item information from user
    printf("Enter item name: ");
    scanf("%s", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%f", &item.price);

    // Add item to inventory
    if (num_items < MAX_ITEMS) {
        items[num_items++] = item;
        printf("Item added to inventory.\n");
    } else {
        printf("Inventory is full. Item not added.\n");
    }
}

// Function to remove item from inventory
void remove_item() {
    char name[50];
    int i, found = 0;

    // Get item name from user
    printf("Enter name of item to remove: ");
    scanf("%s", name);

    // Search for item in inventory
    for (i = 0; i < num_items; i++) {
        if (strcmp(name, items[i].name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        // Remove item from inventory
        for (; i < num_items - 1; i++) {
            items[i] = items[i + 1];
        }
        num_items--;
        printf("Item removed from inventory.\n");
    } else {
        printf("Item not found in inventory.\n");
    }
}

// Function to display inventory
void display_inventory() {
    int i;

    printf("Inventory\n");
    printf("----------------------------------\n");
    for (i = 0; i < num_items; i++) {
        printf("Item name: %s\n", items[i].name);
        printf("Item quantity: %d\n", items[i].quantity);
        printf("Item price: $%.2f\n", items[i].price);
        printf("----------------------------------\n");
    }
}

// Function to calculate total inventory value
void calculate_value() {
    int i;
    float total_value = 0.0;

    for (i = 0; i < num_items; i++) {
        total_value += items[i].quantity * items[i].price;
    }

    printf("Total inventory value: $%.2f\n", total_value);
}