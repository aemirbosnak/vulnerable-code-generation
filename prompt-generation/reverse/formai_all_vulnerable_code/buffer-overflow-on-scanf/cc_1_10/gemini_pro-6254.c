//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Structure to store the details of each item ordered
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item;

// Function to take the order from the customer
void takeOrder(item *items, int *numItems) {
    printf("Enter the number of items you want to order: ");
    scanf("%d", numItems);

    for (int i = 0; i < *numItems; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);

        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &items[i].quantity);

        printf("Enter the price of item %d: ", i + 1);
        scanf("%f", &items[i].price);
    }
}

// Function to calculate the total bill
float calculateBill(item *items, int numItems) {
    float totalBill = 0;

    for (int i = 0; i < numItems; i++) {
        totalBill += items[i].quantity * items[i].price;
    }

    return totalBill;
}

// Function to print the bill
void printBill(item *items, int numItems, float totalBill) {
    printf("\n\n========== Cafe Billing System ==========\n");

    printf("\nItems Ordered:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    printf("\nTotal Bill: %.2f\n", totalBill);
}

// Main function
int main() {
    // Declare an array of items to store the order
    item items[100];

    // Declare a variable to store the number of items ordered
    int numItems;

    // Take the order from the customer
    takeOrder(items, &numItems);

    // Calculate the total bill
    float totalBill = calculateBill(items, numItems);

    // Print the bill
    printBill(items, numItems, totalBill);

    return 0;
}