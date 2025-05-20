//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("------------------\n");
}

float calculateTotal(MenuItem menu[], int itemCount) {
    float total = 0;
    for (int i = 0; i < itemCount; i++) {
        total += menu[i].price * menu[i].quantity;
    }
    return total;
}

void printBill(MenuItem menu[], int itemCount) {
    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < itemCount; i++) {
        if (menu[i].quantity > 0) {
            printf("%s (x%d) - $%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    float total = calculateTotal(menu, itemCount);
    printf("------------------\nTotal: $%.2f\n", total);
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50, 0},
        {"Tea", 1.80, 0},
        {"Sandwich", 3.00, 0},
        {"Cake", 2.20, 0},
        {"Juice", 1.50, 0}
    };

    int choice, itemCount = MAX_ITEMS;
    char continueOrder;

    do {
        displayMenu(menu, itemCount);
        printf("Please select an item (1-%d or 0 to finish): ", itemCount);
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > itemCount) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("How many of %s would you like to order? ", menu[choice - 1].name);
        scanf("%d", &menu[choice - 1].quantity);
        
        printf("Would you like to order another item? (y/n): ");
        scanf(" %c", &continueOrder);

    } while (continueOrder == 'y' || continueOrder == 'Y');

    printBill(menu, itemCount);

    printf("Thank you for dining with us!\n");
    return 0;
}