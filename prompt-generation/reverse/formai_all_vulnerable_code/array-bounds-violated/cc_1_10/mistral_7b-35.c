//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Menu structure definition
typedef struct {
    char name[30];
    float price;
} MenuItem;

// Menu item array initialization
MenuItem menu[] = {
    {"Cappuccino", 3.5},
    {"Latte", 4.0},
    {"Mocha", 3.8},
    {"Espresso", 2.5},
    {"Americano", 3.0},
    {"Macchiato", 2.8},
    {"Caf Au Lait", 3.2},
    {"Hot Chocolate", 3.5},
    {"Tea", 2.0},
    {"Cookies", 1.5}
};

int main() {
    int choice, qty;
    float bill, total_bill = 0.0;

    printf("\n-----------------------------------\n");
    printf("| Welcome to Cheerful Cafe! |\n");
    printf("-----------------------------------\n\n");

    // Display menu to user
    printf("| Menu |\n");
    printf("-----------------------------\n");
    for (int i = 0; i < 11; i++) {
        printf("| %-15s | %.2f |\n", menu[i].name, menu[i].price);
    }

    // Take user order and calculate bill
    do {
        printf("\n| Your turn to order! |\n");
        printf("-----------------------------\n");
        printf("| %-15s | Price |\n", "Item Name");
        printf("-----------------------------\n");
        for (int i = 0; i < 11; i++) {
            printf("| %-15s | %.2f |\n", menu[i].name, menu[i].price);
        }
        printf("| %-15s |   --  |\n", "Qty");
        printf("-----------------------------\n");

        scanf("%d", &choice);
        printf("How many %s would you like? ", menu[choice - 1].name);
        scanf("%d", &qty);

        bill = menu[choice - 1].price * qty;
        printf("\nYour order of %d %s(s) will cost you: $%.2f", qty, menu[choice - 1].name, bill);
        printf("\nYour total bill is now: $%.2f\n", total_bill += bill);

    } while (choice != 0); // Exit loop when user chooses '0'

    printf("\n-----------------------------------\n");
    printf("| Thank you for visiting Cheerful Cafe! |\n");
    printf("-----------------------------------\n");

    return 0;
}