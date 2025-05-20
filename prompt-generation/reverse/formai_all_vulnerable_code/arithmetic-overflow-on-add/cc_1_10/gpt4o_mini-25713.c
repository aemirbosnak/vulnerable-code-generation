//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>

#define MAX_ITEMS 10

// Structure for Menu Items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Function to display the menu
void displayMenu(MenuItem menu[], int size) {
    printf("\n*** Cafe Menu ***\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\nSelect your items by number (1 to %d) or 0 to finish:\n", size);
}

// Function to calculate total and print the bill
void printBill(MenuItem menu[], int quantities[], int size) {
    float total = 0.0;
    printf("\n*** Your Bill ***\n");
    for (int i = 0; i < size; i++) {
        if (quantities[i] > 0) {
            float cost = menu[i].price * quantities[i];
            printf("%s x%d - $%.2f\n", menu[i].name, quantities[i], cost);
            total += cost;
        }
    }
    printf("Total Amount: $%.2f\n", total);
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Sandwich", 3.50},
        {"Pasta", 5.00},
        {"Burger", 4.25},
        {"Pizza", 6.00},
        {"Salad", 3.00},
        {"Juice", 2.00},
        {"Cake", 2.50},
        {"Ice Cream", 3.75}
    };

    int quantities[MAX_ITEMS] = {0}; // Array to store quantities of each menu item
    int choice, quantity;

    while (1) {
        displayMenu(menu, MAX_ITEMS);
        scanf("%d", &choice);

        if (choice == 0) {
            break; // Exit loop and finish selection
        } else if (choice < 1 || choice > MAX_ITEMS) {
            printf("Invalid choice! Please select a valid option.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantity);

        if (quantity < 0) {
            printf("Quantity cannot be negative. Please try again.\n");
            continue;
        }

        quantities[choice - 1] += quantity; // Update the quantity
    }

    printBill(menu, quantities, MAX_ITEMS);

    return 0;
}