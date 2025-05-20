//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int id;
    float price;
} Item;

int main() {
    int num_items, choice, id;
    char ch;
    float total = 0.0;
    Item items[100];

    // Initialize items
    strcpy(items[0].name, "Coffee");
    items[0].id = 1;
    items[0].price = 2.50;

    strcpy(items[1].name, "Tea");
    items[1].id = 2;
    items[1].price = 1.50;

    strcpy(items[2].name, "Cake");
    items[2].id = 3;
    items[2].price = 3.50;

    num_items = 3;

    // Display menu
    printf("Welcome to the Cafe!\n");
    printf("Please choose an item from the menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }

    // Get customer's choice
    scanf("%d", &choice);

    // Check if choice is valid
    if (choice < 1 || choice > num_items) {
        printf("Invalid choice.\n");
        exit(1);
    }

    // Get customer's ID
    printf("Enter your ID:\n");
    scanf("%d", &id);

    // Search for customer in database
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            printf("Welcome back, %s!\n", items[i].name);
        }
    }

    // Calculate total price
    total = items[choice-1].price;

    // Print receipt
    printf("\nReceipt:\n");
    printf("Item: %s\n", items[choice-1].name);
    printf("Price: $%.2f\n", items[choice-1].price);
    printf("Total: $%.2f\n", total);

    return 0;
}