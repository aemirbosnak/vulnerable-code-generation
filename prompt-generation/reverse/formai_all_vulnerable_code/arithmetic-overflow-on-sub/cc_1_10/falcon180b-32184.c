//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to represent a menu item
struct menu_item {
    char name[50];
    float price;
};

// Function to print the menu
void print_menu(struct menu_item menu[], int num_items) {
    printf("Welcome to our cafe!\n");
    printf("Here's what we have on the menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take the customer's order
void take_order(struct menu_item menu[], int num_items) {
    int choice;
    float total = 0;
    char order[50];

    printf("What would you like to order?\n");
    scanf("%d", &choice);

    strcpy(order, menu[choice-1].name);
    printf("You ordered a %s - that will be $%.2f.\n", order, menu[choice-1].price);
    total += menu[choice-1].price;

    printf("Would you like anything else? (y/n)\n");
    char response[3];
    scanf("%s", response);

    while (strcmp(response, "n")!= 0) {
        printf("What else would you like to order?\n");
        scanf("%d", &choice);

        strcpy(order, menu[choice-1].name);
        printf("You ordered a %s - that will be $%.2f.\n", order, menu[choice-1].price);
        total += menu[choice-1].price;

        printf("Would you like anything else? (y/n)\n");
        scanf("%s", response);
    }

    printf("Your total comes to $%.2f. Thank you for your order!\n", total);
}

int main() {
    // Initialize the menu
    struct menu_item menu[] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Muffin", 3.00},
        {"Cookie", 2.00},
        {"Sandwich", 5.50}
    };
    int num_items = sizeof(menu) / sizeof(menu[0]);

    // Print the menu
    print_menu(menu, num_items);

    // Take the customer's order
    take_order(menu, num_items);

    return 0;
}