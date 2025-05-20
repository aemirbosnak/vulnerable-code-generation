//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to hold menu items
typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

// Function to display menu and return user's chosen item
int displayMenu(MenuItem menu[], int size) {
    int choice;
    printf("\nMenu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("Enter item number to add to order (or 0 to exit): ");
    scanf("%d", &choice);
    return choice;
}

// Function to add item to order
void addItemToOrder(MenuItem menu[], int size, int itemIndex, float* total) {
    if (itemIndex == 0) {
        printf("Order complete. Total: $%.2f\n", *total);
        return;
    }
    // Subtract 1 to convert from user input to array index
    MenuItem item = menu[itemIndex - 1];
    printf("Adding %s to order for $%.2f\n", item.name, item.price);
    *total += item.price;
}

int main() {
    // Seed random number generator for generating order numbers
    srand(time(NULL));
    
    // Initialize menu items
    MenuItem menu[] = {
        {1, "Coffee", 2.50},
        {2, "Tea", 2.00},
        {3, "Muffin", 3.00},
        {4, "Croissant", 3.50},
        {5, "Bagel", 2.50}
    };
    int menuSize = sizeof(menu) / sizeof(MenuItem);
    
    // Initialize variables
    float total = 0;
    int orderNumber = rand() % 10000 + 1;
    
    // Display welcome message and initial menu
    printf("Welcome to C Cafe!\n");
    int choice = displayMenu(menu, menuSize);
    
    // Process user selections until user exits
    while (choice != 0) {
        addItemToOrder(menu, menuSize, choice, &total);
        choice = displayMenu(menu, menuSize);
    }
    
    printf("Thank you for your order!\n");
    printf("Order Number: %d\n", orderNumber);
    printf("Total: $%.2f\n", total);
    
    return 0;
}