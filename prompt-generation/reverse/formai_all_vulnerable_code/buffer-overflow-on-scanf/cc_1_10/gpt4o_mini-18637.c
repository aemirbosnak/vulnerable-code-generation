//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

// Structure to hold menu item details
typedef struct {
    char name[30];
    float price;
} MenuItem;

// Function prototypes
void displayMenu(MenuItem menu[], int size);
void takeOrder(MenuItem menu[], int size);
float calculateTotal(int orders[], MenuItem menu[], int size);
void printReceipt(int orders[], MenuItem menu[], int size, float total);

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50},
        {"Latte", 3.00},
        {"Espresso", 3.50},
        {"Tea", 2.00},
        {"Sandwich", 5.00},
        {"Cake", 4.00},
        {"Salad", 4.50},
        {"Smoothie", 3.80},
        {"Juice", 2.80},
        {"Pasta", 7.00}
    };

    printf("🌟 Welcome to Our Energetic Cafe! 🌟\n");

    // Display menu and take order
    displayMenu(menu, MAX_ITEMS);
    takeOrder(menu, MAX_ITEMS);
    
    return 0;
}

void displayMenu(MenuItem menu[], int size) {
    printf("\n🎉 Here's our exciting menu! 🎉\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %-20s $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void takeOrder(MenuItem menu[], int size) {
    int orders[MAX_ITEMS] = {0}; // Store quantity of each item ordered
    int choice, quantity;
    char more;

    do {
        printf("\n👉 Enter the item number to order (1-%d): ", size);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > size) {
            printf("❌ Invalid selection! Please try again.\n");
            continue;
        }

        printf("🔢 How many of '%s' would you like to order? ", menu[choice - 1].name);
        scanf("%d", &quantity);
        
        if (quantity < 0) {
            printf("❌ Quantity can't be negative! Please try again.\n");
            continue;
        }

        orders[choice - 1] += quantity; // Update the ordered quantity 

        printf("✅ You ordered %d of '%s'. Would you like to add more? (y/n): ", quantity, menu[choice - 1].name);
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');

    // Calculate total and print receipt
    float total = calculateTotal(orders, menu, size);
    printReceipt(orders, menu, size, total);
}

float calculateTotal(int orders[], MenuItem menu[], int size) {
    float total = 0.0f;
    for (int i = 0; i < size; i++) {
        if (orders[i] > 0) {
            total += orders[i] * menu[i].price;
        }
    }
    return total;
}

void printReceipt(int orders[], MenuItem menu[], int size, float total) {
    printf("\n🎉🏪 Your Receipt 🏪🎉\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        if (orders[i] > 0) {
            printf("%-20s x%d = $%.2f\n", menu[i].name, orders[i], orders[i] * menu[i].price);
        }
    }
    printf("-------------------------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("💖 Thank you for visiting our cafe! Come back soon! 💖\n");
}