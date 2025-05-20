//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for billing item
typedef struct {
    char name[50];
    float price;
} billingItem;

// Function to calculate total price of items
float calculateTotal(billingItem items[], int numItems) {
    float total = 0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].price;
    }
    return total;
}

// Function to print billing receipt
void printReceipt(billingItem items[], int numItems) {
    printf("Billing Receipt:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: $%.2f\n", items[i].name, items[i].price);
    }
    printf("Total: $%.2f\n", calculateTotal(items, numItems));
}

// Main function
int main() {
    // Initialize billing items
    billingItem items[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Pastry", 3.25}};
    int numItems = sizeof(items) / sizeof(billingItem);

    // Take user order
    char order[100];
    printf("Welcome to our romantic cafe! What can I get for you today?\n");
    scanf("%s", order);

    // Search for ordered items and add to bill
    int found = 0;
    for (int i = 0; i < numItems; i++) {
        if (strcmp(order, items[i].name) == 0) {
            printf("You ordered %s for $%.2f.\n", items[i].name, items[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("I'm sorry, we don't have %s.\n", order);
        return 0;
    }

    // Print billing receipt
    printReceipt(items, numItems);

    return 0;
}