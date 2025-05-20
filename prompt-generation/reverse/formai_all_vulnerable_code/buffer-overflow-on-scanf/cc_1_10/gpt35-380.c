//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 1000

// Define struct for item
typedef struct item {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

// Declare global variables
Item items[MAX_ITEMS];
int total_items = 0;

// Function to add item to warehouse
void add_item(int id, char name[], int quantity, float price) {
    // Check if item already exists
    for(int i=0; i<total_items; i++) {
        if(items[i].id == id) {
            printf("Error: Item already exists with same ID\n");
            return;
        }
    }   
    // Create new item and assign values
    Item new_item;
    new_item.id = id;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    new_item.price = price;
    // Add new item to global items array
    items[total_items] = new_item;
    total_items++;
    printf("Item added successfully to warehouse\n");
}

// Function to remove item from warehouse
void remove_item(int id) {
    int found = 0;
    // Find item with given id
    for(int i=0; i<total_items; i++) {
        if(items[i].id == id) {
            // Shift elements to remove item
            for(int j=i; j<total_items-1; j++) {
                items[j] = items[j+1];
            }
            total_items--;
            found = 1;
            break;
        }
    }
    if(found) {
        printf("Item removed successfully from warehouse\n");
    }
    else {
        printf("Error: Item not found with given ID\n");
    }
}

// Function to display all items in warehouse
void display_items() {
    printf("ID\tName\t\tQuantity\tPrice\n");
    for(int i=0; i<total_items; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

// Main function
int main() {
    // Display welcome message
    printf("Welcome to warehouse management system\n");
    while(1) {
        // Display menu options
        printf("\nPlease select an option:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n");
        // Read user input
        int option;
        scanf("%d", &option);
        switch(option) {
            case 1: {
                printf("Enter ID: ");
                int id;
                scanf("%d", &id);
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter quantity: ");
                int quantity;
                scanf("%d", &quantity);
                printf("Enter price: ");
                float price;
                scanf("%f", &price);
                add_item(id, name, quantity, price);
                break;
            }
            case 2: {
                printf("Enter ID: ");
                int id;
                scanf("%d", &id);
                remove_item(id);
                break;
            }
            case 3: {
                display_items();
                break;
            }
            case 4: {
                printf("Thank you for using warehouse management system\n");
                exit(0);
            }
            default: {
                printf("Error: Invalid option\n");
            }
        }
    }
    return 0;
}