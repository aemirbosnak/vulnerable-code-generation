//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 30

struct MenuItem {
    char name[MAX_NAME_LENGTH];
    float price;
};

void printBill(struct MenuItem items[], int quantities[], int count) {
    float total = 0.0;
    printf("\n----- Bill -----\n");
    for (int i = 0; i < count; ++i) {
        if (quantities[i] > 0) {
            float cost = quantities[i] * items[i].price;
            total += cost;
            printf("%s (x%d): $%.2f\n", items[i].name, quantities[i], cost);
        }
    }
    printf("-----------------\n");
    printf("Total Amount: $%.2f\n", total);
}

void displayMenu(struct MenuItem items[], int count) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < count; ++i) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

int main() {
    struct MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Sandwich", 5.50},
        {"Burger", 6.25},
        {"Pasta", 7.00},
        {"Salad", 4.00},
        {"Soda", 1.50},
        {"Juice", 2.00},
        {"Cake", 3.00},
        {"Ice Cream", 2.50}
    };
    
    int quantities[MAX_ITEMS] = {0};
    int choice, count = 10;

    while (1) {
        displayMenu(menu, count);
        printf("\nEnter the number of the item to order (0 to finish): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > count) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter the quantity of %s: ", menu[choice - 1].name);
        int quantity;
        scanf("%d", &quantity);
        if (quantity < 0) {
            printf("Quantity cannot be negative.\n");
        } else {
            quantities[choice - 1] += quantity;
            printf("Added %d of %s to your order.\n", quantity, menu[choice - 1].name);
        }
    }

    printBill(menu, quantities, count);
    printf("Thank you for visiting our cafe!\n");
    return 0;
}