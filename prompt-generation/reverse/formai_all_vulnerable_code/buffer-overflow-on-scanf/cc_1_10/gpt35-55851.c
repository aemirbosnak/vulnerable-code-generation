//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing item details
struct Item {
    char name[50];
    int quantity;
    float price;
};

// Function to capture item details from user and store in Item struct
void capture_item_details(struct Item* item) {
    printf("\nEnter item name: ");
    scanf("%s", item->name);
    printf("Enter quantity: ");
    scanf("%d", &item->quantity);
    printf("Enter price: ");
    scanf("%f", &item->price);
}

// Function to calculate total bill amount
float calculate_bill(struct Item* items, int item_count) {
    float total = 0;
    for(int i=0; i<item_count; i++) {
        total += items[i].quantity * items[i].price;
    }
    return total;
}

// Function to display menu and capture user choice
int get_menu_choice() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Add item\n");
    printf("2. Print bill and exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

// Recursive function to add items to the bill and display menu until user chooses to print bill
void add_items_and_display_menu(struct Item* items, int* item_count) {
    int choice = get_menu_choice();
    if(choice == 1) {
        // Capture new item and add to the list
        struct Item item;
        capture_item_details(&item);
        items[*item_count] = item;
        (*item_count)++;
        add_items_and_display_menu(items, item_count);
    } else if(choice == 2) {
        // Print the bill
        printf("\nBill:\n");
        printf("Item\t\tQuantity\tPrice\n");
        for(int i=0; i<*item_count; i++) {
            printf("%s\t\t%d\t\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
        printf("Total:\t\t\t\t%.2f\n", calculate_bill(items, *item_count));
        return;
    } else {
        printf("\nInvalid choice. Please try again.\n");
        add_items_and_display_menu(items, item_count);
    }
}

int main() {
    struct Item items[50];
    int item_count = 0;

    add_items_and_display_menu(items, &item_count);

    return 0;
}