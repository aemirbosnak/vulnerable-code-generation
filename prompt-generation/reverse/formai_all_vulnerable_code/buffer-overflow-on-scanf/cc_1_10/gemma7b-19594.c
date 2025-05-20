//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

int main() {
    int i, totalItems = 0;

    // Create a loop to add items to the array
    for (i = 0; i < MAX_ITEMS && totalItems < MAX_ITEMS; i++) {
        printf("Enter item name: ");
        scanf("%s", items[i].name);

        printf("Enter item quantity: ");
        scanf("%d", &items[i].quantity);

        printf("Enter item price: ");
        scanf("%f", &items[i].price);

        totalItems++;
    }

    // Calculate the total cost of the items
    float totalCost = 0;
    for (i = 0; i < totalItems; i++) {
        totalCost += items[i].quantity * items[i].price;
    }

    // Print the bill
    printf("----------------------------------------\n");
    printf("C Cafe Bill\n");
    printf("----------------------------------------\n");
    printf("Items:\n");
    for (i = 0; i < totalItems; i++) {
        printf("%s: %d @ %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    printf("\nTotal Cost: %.2f\n", totalCost);
    printf("Thank you for your visit!\n");

    return 0;
}