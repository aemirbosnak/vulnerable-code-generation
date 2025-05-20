//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for menu items
struct menuItem {
    char name[100];
    float price;
};

// Function to print menu
void printMenu(struct menuItem menu[], int size) {
    printf("Cafe Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take order
void takeOrder(struct menuItem menu[], int size, float total) {
    int choice;
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > size) {
            printf("Invalid choice. Please try again.\n");
        } else {
            printf("\nYou have chosen %s - $%.2f\n", menu[choice-1].name, menu[choice-1].price);
            total += menu[choice-1].price;
            printf("\nTotal bill: $%.2f\n", total);
            break;
        }
    }
}

// Function to calculate discount
float calculateDiscount(float total) {
    if (total >= 50.0) {
        return 0.2 * total;
    } else {
        return 0;
    }
}

// Function to print receipt
void printReceipt(float total, float discount) {
    printf("\nReceipt:\n");
    printf("\tTotal bill: $%.2f\n", total);
    if (discount > 0) {
        printf("\tDiscount: $%.2f\n", discount);
    }
    printf("\tAmount payable: $%.2f\n", total - discount);
}

int main() {
    // Menu items
    struct menuItem menu[] = {
        {"Coffee", 4.50},
        {"Cappuccino", 5.50},
        {"Latte", 6.00},
        {"Tea", 3.50},
        {"Croissant", 3.00},
        {"Muffin", 2.50},
        {"Sandwich", 7.00},
        {"Pizza", 10.00}
    };
    int size = sizeof(menu) / sizeof(menu[0]);

    // Initializing total bill
    float total = 0.0;

    // Printing menu
    printMenu(menu, size);

    // Taking order
    takeOrder(menu, size, total);

    // Calculating discount
    float discount = calculateDiscount(total);

    // Printing receipt
    printReceipt(total, discount);

    return 0;
}