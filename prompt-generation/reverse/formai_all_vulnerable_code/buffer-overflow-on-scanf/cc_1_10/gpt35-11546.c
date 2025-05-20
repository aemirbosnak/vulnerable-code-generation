//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ITEMS 20
#define ITEM_NAME_LENGTH 20

// Define struct for items
typedef struct Item {
    char name[ITEM_NAME_LENGTH];
    double price;
    int quantity;
} Item;

// Function prototypes
void printMenu(Item* menu, int numItems);
Item* initializeMenu(int numItems);
int getIndexByName(char* name, Item* menu, int numItems);
void getOrder(Item* menu, int numItems, int* order);

int main() {
    // Declare variables
    Item* menu;
    int numItems, choice;
    int order[MAX_ITEMS] = {0};
    double subtotal = 0, tax = 0, total = 0;
    const double TAX_RATE = 0.1;

    // Get number of items in menu
    printf("How many items are in the menu? ");
    scanf("%d", &numItems);

    // Initialize menu
    menu = initializeMenu(numItems);

    // Loop through menu until customer is done ordering
    do {
        printf("\n\n");
        // Print menu
        printMenu(menu, numItems);

        // Get customer's choice
        printf("\nEnter the number of the item you would like to order (0 to exit): ");
        scanf("%d", &choice);

        // Check if choice is valid
        if (choice < 0 || choice > numItems) {
            printf("\nInvalid choice! Please try again.");
        } else if (choice == 0) {
            break;
        } else {
            // Add item to order
            getOrder(menu, numItems, order);
            order[choice-1]++;
            printf("\n%s added to order!\n", menu[choice-1].name);
        }
    } while (1);

    // Print final order
    printf("\n\nYour Order:\n");
    for (int i = 0; i < numItems; i++) {
        if (order[i] > 0) {
            printf("%s x%d: $%.2f\n", menu[i].name, order[i], menu[i].price * order[i]);
            subtotal += menu[i].price * order[i];
        }
    }

    // Calculate tax and total
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", total);

    // Free memory
    free(menu);

    return 0;
}

// Initializes the menu with item names and prices
Item* initializeMenu(int numItems) {
    Item* menu = malloc(numItems * sizeof(Item));
    for (int i = 0; i < numItems; i++) {
        printf("\nEnter the name of item %d: ", i+1);
        scanf("%19s", menu[i].name);
        printf("Enter the price of item %d: $", i+1);
        scanf("%lf", &menu[i].price);
        menu[i].quantity = 0;
    }
    return menu;
}

// Prints the menu
void printMenu(Item* menu, int numItems) {
    printf("%-4s%-20s%s\n", "", "Name", "Price");
    for (int i = 0; i < numItems; i++) {
        printf("%-4d%-20s$%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Gets the index of an item in the menu by its name
int getIndexByName(char* name, Item* menu, int numItems) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(name, menu[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Gets the customer's order by name
void getOrder(Item* menu, int numItems, int* order) {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    printf("\nEnter the name of the item you would like to order: ");
    scanf("%19s", name);
    printf("How many would you like to order? ");
    scanf("%d", &quantity);
    int index = getIndexByName(name, menu, numItems);
    if (index == -1) {
        printf("\n%s not found on menu! Please try again.", name);
    } else {
        order[index] += quantity;
        printf("\n%d %s added to order!\n", quantity, name);
    }
}