//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: modular
//cafe_billing_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the menu
#define MAX_MENU_ITEMS 100

// Define the structure for menu items
typedef struct {
    char name[50];
    double price;
} MenuItem;

// Function to read menu items from a file
void readMenuItems(MenuItem menuItems[], FILE *file) {
    int i = 0;
    while (fscanf(file, "%s %lf\n", menuItems[i].name, &menuItems[i].price)!= EOF) {
        i++;
    }
    menuItems[i].name[0] = '\0'; // mark the end of the menu
}

// Function to display the menu
void displayMenu(MenuItem menuItems[]) {
    printf("Menu:\n");
    for (int i = 0; menuItems[i].name[0]!= '\0'; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItems[i].name, menuItems[i].price);
    }
}

// Function to take user input for the menu item
int getMenuChoice(MenuItem menuItems[]) {
    int choice = 0;
    while (choice <= 0 || choice > MAX_MENU_ITEMS) {
        printf("Enter the number of the item you want to order: ");
        scanf("%d", &choice);
        if (choice <= 0 || choice > MAX_MENU_ITEMS) {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return choice-1; // convert choice to 0-based index
}

// Function to calculate the total price of the order
double calculateTotalPrice(MenuItem menuItems[], int numItems) {
    double totalPrice = 0.0;
    for (int i = 0; i < numItems; i++) {
        totalPrice += menuItems[i].price;
    }
    return totalPrice;
}

// Function to print the receipt
void printReceipt(double totalPrice) {
    printf("Receipt:\n");
    printf("Total price: $%.2f\n", totalPrice);
}

// Main function
int main() {
    FILE *menuFile;
    MenuItem menuItems[MAX_MENU_ITEMS];
    int numItems = 0;
    
    // Open the menu file
    menuFile = fopen("menu.txt", "r");
    if (menuFile == NULL) {
        printf("Error: could not open menu file.\n");
        return 1;
    }
    
    // Read the menu items
    readMenuItems(menuItems, menuFile);
    numItems = getMenuChoice(menuItems);
    
    // Calculate the total price of the order
    double totalPrice = calculateTotalPrice(menuItems, numItems);
    
    // Print the receipt
    printReceipt(totalPrice);
    
    // Close the menu file
    fclose(menuFile);
    
    return 0;
}

// End of cafe_billing_system.c