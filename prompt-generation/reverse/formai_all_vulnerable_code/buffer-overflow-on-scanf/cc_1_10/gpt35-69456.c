//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold item details
typedef struct {
    char *itemName;
    int quantity;
    float price;
} item;

// Function prototypes
float totalBill(item *items, int n);
void printBill(item *items, int n);

// Main function
int main() {
    int n, i;
    float total;
    char itemName[50];
    item *items;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Allocate memory for the array of items
    items = (item *) malloc(n * sizeof(item));

    // Get details for each item
    for(i = 0; i < n; i++) {
        printf("Enter details for item %d:\n", i+1);

        printf("Enter name: ");
        scanf("%s", itemName);
        items[i].itemName = malloc(strlen(itemName) + 1);
        strcpy(items[i].itemName, itemName);

        printf("Enter quantity: ");
        scanf("%d", &items[i].quantity);

        printf("Enter price: ");
        scanf("%f", &items[i].price);
    }

    // Calculate total bill
    total = totalBill(items, n);

    // Print bill
    printBill(items, n);
    printf("Total Bill: %0.2f", total);

    // Free memory allocated for itemName
    for(i = 0; i < n; i++) {
        free(items[i].itemName);
    }

    // Free memory allocated for items
    free(items);

    return 0;
}

// Function to calculate total bill
float totalBill(item *items, int n) {
    int i;
    float total = 0;

    for(i = 0; i < n; i++) {
        total += items[i].quantity * items[i].price;
    }

    return total;
}

// Function to print the bill
void printBill(item *items, int n) {
    int i;

    printf("\n\n");
    printf("-----------------------------------------------\n");
    printf("|                C Cafe Billing System         |\n");
    printf("------------------------------------------------\n");
    printf("|         Item Name         |  Quantity |  Price |\n");
    printf("------------------------------------------------\n");
    for(i = 0; i < n; i++) {
        printf("|%-26s|%10d|%8.2f|\n", items[i].itemName, items[i].quantity, items[i].price);
    }
    printf("------------------------------------------------\n");
}