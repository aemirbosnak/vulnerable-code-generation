//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
// Medical Store Management System
// Alan Turing Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Define the array of items
Item items[MAX_ITEMS];

// Define the number of items in the store
int num_items = 0;

// Define the menu options
enum MenuOption {
    ADD_ITEM,
    REMOVE_ITEM,
    SEARCH_ITEM,
    DISPLAY_ITEMS,
    QUIT
};

// Define the function to add an item to the store
void add_item() {
    // Get the item's name
    printf("Enter the item's name: ");
    scanf("%s", items[num_items].name);

    // Get the item's quantity
    printf("Enter the item's quantity: ");
    scanf("%d", &items[num_items].quantity);

    // Get the item's price
    printf("Enter the item's price: ");
    scanf("%f", &items[num_items].price);

    // Increment the number of items in the store
    num_items++;
}

// Define the function to remove an item from the store
void remove_item() {
    // Get the item's name
    char name[50];
    printf("Enter the item's name: ");
    scanf("%s", name);

    // Find the item in the array
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            break;
        }
    }

    // If the item was found, remove it from the array
    if (i < num_items) {
        for (int j = i; j < num_items - 1; j++) {
            items[j] = items[j + 1];
        }
        num_items--;
    } else {
        printf("Item not found.\n");
    }
}

// Define the function to search for an item in the store
void search_item() {
    // Get the item's name
    char name[50];
    printf("Enter the item's name: ");
    scanf("%s", name);

    // Find the item in the array
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            break;
        }
    }

    // If the item was found, display its information
    if (i < num_items) {
        printf("Item found:\n");
        printf("Name: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: %f\n", items[i].price);
    } else {
        printf("Item not found.\n");
    }
}

// Define the function to display the items in the store
void display_items() {
    // Display the items in the array
    for (int i = 0; i < num_items; i++) {
        printf("Item %d:\n", i + 1);
        printf("Name: %s\n", items[i].name);
        printf("Quantity: %d\n", items[i].quantity);
        printf("Price: %f\n", items[i].price);
    }
}

// Define the function to quit the program
void quit() {
    // Exit the program
    exit(0);
}

// Define the main function
int main() {
    // Display the menu
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Search Item\n");
        printf("4. Display Items\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case ADD_ITEM:
                add_item();
                break;
            case REMOVE_ITEM:
                remove_item();
                break;
            case SEARCH_ITEM:
                search_item();
                break;
            case DISPLAY_ITEMS:
                display_items();
                break;
            case QUIT:
                quit();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}