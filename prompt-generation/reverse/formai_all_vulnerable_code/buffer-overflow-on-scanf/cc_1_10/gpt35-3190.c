//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items the warehouse can hold
#define MAX_ITEMS 1000

// Define the maximum length of item description and supplier name
#define MAX_LENGTH 50

// Define a struct data type to represent an item in the warehouse
typedef struct {
    int item_code;
    char description[MAX_LENGTH];
    char supplier[MAX_LENGTH];
    int quantity;
    float price;
} Item;

// Declare an array of items to store the items in the warehouse
Item items[MAX_ITEMS];

// Declare a variable to keep track of the number of items in the warehouse
int num_items = 0;

// Function prototypes
void add_item();
void remove_item();
void view_items();
void search_items();

int main() {
    int choice;

    // Display the menu
    do {
        printf("\nWarehouse Management System Menu\n\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. View items\n");
        printf("4. Search items\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                view_items();
                break;
            case 4:
                search_items();
                break;
            case 5:
                printf("\nThank you for using the Warehouse Management System.\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

// Function to add a new item to the warehouse
void add_item() {
    // Check if the warehouse is full
    if(num_items == MAX_ITEMS) {
        printf("\nThe warehouse is full. No more items can be added.\n");
        return;
    }

    // Prompt the user to enter the details of the new item
    printf("\nEnter the details of the new item:\n");

    Item item;
    printf("Item code: ");
    scanf("%d", &item.item_code);

    printf("Description: ");
    scanf("%s", item.description);

    printf("Supplier: ");
    scanf("%s", item.supplier);

    printf("Quantity: ");
    scanf("%d", &item.quantity);

    printf("Price: ");
    scanf("%f", &item.price);

    // Add the new item to the warehouse
    items[num_items] = item;
    num_items++;

    printf("\nItem added successfully.\n");
}

// Function to remove an item from the warehouse
void remove_item() {
    // Check if the warehouse is empty
    if(num_items == 0) {
        printf("\nThe warehouse is empty. No items can be removed.\n");
        return;
    }

    // Prompt the user to enter the item code of the item to be removed
    int item_code;
    printf("\nEnter the item code of the item to be removed: ");
    scanf("%d", &item_code);

    // Search for the item in the warehouse
    int found = 0;
    int i;
    for(i = 0; i < num_items; i++) {
        if(items[i].item_code == item_code) {
            found = 1;
            break;
        }
    }

    // Remove the item from the warehouse
    if(found) {
        for(i = i + 1; i < num_items; i++) {
            items[i - 1] = items[i];
        }
        num_items--;
        printf("\nItem removed successfully.\n");
    }
    else {
        printf("\nItem not found in the warehouse.\n");
    }
}

// Function to view all items in the warehouse
void view_items() {
    // Check if the warehouse is empty
    if(num_items == 0) {
        printf("\nThe warehouse is empty. No items to view.\n");
        return;
    }

    // Display all the items in the warehouse
    printf("\nItems in the warehouse:\n\n");
    printf("Item Code\tDescription\t\tSupplier\tQuantity\tPrice\n");

    int i;
    for(i = 0; i < num_items; i++) {
        printf("%d\t\t%-20s%-15s\t%d\t\t%.2f\n", items[i].item_code, items[i].description, items[i].supplier, items[i].quantity, items[i].price);
    }
}

// Function to search for an item in the warehouse
void search_items() {
    // Check if the warehouse is empty
    if(num_items == 0) {
        printf("\nThe warehouse is empty. No items to search.\n");
        return;
    }

    // Prompt the user to enter the item code or description to search for
    int choice;
    printf("\nSearch items by:\n\n");
    printf("1. Item code\n");
    printf("2. Description\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        int item_code;
        printf("\nEnter the item code to search for: ");
        scanf("%d", &item_code);

        // Search for the item in the warehouse
        int found = 0;
        int i;
        for(i = 0; i < num_items; i++) {
            if(items[i].item_code == item_code) {
                found = 1;
                break;
            }
        }

        // Display the item details
        if(found) {
            printf("\nItem found:\n\n");
            printf("Item Code\tDescription\t\tSupplier\tQuantity\tPrice\n");
            printf("%d\t\t%-20s%-15s\t%d\t\t%.2f\n", items[i].item_code, items[i].description, items[i].supplier, items[i].quantity, items[i].price);
        }
        else {
            printf("\nItem not found in the warehouse.\n");
        }
    }
    else if(choice == 2) {
        char description[MAX_LENGTH];
        printf("\nEnter the description to search for: ");
        scanf("%s", description);

        // Search for the item in the warehouse
        int found = 0;
        int i;
        for(i = 0; i < num_items; i++) {
            if(strcmp(items[i].description, description) == 0) {
                found = 1;
                break;
            }
        }

        // Display the item details
        if(found) {
            printf("\nItem found:\n\n");
            printf("Item Code\tDescription\t\tSupplier\tQuantity\tPrice\n");
            printf("%d\t\t%-20s%-15s\t%d\t\t%.2f\n", items[i].item_code, items[i].description, items[i].supplier, items[i].quantity, items[i].price);
        }
        else {
            printf("\nItem not found in the warehouse.\n");
        }
    }
    else {
        printf("\nInvalid choice. Please try again.\n");
    }
}