//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int itemCount = 0;

void addItem(int id, const char* name, float price) {
    menu[itemCount].id = id;
    snprintf(menu[itemCount].name, sizeof(menu[itemCount].name), "%s", name);
    menu[itemCount].price = price;
    itemCount++;
}

void displayMenu() {
    printf("\n----- Welcome to Our Café! -----\n");
    printf("ID\tItem\t\tPrice\n");
    printf("===============================\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("===============================\n");
}

void generateBill(float total) {
    printf("\n----- Your Bill -----\n");
    printf("Total Amount: %.2f\n", total);
    printf("Thank you for visiting our café!\n");
    printf("----------------------\n");
}

int main() {
    int choice;
    float total = 0;

    // Adding items to the menu
    addItem(1, "Espresso", 2.50);
    addItem(2, "Latte", 3.00);
    addItem(3, "Cappuccino", 3.25);
    addItem(4, "Americano", 2.75);
    addItem(5, "Cookies", 1.50);
    addItem(6, "Sandwich", 4.00);

    while (1) {
        displayMenu();

        printf("Select item ID to order (or enter 0 to finish): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > itemCount) {
            printf("Invalid selection! Please choose a valid item ID.\n");
        } else {
            int quantity;
            printf("How many would you like to order? ");
            scanf("%d", &quantity);
            float itemTotal = menu[choice - 1].price * quantity;
            total += itemTotal;
            printf("Added %d x %s to your order. Total: %.2f\n", quantity, menu[choice - 1].name, itemTotal);
        }
    }

    generateBill(total);

    return 0;
}