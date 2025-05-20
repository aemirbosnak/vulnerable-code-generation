//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    float price;
    int shape; // 1: Circle, 2: Square, 3: Triangle
} MenuItem;

void displayMenu(MenuItem menu[], int count) {
    printf("\nWelcome to the Shape-Shifting Cafe!\n");
    printf("-------------------------------------\n");
    printf("Shape\t\tItem Name\t\tPrice\n");
    printf("-----\t\t----------\t\t-----\n");
    for (int i = 0; i < count; i++) {
        char shapeSymbol[10];
        switch (menu[i].shape) {
            case 1: strcpy(shapeSymbol, "O"); break; // Circle
            case 2: strcpy(shapeSymbol, "[ ]"); break; // Square
            case 3: strcpy(shapeSymbol, "/\\"); break; // Triangle
            default: strcpy(shapeSymbol, "?"); break; 
        }
        printf("%s\t\t%-15s\t\t%.2f\n", shapeSymbol, menu[i].name, menu[i].price);
    }
    printf("-------------------------------------\n");
}

void calculateTotal(MenuItem menu[], int count) {
    float total = 0;
    int choice, quantity;
    printf("Select the items by shape number (1-%d) and quantity (0 to stop):\n", count);
    
    while (1) {
        printf("Enter the shape number (or 0 to finish): ");
        scanf("%d", &choice);
        
        if (choice == 0) break; // Exit if the user enters 0
        if (choice < 1 || choice > count) {
            printf("Invalid choice, please try again.\n");
            continue; // Skip invalid choice
        }
        
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        
        if (quantity < 1) {
            printf("Invalid quantity, please enter a positive number.\n");
            continue; // Skip invalid quantity
        }
        
        total += menu[choice - 1].price * quantity;
        printf("Added %d x %s to your bill (total now: %.2f)\n", quantity, menu[choice - 1].name, total);
    }
    
    printf("-------------------------------------\n");
    printf("Your total bill is: %.2f\n", total);
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50, 1},       // Circle
        {"Tea", 2.00, 1},          // Circle
        {"Sandwich", 5.00, 2},     // Square
        {"Cake", 3.50, 2},         // Square
        {"Pastry", 4.00, 3},       // Triangle
        {"Cookies", 1.50, 3}       // Triangle
    };
    
    int menuCount = 6; // Total unique items
    displayMenu(menu, menuCount);
    calculateTotal(menu, menuCount);
    
    printf("Thank you for visiting the Shape-Shifting Cafe!\n");
    return 0;
}