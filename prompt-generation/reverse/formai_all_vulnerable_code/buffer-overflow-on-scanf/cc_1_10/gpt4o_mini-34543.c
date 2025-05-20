//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 10

// Structure to represent a menu item
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Function to display the menu
void displayMenu(MenuItem items[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    printf("ID\tItem\t\tPrice\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

// Function to calculate the total bill with taxes
float calculateTotal(float subtotal, float taxRate, float discount) {
    float taxAmount = (subtotal * taxRate) / 100;
    float discountAmount = (subtotal * discount) / 100;
    return subtotal + taxAmount - discountAmount;
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50},
        {"Tea", 1.75},
        {"Sandwich", 5.00},
        {"Burger", 6.50},
        {"Pasta", 7.50},
        {"Cake", 4.25},
        {"Ice Cream", 3.50},
        {"Soda", 1.25},
        {"Fries", 2.00},
        {"Pizza", 8.00}
    };

    int choice[MAX_ITEMS];
    int quantity[MAX_ITEMS];
    int itemCount = 10;
    float subtotal = 0.0, total = 0.0;
    char moreItems;

    printf("Welcome to Cafe Billing System!\n");
    
    // Input choices from the user
    do {
        displayMenu(menu, itemCount);
        printf("Enter the item ID (0 to finish): ");
        int itemId;
        scanf("%d", &itemId);

        if (itemId == 0) {
            break;
        }

        if (itemId < 1 || itemId > itemCount) {
            printf("Invalid Item ID. Please try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity[itemId - 1]);
        choice[itemId - 1] = 1; // Mark this item as chosen
        subtotal += menu[itemId - 1].price * quantity[itemId - 1];

        printf("Do you want to add more items? (y/n): ");
        scanf(" %c", &moreItems);
    } while (moreItems == 'y' || moreItems == 'Y');

    // Display the subtotal
    printf("\n--- Bill Summary ---\n");
    printf("Item\t\tQuantity\tPrice\n");

    for (int i = 0; i < itemCount; i++) {
        if (choice[i]) {
            printf("%s\t\t%d\t\t%.2f\n", menu[i].name, quantity[i], menu[i].price * quantity[i]);
        }
    }

    float discountRate = 10.0; // 10% discount
    float taxRate = 5.0;        // 5% tax

    // Calculate total
    total = calculateTotal(subtotal, taxRate, discountRate);

    // Display final amounts
    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Discount (%.1f%%): -$%.2f\n", discountRate, (subtotal * discountRate) / 100);
    printf("Tax (%.1f%%): +$%.2f\n", taxRate, (subtotal * taxRate) / 100);
    printf("---------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("Thank you for visiting our cafe!\n");

    return 0;
}