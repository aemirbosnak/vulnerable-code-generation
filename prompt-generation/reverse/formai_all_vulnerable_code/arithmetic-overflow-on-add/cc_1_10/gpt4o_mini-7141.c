//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include <stdio.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("------------------\n");
}

float calculateTotal(int quantities[], MenuItem menu[], int itemCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += quantities[i] * menu[i].price;
    }
    return total;
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {1, "Coffee", 2.50},
        {2, "Tea", 1.50},
        {3, "Sandwich", 5.00},
        {4, "Cake", 3.00},
        {5, "Soda", 1.25}
    };

    int itemCount = 5;
    int quantities[MAX_ITEMS] = {0};

    while (1) {
        displayMenu(menu, itemCount);
        printf("Please select the item number to order (0 to finish): ");
        
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > itemCount) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter quantity for %s: ", menu[choice - 1].name);
        int quantity;
        scanf("%d", &quantity);

        if (quantity < 0) {
            printf("Quantity cannot be negative. Please try again.\n");
            continue;
        }

        quantities[choice - 1] += quantity;
        printf("You added %d x %s to your order.\n", quantity, menu[choice - 1].name);
    }

    float total = calculateTotal(quantities, menu, itemCount);
    printf("\n--- Your Order Summary ---\n");
    
    for (int i = 0; i < itemCount; i++) {
        if (quantities[i] > 0) {
            printf("%s x %d = $%.2f\n", menu[i].name, quantities[i], quantities[i] * menu[i].price);
        }
    }
    printf("---------------------------\n");
    printf("Total Amount Due: $%.2f\n", total);
    printf("Thank you for visiting our cafe!\n");

    return 0;
}