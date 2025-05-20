//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store cafe items
typedef struct CafeItem {
    char name[50];
    int quantity;
    float price;
} CafeItem;

// Array of cafe items
CafeItem cafeItems[] = {
    {"Coffee", 0, 2.50},
    {"Tea", 0, 1.50},
    {"Cake", 0, 3.00},
    {"Muffin", 0, 2.00},
    {"Sandwich", 0, 4.00},
};

// Function to print the cafe menu
void printMenu() {
    printf("Cafe Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i + 1, cafeItems[i].name, cafeItems[i].price);
    }
}

// Function to get user input
int getUserInput(char *message) {
    int input;
    printf("%s", message);
    scanf("%d", &input);
    return input;
}

// Function to add an item to the order
void addItemToOrder(int itemNumber, int quantity) {
    cafeItems[itemNumber - 1].quantity += quantity;
}

// Function to calculate the total cost of the order
float calculateTotalCost() {
    float totalCost = 0;
    for (int i = 0; i < 5; i++) {
        totalCost += cafeItems[i].quantity * cafeItems[i].price;
    }
    return totalCost;
}

// Function to print the order
void printOrder() {
    printf("Your Order:\n");
    for (int i = 0; i < 5; i++) {
        if (cafeItems[i].quantity > 0) {
            printf("%d x %s - $%.2f\n", cafeItems[i].quantity, cafeItems[i].name, cafeItems[i].quantity * cafeItems[i].price);
        }
    }
}

// Main function
int main() {
    // Print the cafe menu
    printMenu();

    // Get user input for the order
    int itemNumber;
    int quantity;
    bool continueOrdering = true;
    while (continueOrdering) {
        itemNumber = getUserInput("Enter the item number (1-5): ");
        quantity = getUserInput("Enter the quantity: ");
        addItemToOrder(itemNumber, quantity);
        continueOrdering = getUserInput("Continue ordering? (1 for yes, 0 for no): ");
    }

    // Calculate the total cost of the order
    float totalCost = calculateTotalCost();

    // Print the order
    printOrder();

    // Print the total cost
    printf("Total Cost: $%.2f\n", totalCost);

    return 0;
}