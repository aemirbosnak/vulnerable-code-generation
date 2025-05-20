//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    int id;
    char name[30];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int order[MAX_ITEMS] = {0}; // to store how many of each item ordered
int itemCount = 0;

void initializeMenu() {
    menu[0] = (MenuItem){1, "Coffee", 2.50};
    menu[1] = (MenuItem){2, "Espresso", 3.00};
    menu[2] = (MenuItem){3, "Latte", 3.50};
    menu[3] = (MenuItem){4, "Cappuccino", 4.00};
    menu[4] = (MenuItem){5, "Tea", 2.00};
    menu[5] = (MenuItem){6, "Sandwich", 5.00};
    menu[6] = (MenuItem){7, "Cake", 4.50};
    menu[7] = (MenuItem){8, "Cookies", 1.50};
    menu[8] = (MenuItem){9, "Muffin", 2.00};
    menu[9] = (MenuItem){10, "Brownie", 3.00};
    itemCount = 10;
}

void displayMenu() {
    printf("Available Menu Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("\n");
}

void takeOrder() {
    int choice, quantity;
    printf("Enter the item number to order (0 to finish): ");
    while (1) {
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        if (choice < 1 || choice > itemCount) {
            printf("Invalid choice! Please try again: ");
            continue;
        }
        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantity);
        order[choice - 1] += quantity;
        printf("Added %d x %s to your order.\n", quantity, menu[choice - 1].name);
        printf("Enter the item number to order (0 to finish): ");
    }
}

float calculateTotal() {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        if (order[i] > 0) {
            total += order[i] * menu[i].price;
        }
    }
    return total;
}

void printReceipt() {
    printf("\nReceipt:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        if (order[i] > 0) {
            printf("%d x %s - $%.2f\n", order[i], menu[i].name, order[i] * menu[i].price);
        }
    }
    printf("---------------------------------------------------\n");
    printf("Total: $%.2f\n", calculateTotal());
    printf("Thank you for your order!\n");
}

int main() {
    initializeMenu();
    displayMenu();
    takeOrder();
    printReceipt();
    return 0;
}