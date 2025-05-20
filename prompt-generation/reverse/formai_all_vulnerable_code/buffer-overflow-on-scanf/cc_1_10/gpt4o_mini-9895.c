//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

struct Product {
    char name[30];
    float price;
    int quantity;
};

void displayProducts(struct Product inventory[], int size);
void calculateTotalSales(struct Product inventory[], int size);
void applyDiscount(struct Product inventory[], int size, float discountRate);
float calculateInventoryValue(struct Product inventory[], int size);

int main() {
    int size;
    float discountRate;
    struct Product inventory[50];

    // User input for inventory size
    printf("Enter the number of products in the inventory: ");
    scanf("%d", &size);

    // Input product details
    for (int i = 0; i < size; i++) {
        printf("\nEnter details for product %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", inventory[i].name);
        printf("Price: ");
        scanf("%f", &inventory[i].price);
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
    }

    // Display all products
    displayProducts(inventory, size);

    // Calculate total sales
    calculateTotalSales(inventory, size);

    // Apply discount to all products
    printf("\nEnter the discount rate (in percentage, e.g., 10 for 10%%): ");
    scanf("%f", &discountRate);
    applyDiscount(inventory, size, discountRate);

    // Recalculate total sales after discount
    calculateTotalSales(inventory, size);

    // Calculate total inventory value
    float totalInventoryValue = calculateInventoryValue(inventory, size);
    printf("\nTotal inventory value: $%.2f\n", totalInventoryValue);

    return 0;
}

// Function to display products
void displayProducts(struct Product inventory[], int size) {
    printf("\nCurrent Inventory:\n");
    printf("%-15s %-10s %-10s\n", "Product Name", "Price", "Quantity");
    printf("---------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-15s $%.2f     %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

// Function to calculate total sales
void calculateTotalSales(struct Product inventory[], int size) {
    float totalSales = 0.0;
    for (int i = 0; i < size; i++) {
        totalSales += inventory[i].price * inventory[i].quantity;
    }
    printf("Total Sales: $%.2f\n", totalSales);
}

// Function to apply discount on prices
void applyDiscount(struct Product inventory[], int size, float discountRate) {
    for (int i = 0; i < size; i++) {
        inventory[i].price -= (inventory[i].price * (discountRate / 100));
    }
    printf("Discount of %.2f%% applied on all products.\n", discountRate);
}

// Function to calculate total inventory value
float calculateInventoryValue(struct Product inventory[], int size) {
    float totalValue = 0.0;
    for (int i = 0; i < size; i++) {
        totalValue += inventory[i].price * inventory[i].quantity;
    }
    return totalValue;
}