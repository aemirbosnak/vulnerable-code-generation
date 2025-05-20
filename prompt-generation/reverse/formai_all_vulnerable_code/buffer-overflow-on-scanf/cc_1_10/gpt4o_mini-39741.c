//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

// Structure to hold menu item details
struct MenuItem {
    char name[30];
    float price;
};

// Function prototypes
void displayMenu(struct MenuItem menu[], int item_count);
float calculateTotal(int quantities[], struct MenuItem menu[], int item_count);
void generateBill(int quantities[], struct MenuItem menu[], int item_count);

int main() {
    struct MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.5},
        {"Tea", 1.5},
        {"Sandwich", 4.0},
        {"Burger", 5.0},
        {"Pizza", 8.0},
        {"Pasta", 7.0},
        {"Juice", 3.0},
        {"Cake", 2.0},
        {"Ice Cream", 2.5},
        {"Salad", 3.5}
    };

    int quantities[MAX_ITEMS] = {0}; // Array to hold the quantity of each item
    int choice, item_count = MAX_ITEMS;

    printf("Welcome to Our Cafe Billing System!\n");
    
    do {
        displayMenu(menu, item_count);
        printf("Enter the number of the item to order (0 to finish): ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= item_count) {
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &quantities[choice - 1]);
        } else if (choice != 0) {
            printf("Invalid choice, please try again.\n");
        }

    } while (choice != 0);

    // Generate bill
    generateBill(quantities, menu, item_count);

    return 0;
}

void displayMenu(struct MenuItem menu[], int item_count) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

float calculateTotal(int quantities[], struct MenuItem menu[], int item_count) {
    float total = 0.0;
    for (int i = 0; i < item_count; i++) {
        total += quantities[i] * menu[i].price;
    }
    return total;
}

void generateBill(int quantities[], struct MenuItem menu[], int item_count) {
    printf("\n--- Your Bill ---\n");
    for (int i = 0; i < item_count; i++) {
        if (quantities[i] > 0) {
            printf("%s x %d = $%.2f\n", menu[i].name, quantities[i], quantities[i] * menu[i].price);
        }
    }
    float total = calculateTotal(quantities, menu, item_count);
    printf("Total Amount Due: $%.2f\n", total);
    printf("Thank you for visiting our cafe!\n");
}