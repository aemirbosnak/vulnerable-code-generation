//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>

#define MAX_ITEMS 100

// Function Prototypes
void displayMenu();
void takeOrder(int *itemCount, int orderedItems[], double prices[]);
void calculateBill(int itemCount, int orderedItems[], double prices[], double *total);
void printReceipt(int itemCount, int orderedItems[], double prices[], double total);

int main() {
    int orderedItems[MAX_ITEMS];
    double prices[MAX_ITEMS] = {2.5, 3.0, 1.5, 2.0, 4.0}; // Prices for each item
    int itemCount = 0;
    double total = 0.0;

    printf("Welcome to the Cafe Billing System\n");

    displayMenu();
    takeOrder(&itemCount, orderedItems, prices);
    calculateBill(itemCount, orderedItems, prices, &total);
    printReceipt(itemCount, orderedItems, prices, total);

    return 0;
}

void displayMenu() {
    printf("\n--- Cafe Menu ---\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $3.00\n");
    printf("3. Sandwich - $1.50\n");
    printf("4. Cake - $2.00\n");
    printf("5. Juice - $4.00\n");
    printf("-----------------\n");
    printf("Please enter the number corresponding to your choice (0 to finish):\n");
}

void takeOrder(int *itemCount, int orderedItems[], double prices[]) {
    int choice;

    while (1) {
        scanf("%d", &choice);
        if (choice == 0) break; // Exit if the user enters 0
        
        if (choice < 1 || choice > 5) {
            printf("Invalid choice, please try again.\n");
            continue;
        }
        
        orderedItems[*itemCount] = choice - 1; // Store the item index
        (*itemCount)++; // Increment the count
        printf("Added %s to your order. \n", choice == 1 ? "Coffee" :
                                              choice == 2 ? "Tea" :
                                              choice == 3 ? "Sandwich" :
                                              choice == 4 ? "Cake" : "Juice");
    }
}

void calculateBill(int itemCount, int orderedItems[], double prices[], double *total) {
    for (int i = 0; i < itemCount; i++) {
        *total += prices[orderedItems[i]];
    }
}

void printReceipt(int itemCount, int orderedItems[], double prices[], double total) {
    printf("\n--- Your Receipt ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s - $%.2f\n", 
            i + 1, 
            orderedItems[i] == 0 ? "Coffee" :
            orderedItems[i] == 1 ? "Tea" :
            orderedItems[i] == 2 ? "Sandwich" :
            orderedItems[i] == 3 ? "Cake" : "Juice",
            prices[orderedItems[i]]);
    }
    printf("---------------------\n");
    printf("Total: $%.2f\n", total);
    printf("Thank you for your visit!\n");
}