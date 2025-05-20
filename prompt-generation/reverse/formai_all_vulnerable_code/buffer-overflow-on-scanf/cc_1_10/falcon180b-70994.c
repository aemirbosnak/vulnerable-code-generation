//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>

// Function to calculate the total cost of items ordered
float calculateTotalCost(int items[], int numItems) {
    float totalCost = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalCost += items[i];
    }
    return totalCost;
}

// Function to display the menu and take user's order
void orderMenu() {
    int menu[] = {5, 10, 15, 20}; // Menu items with their prices
    int numMenuItems = sizeof(menu) / sizeof(menu[0]);
    printf("Welcome to the Cafe! Here's our menu:\n");
    for (int i = 0; i < numMenuItems; i++) {
        printf("%d. %d - $%.2f\n", i+1, menu[i], (float)menu[i]/100);
    }
    int choice;
    scanf("%d", &choice);
    while (choice < 1 || choice > numMenuItems) {
        printf("Invalid choice. Please enter a number between 1 and %d:\n", numMenuItems);
        scanf("%d", &choice);
    }
    printf("You chose item %d - $%.2f\n", choice, (float)menu[choice-1]/100);
}

// Function to print the bill
void printBill(int items[], int numItems) {
    printf("Your bill:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %d - $%.2f\n", i+1, items[i], (float)items[i]/100);
    }
    printf("Total cost: $%.2f\n", calculateTotalCost(items, numItems));
}

// Main function
int main() {
    int items[100]; // Array to store user's order
    int numItems = 0; // Number of items ordered
    orderMenu();
    while (numItems < 100) {
        int choice;
        scanf("%d", &choice);
        while (choice < 1 || choice > 4) {
            printf("Invalid choice. Please enter a number between 1 and 4:\n");
            scanf("%d", &choice);
        }
        if (choice == 1) {
            items[numItems] = 5;
            numItems++;
        } else if (choice == 2) {
            items[numItems] = 10;
            numItems++;
        } else if (choice == 3) {
            items[numItems] = 15;
            numItems++;
        } else if (choice == 4) {
            items[numItems] = 20;
            numItems++;
        }
    }
    printBill(items, numItems);
    return 0;
}