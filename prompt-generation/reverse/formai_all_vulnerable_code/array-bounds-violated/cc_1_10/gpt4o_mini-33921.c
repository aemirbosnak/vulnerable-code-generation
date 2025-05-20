//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    char name[30];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int size) {
    printf("Cafe Menu:\n");
    printf("No\tItem\t\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

float calculateTotal(int orders[], MenuItem menu[], int orderCount) {
    float total = 0.0;
    for (int i = 0; i < orderCount; i++) {
        if (orders[i] >= 0 && orders[i] < MAX_ITEMS) {
            total += menu[orders[i]].price;
        }
    }
    return total;
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Latte", 2.50},
        {"Espresso", 1.75},
        {"Cappuccino", 3.00},
        {"Tea", 1.50},
        {"Croissant", 2.00},
        {"Sandwich", 4.00},
        {"Pasta", 5.50},
        {"Salad", 3.50},
        {"Cookie", 1.25},
        {"Muffin", 1.50}
    };

    int orders[MAX_ITEMS];
    int orderCount = 0;
    int choice;

    displayMenu(menu, MAX_ITEMS);

    printf("Select your items (1 to %d). Enter -1 to finish ordering:\n", MAX_ITEMS);
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == -1) {
            break;
        }
        if (choice >= 1 && choice <= MAX_ITEMS) {
            orders[orderCount++] = choice - 1;
        } else {
            printf("Invalid choice. Please select again.\n");
        }
    }
    
    printf("\nThank you for your order!\n");
    printf("Your selected items are:\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%s\n", menu[orders[i]].name);
    }
    
    float totalAmount = calculateTotal(orders, menu, orderCount);
    printf("Total Amount: %.2f\n", totalAmount);
    printf("Please pay at the counter.\n");

    return 0;
}