//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    float price;
    int quantity;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("0. Checkout\n\n");
}

float calculateTotal(MenuItem menu[], int itemCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += menu[i].price * menu[i].quantity;
    }
    return total;
}

void printBill(MenuItem menu[], int itemCount) {
    printf("\n--- Bill Summary ---\n");
    for (int i = 0; i < itemCount; i++) {
        if (menu[i].quantity > 0) {
            printf("%s x %d - $%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    printf("---------------------\n");
    float total = calculateTotal(menu, itemCount);
    printf("Total: $%.2f\n", total);
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50, 0},
        {"Tea", 1.50, 0},
        {"Sandwich", 5.00, 0},
        {"Pastry", 3.00, 0},
        {"Burger", 8.00, 0},
        {"Pizza", 10.00, 0}
    };
    int itemCount = 6;
    int choice;

    do {
        displayMenu(menu, itemCount);
        printf("Select an item (1-%d): ", itemCount);
        scanf("%d", &choice);

        if (choice > 0 && choice <= itemCount) {
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &menu[choice - 1].quantity);
        } else if (choice != 0) {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
    
    printBill(menu, itemCount);

    return 0;
}