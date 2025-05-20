//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char item[50];
    int price;
} Menu_Item;

int main() {
    int num_items, total = 0, option;
    printf("Welcome to the Cafe Billing System!\n\n");

    // Create the menu
    Menu_Item menu[] = {
        {"Coffee", 2},
        {"Tea", 1},
        {"Croissant", 3},
        {"Muffin", 2},
        {"Sandwich", 5}
    };

    // Determine the number of items in the menu
    num_items = sizeof(menu) / sizeof(menu[0]);

    // Display the menu to the user
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%d\n", i+1, menu[i].item, menu[i].price);
    }
    printf("\n");

    // Allow the user to select menu items
    while (1) {
        printf("Select an option (or enter 0 to exit): ");
        scanf("%d", &option);

        // Exit if 0 is selected
        if (option == 0) {
            break;
        }

        // Add the price of the selected item to the total
        total += menu[option - 1].price;
        printf("Added %s to the bill. Total: $%d\n\n", menu[option - 1].item, total);
    }

    // Display the final bill to the user
    printf("Final total: $%d\n", total);

    return 0;
}