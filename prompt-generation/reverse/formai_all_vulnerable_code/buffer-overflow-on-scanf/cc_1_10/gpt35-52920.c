//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a structure to hold menu items
typedef struct {
    char name[100];
    double price;
} MenuItem;

int main() {
    int numItems; // Number of items in the menu
    MenuItem *menu; // Array to hold menu items
    double total = 0.0; // Total cost of the items
    char itemName[100]; // Name of the item ordered
    int itemQuantity; // Quantity of the item ordered
    char response; // Response of the user to order another item

    // Ask user for the number of items in the menu
    printf("How many items are on the menu?\n");
    scanf("%d", &numItems);

    // Allocate memory for the menu array
    menu = (MenuItem*) malloc(numItems * sizeof(MenuItem));

    // Ask user to enter the details of each menu item
    printf("Enter the name and price of each item on the menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d: ", i + 1);
        scanf("%s %lf", menu[i].name, &menu[i].price);
    }

    // Display the menu to the user
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: $%.2lf\n", menu[i].name, menu[i].price);
    }

    // Prompt user to order an item
    do {
        // Ask user for the name and quantity of the item ordered
        printf("Enter the name and quantity of the item you would like to order:\n");
        scanf("%s %d", itemName, &itemQuantity);

        // Search for the item in the menu
        for (int i = 0; i < numItems; i++) {
            if (strcmp(itemName, menu[i].name) == 0) {
                // Add the cost of the item to the total
                total += menu[i].price * itemQuantity;
                printf("%d %s added to the order. Total cost: $%.2lf\n", itemQuantity, itemName, total);
                break;
            }
            else if (i == numItems - 1) {
                // Item not found in the menu
                printf("%s is not on the menu. Please try again.\n", itemName);
            }
        }

        // Ask user if they want to order another item
        printf("Do you want to order another item? (Y/N)\n");
        scanf(" %c", &response);
    } while (response == 'Y' || response == 'y');

    // Print the final cost of the order
    printf("Your total bill is: $%.2lf\n", total);

    // Free the memory allocated to the menu array
    free(menu);

    return 0;
}