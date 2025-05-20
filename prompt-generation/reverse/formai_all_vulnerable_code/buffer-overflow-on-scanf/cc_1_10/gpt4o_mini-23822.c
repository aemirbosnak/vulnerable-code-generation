//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50

typedef struct {
    char name[30];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int count) {
    printf("\n======== Welcome to the Cafe ========\n");
    printf("No\tItem\t\tPrice\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("=====================================\n");
}

float calculateTotal(int orderedItems[], int quantities[], MenuItem menu[], int count) {
    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        total += orderedItems[i] * quantities[i] * menu[i].price;
    }
    return total;
}

void takeOrder(MenuItem menu[], int count) {
    int orderedItems[MAX_ITEMS] = {0};
    int quantities[MAX_ITEMS] = {0};
    int choice = 0;

    while (1) {
        displayMenu(menu, count);
        printf("Please enter the item number to order (0 to finish): ");
        scanf("%d", &choice);

        if (choice == 0) break; // End ordering
        
        if (choice < 1 || choice > count) {
            printf("Invalid choice. Please select again!\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantities[choice - 1]);
        orderedItems[choice - 1] = 1; // Set that this item was ordered
        printf("%d x %s added to your order!\n", quantities[choice - 1], menu[choice - 1].name);
    }

    float total = calculateTotal(orderedItems, quantities, menu, count);
    printf("\nYour total bill is: %.2f\n", total);
}

int main() {
    MenuItem menu[] = {
        {"Espresso", 2.50},
        {"Latte", 3.00},
        {"Cappuccino", 3.50},
        {"Black Coffee", 2.00},
        {"Frappuccino", 4.00},
        {"Iced Tea", 2.75},
        {"Croissant", 1.50},
        {"Muffin", 2.00},
        {"Sandwich", 5.00},
        {"Cheesecake", 4.50}
    };

    int itemCount = sizeof(menu) / sizeof(menu[0]);

    printf("Welcome to the C Cafe Billing System!\n");
    printf("Let's take your order!\n");

    takeOrder(menu, itemCount);

    printf("Thank you for visiting C Cafe! Have a great day!\n");
    return 0;
}