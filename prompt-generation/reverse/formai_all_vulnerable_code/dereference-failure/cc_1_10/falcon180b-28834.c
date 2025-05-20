//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store customer information
struct customer {
    char name[50];
    char order[100];
    float total;
};

// Struct to store item information
struct item {
    char name[50];
    float price;
};

// Function to calculate total cost
float calculateTotal(struct item *items, int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price;
    }
    return total;
}

// Function to print the receipt
void printReceipt(struct customer *customer, struct item *items, int numItems) {
    printf("Customer Name: %s\n", customer->name);
    printf("Order: %s\n", customer->order);
    printf("Total Cost: $%.2f\n", customer->total);
    printf("\n");
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }
}

int main() {
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    // Allocate memory for items
    struct item *items = (struct item*) malloc(numItems * sizeof(struct item));

    // Get item information from user
    for (int i = 0; i < numItems; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);
        printf("Enter item price: ");
        scanf("%f", &items[i].price);
    }

    // Allocate memory for customer
    struct customer *customer = (struct customer*) malloc(sizeof(struct customer));

    // Get customer information from user
    printf("Enter customer name: ");
    scanf("%s", customer->name);

    // Calculate total cost
    customer->total = calculateTotal(items, numItems);

    // Print receipt
    printReceipt(customer, items, numItems);

    // Free memory
    free(items);
    free(customer);

    return 0;
}