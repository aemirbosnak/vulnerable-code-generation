//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} item;

void display_menu() {
    printf("======================================\n");
    printf("Welcome to C Cafe!\n");
    printf("======================================\n");
    printf("         MENU\n");
    printf("======================================\n");
    printf("ITEM\t\tQUANTITY\tPRICE\n");
    printf("--------------------------------------\n");
    printf("Coffee\t\t100\t\t$2.50\n");
    printf("Tea\t\t150\t\t$1.50\n");
    printf("Burger\t\t50\t\t$5.00\n");
    printf("Sandwich\t100\t\t$3.00\n");
    printf("======================================\n");
}

int main() {
    item menu[4] = {
        {"Coffee", 100, 2.50},
        {"Tea", 150, 1.50},
        {"Burger", 50, 5.00},
        {"Sandwich", 100, 3.00}
    };

    int choice, quantity;
    float total_price = 0.0;

    display_menu();

    do {
        printf("\nEnter your choice (1-4) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Total amount due: $%.2f\n", total_price);
            printf("Thank you for visiting C Cafe!\n");
            return 0;
        }

        printf("\nEnter quantity: ");
        scanf("%d", &quantity);

        if (quantity > menu[choice-1].quantity) {
            printf("Insufficient quantity\n");
            continue;
        }

        total_price += menu[choice-1].price * quantity;
        menu[choice-1].quantity -= quantity;
        printf("The total for your order is $%.2f\n", menu[choice-1].price * quantity);

    } while (choice != 0);

    return 0;
}