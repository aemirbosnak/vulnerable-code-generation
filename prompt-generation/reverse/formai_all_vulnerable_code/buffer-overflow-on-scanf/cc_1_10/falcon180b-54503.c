//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

// Structure to hold item information
typedef struct {
    char name[50];
    double price;
} Item;

// Function to add an item to the menu
void addItem(Item menu[], int *numItems) {
    printf("Enter item name: ");
    scanf("%s", &menu[*numItems].name);
    printf("Enter item price: $");
    scanf("%lf", &menu[*numItems].price);
    (*numItems)++;
}

// Function to display the menu
void displayMenu(Item menu[], int numItems) {
    printf("Menu:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2lf\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take customer orders
void takeOrder(Item menu[], int numItems, double *total) {
    int choice;
    printf("Enter your choice (1-%d): ", numItems);
    scanf("%d", &choice);
    if (choice >= 1 && choice <= numItems) {
        *total += menu[choice-1].price;
        printf("You ordered %s for $%.2lf.\n", menu[choice-1].name, menu[choice-1].price);
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to calculate and display total bill
void calculateTotal(double total) {
    printf("Your total bill is $%.2lf.\n", total);
}

int main() {
    Item menu[MAX_ITEMS];
    int numItems = 0;

    // Add items to menu
    addItem(menu, &numItems);
    addItem(menu, &numItems);

    // Display menu
    displayMenu(menu, numItems);

    // Take customer order
    double total = 0.0;
    takeOrder(menu, numItems, &total);

    // Calculate and display total bill
    calculateTotal(total);

    return 0;
}