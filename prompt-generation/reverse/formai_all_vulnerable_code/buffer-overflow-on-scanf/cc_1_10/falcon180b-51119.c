//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>

// Function to calculate the total bill amount
float calculateTotal(int numItems, float prices[], int quantities[]) {
    float total = 0;
    for (int i = 0; i < numItems; i++) {
        total += prices[i] * quantities[i];
    }
    return total;
}

// Function to print the bill
void printBill(int numItems, char items[], float prices[], int quantities[]) {
    printf("\nItem\tQuantity\tPrice\tTotal\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", items[i], quantities[i], prices[i], prices[i] * quantities[i]);
    }
    printf("\nTotal Bill Amount: %.2f\n", calculateTotal(numItems, prices, quantities));
}

int main() {
    int numItems;
    printf("Enter the number of items in your order: ");
    scanf("%d", &numItems);

    // Array to store item names
    char items[numItems][50];

    // Array to store item prices
    float prices[numItems];

    // Array to store item quantities
    int quantities[numItems];

    // Get item details from user
    for (int i = 0; i < numItems; i++) {
        printf("\nItem %d:\n", i+1);
        printf("Enter item name: ");
        scanf("%s", items[i]);
        printf("Enter item price: ");
        scanf("%f", &prices[i]);
        printf("Enter item quantity: ");
        scanf("%d", &quantities[i]);
    }

    // Print the bill
    printBill(numItems, items, prices, quantities);

    return 0;
}