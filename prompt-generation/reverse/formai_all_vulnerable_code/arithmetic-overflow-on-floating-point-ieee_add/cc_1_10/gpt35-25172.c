//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Item {
   char name[50];
   float price;
   int quantity;
} Item;

int main() {
    Item menu[MAX_SIZE]; // For storing menu items
    int size = 0; // For keeping track of the size of the menu array
    float total = 0; // For keeping track of the total bill amount
    char choice; // For storing user's choice
    int i; // For iteration

    // Add items to the menu
    strcpy(menu[0].name, "Latte");
    menu[0].price = 3.50;
    menu[0].quantity = 5;

    strcpy(menu[1].name, "Espresso");
    menu[1].price = 2.50;
    menu[1].quantity = 7;

    strcpy(menu[2].name, "Cappuccino");
    menu[2].price = 4.00;
    menu[2].quantity = 3;

    size = 3;

    printf("Welcome to the Cafe Billing System!\n\n");

    do {
        // Display the menu
        printf("Menu:\n");
        for(i = 0; i < size; i++) {
            printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
        }

        // Ask for user's choice
        printf("Enter your choice (1-%d) or 0 to exit: ", size);
        scanf("%d", &choice);

        if(choice > 0 && choice <= size) {
            Item selected = menu[choice-1];

            // Ask for quantity
            printf("Enter quantity: ");
            scanf("%d", &selected.quantity);

            // Calculate cost and add to total
            float cost = selected.price * selected.quantity;
            total += cost;

            // Update quantity in menu
            menu[choice-1].quantity -= selected.quantity;

            printf("%d %s added to your bill.\n\n", selected.quantity, selected.name);
        }
        else if(choice != 0) {
            printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice != 0);

    printf("Total bill: $%.2f\n", total);

    return 0;
}