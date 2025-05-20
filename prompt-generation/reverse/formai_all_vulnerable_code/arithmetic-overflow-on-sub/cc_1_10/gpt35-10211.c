//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Menu_Item;

int main() {
    int order_number = 0, menu_size = 6, input_id, input_quantity;
    float bill = 0;
    char input_choice;

    // Menu items
    Menu_Item menu[] = {
        {1, "Espresso", 3.5, 20},
        {2, "Cappuccino", 4.0, 15},
        {3, "Latte", 4.5, 10},
        {4, "Muffin", 2.5, 30},
        {5, "Croissant", 3.0, 25},
        {6, "Bagel", 2.0, 20}
    };

    // Main loop
    while (1) {
        // Display menu
        printf("Welcome to the C Cafe!\n");
        printf("---------------------\n");
        printf("ID  | Name         | Price  | Quantity\n");
        printf("---------------------------------------\n");
        for (int i = 0; i < menu_size; i++) {
            printf("%-3d | %-11s | $%-5.2f | %-8d\n", menu[i].id, menu[i].name, menu[i].price, menu[i].quantity);
        }

        // Take order
        printf("\nWhat would you like to order? (Enter ID)\n");
        scanf("%d", &input_id);
        printf("How many would you like?\n");
        scanf("%d", &input_quantity);

        // Check if item is in stock
        Menu_Item chosen_item;
        for (int i = 0; i < menu_size; i++) {
            if (menu[i].id == input_id) {
                chosen_item = menu[i];
                if (chosen_item.quantity < input_quantity) {
                    printf("Sorry, we don't have enough %s. Please try again.\n", chosen_item.name);
                    break;
                }
                else {
                    chosen_item.quantity -= input_quantity;
                    bill += chosen_item.price * input_quantity;
                    order_number++;
                    printf("Your order of %d %s has been placed. Your order number is %d.\n", input_quantity, chosen_item.name, order_number);
                    break;
                }
            }
            if (i == menu_size - 1) {
                printf("Sorry, that item doesn't exist. Please try again.\n");
            }
        }

        // Check if customer wants to order more
        printf("\nWould you like to order anything else? (Y/N)\n");
        scanf(" %c", &input_choice);
        if (input_choice == 'N' || input_choice == 'n') {
            break;
        }
    }

    // Display bill
    printf("\nYour total bill is: $%.2f\n", bill);
    printf("Thank you for visiting the C Cafe!\n");

    return 0;
}