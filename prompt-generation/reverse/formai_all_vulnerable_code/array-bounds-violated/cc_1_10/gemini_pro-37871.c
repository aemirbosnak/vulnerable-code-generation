//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure to store cafe menu items
typedef struct MenuItem {
    char name[50];
    float price;
} MenuItem;

// Array of cafe menu items
MenuItem menu[] = {
    {"Espresso", 2.50},
    {"Cappuccino", 3.00},
    {"Latte", 3.50},
    {"Americano", 2.75},
    {"Mocha", 4.00},
    {"Chai Tea", 3.25},
    {"Hot Chocolate", 2.75},
    {"Muffin", 2.00},
    {"Croissant", 2.50},
    {"Scone", 2.25}
};

// Function to print the cafe menu
void printMenu() {
    printf("\nCafe Menu\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// Function to get user input for order
int getOrder() {
    int choice;
    printf("\nEnter your choice (1-10): ");
    scanf("%d", &choice);
    return choice;
}

// Function to calculate the total bill
float calculateBill(int *order, int orderSize) {
    float total = 0;
    for (int i = 0; i < orderSize; i++) {
        total += menu[order[i] - 1].price;
    }
    return total;
}

// Function to print the receipt
void printReceipt(int *order, int orderSize, float total) {
    printf("\nReceipt\n");
    for (int i = 0; i < orderSize; i++) {
        printf("%s - $%.2f\n", menu[order[i] - 1].name, menu[order[i] - 1].price);
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    // Print the cafe menu
    printMenu();

    // Get the user's order
    int order[10];
    int orderSize = 0;
    int choice;
    do {
        choice = getOrder();
        if (choice >= 1 && choice <= 10) {
            order[orderSize++] = choice;
        } else {
            printf("Invalid choice. Please enter a number between 1 and 10.\n");
        }
    } while (choice != 0);

    // Calculate the total bill
    float total = calculateBill(order, orderSize);

    // Print the receipt
    printReceipt(order, orderSize, total);

    return 0;
}