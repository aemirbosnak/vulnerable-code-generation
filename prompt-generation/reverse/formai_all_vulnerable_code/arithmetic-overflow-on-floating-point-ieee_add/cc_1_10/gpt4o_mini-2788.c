//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    char name[50];
    float price;
    int quantity;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\n--- Cafe Menu ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("------------------\n");
}

float calculateTotal(MenuItem menu[], int itemCount) {
    float total = 0;
    for (int i = 0; i < itemCount; i++) {
        total += menu[i].price * menu[i].quantity;
    }
    return total;
}

void applyTax(float* total) {
    const float TAX_RATE = 0.07; // 7% tax
    *total += *total * TAX_RATE;
}

void resetOrder(MenuItem menu[], int itemCount) {
    for (int i = 0; i < itemCount; i++) {
        menu[i].quantity = 0; // Reset quantities for next order
    }
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 3.00, 0},
        {"Tea", 2.50, 0},
        {"Sandwich", 5.00, 0},
        {"Pasta", 7.50, 0},
        {"Salad", 4.00, 0},
        {"Soda", 1.50, 0},
        {"Juice", 2.00, 0},
        {"Cake", 3.50, 0},
        {"Ice Cream", 2.25, 0},
        {"Chocolate", 1.00, 0}
    };
    
    int itemCount = 10;
    char choice;
    
    do {
        displayMenu(menu, itemCount);
        
        int itemChoice;
        printf("Enter the item number to order (0 to finish): ");
        scanf("%d", &itemChoice);
        
        if (itemChoice == 0) {
            break; // Exit ordering
        } else if (itemChoice > 0 && itemChoice <= itemCount) {
            printf("Enter quantity: ");
            scanf("%d", &menu[itemChoice - 1].quantity);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        
        printf("Do you want to order another item? (Y/N): ");
        while ((getchar()) != '\n'); // Clear the input buffer
        scanf("%c", &choice);
        
    } while (choice == 'Y' || choice == 'y');
    
    float total = calculateTotal(menu, itemCount);
    applyTax(&total);
    
    printf("\n--- Final Bill ---\n");
    for (int i = 0; i < itemCount; i++) {
        if (menu[i].quantity > 0) {
            printf("%s x%d - $%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    printf("Total (including tax): $%.2f\n", total);
    
    resetOrder(menu, itemCount); // Prepare for the next order
    printf("Thank you for visiting!\n");
    
    return 0;
}