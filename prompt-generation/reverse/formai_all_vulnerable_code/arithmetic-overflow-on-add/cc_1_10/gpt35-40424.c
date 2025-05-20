//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include<stdio.h>

// Function to calculate the total number of items ordered
int calculateTotalItemsOrdered(int items[], int size) {
    int totalItemsOrdered = 0;
    for(int i=0; i<size; i++) {
        totalItemsOrdered += items[i];
    }
    return totalItemsOrdered;
}

// Function to calculate the total cost of items ordered
float calculateTotalCost(int items[], float prices[], int size) {
    float totalCost = 0.0;
    for(int i=0; i<size; i++) {
        totalCost += items[i] * prices[i];
    }
    return totalCost;
}

int main() {
    // Menu with prices
    char menuItems[][25] = {"Cappuccino", "Espresso", "Latte", "Mocha", "Hot Chocolate", "Tea"};
    float menuPrices[] = {3.5, 2.5, 3.0, 4.0, 2.0, 1.5};
    int menuSize = sizeof(menuPrices) / sizeof(menuPrices[0]);

    printf("\t\tC Cafe Billing System\n");
    printf("------------------------------------------------------\n");
    printf("Menu\n------------------------------------------------------\n");
    // Print menu with prices
    for(int i=0; i<menuSize; i++) {
        printf("%d. %-20s $%.2f\n", i+1, menuItems[i], menuPrices[i]);
    }
    printf("------------------------------------------------------\n");

    int itemsOrdered[menuSize];
    // Initialize all items ordered to 0
    for(int i=0; i<menuSize; i++) {
        itemsOrdered[i] = 0;
    }

    int choice = 0;
    do {
        printf("Enter your choice (1-%d) or 0 to exit: ", menuSize);
        scanf("%d", &choice);

        if(choice >= 1 && choice <= menuSize) {
            int quantity = 0;
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            // Update the number of items ordered
            itemsOrdered[choice-1] += quantity;
        } else if(choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 0);

    printf("------------------------------------------------------\n");
    printf("Items Ordered\n------------------------------------------------------\n");
    // Print items ordered along with their quantities and individual prices
    for(int i=0; i<menuSize; i++) {
        if(itemsOrdered[i] != 0) {
            printf("%-20s %2d x $%.2f = $%.2f\n", menuItems[i], itemsOrdered[i], menuPrices[i], itemsOrdered[i] * menuPrices[i]);
        }
    }
    printf("------------------------------------------------------\n");

    // Calculate total items ordered and total cost of items ordered
    int totalItemsOrdered = calculateTotalItemsOrdered(itemsOrdered, menuSize);
    float totalCost = calculateTotalCost(itemsOrdered, menuPrices, menuSize);
    printf("Total items ordered: %d\n", totalItemsOrdered);
    printf("Total cost: $%.2f\n", totalCost);

    return 0;
}