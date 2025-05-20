//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    char name[30];
    float price;
    int quantity;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\nCafe Menu:\n");
    printf("----------------------------------------\n");
    printf("Item No\t\tItem Name\tPrice\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t\t%s\t\t%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("----------------------------------------\n");
}

float calculateTotal(MenuItem menu[], int itemCount) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += menu[i].price * menu[i].quantity;
    }
    return total;
}

float applyDiscount(float total) {
    if (total > 100) {
        total *= 0.9;  // 10% discount for bills over 100
    }
    return total;
}

void generateBill(MenuItem menu[], int itemCount) {
    printf("\n--- Your Bill ---\n");
    printf("Item Name\tQuantity\tPrice\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        if (menu[i].quantity > 0) {
            printf("%s\t\t%d\t\t%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    float total = calculateTotal(menu, itemCount);
    float discountedTotal = applyDiscount(total);
    printf("-----------------------------------\n");
    printf("Total before discount: %.2f\n", total);
    printf("Total after discount: %.2f\n", discountedTotal);
    printf("--- Thank you for your visit! ---\n");
}

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.5, 0},
        {"Tea", 1.5, 0},
        {"Sandwich", 3.0, 0},
        {"Pasta", 5.0, 0},
        {"Burger", 4.0, 0},
        {"Juice", 2.0, 0},
        {"Soda", 1.0, 0},
        {"Cake", 2.5, 0},
        {"Pizza", 7.0, 0},
        {"Salad", 3.5, 0}
    };
    
    int itemCount = 10;
    int choice;
    
    do {
        displayMenu(menu, itemCount);
        printf("Enter the item number to order (0 to finish): ");
        scanf("%d", &choice);
        
        if (choice > 0 && choice <= itemCount) {
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &menu[choice - 1].quantity);
        } else if (choice != 0) {
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
    
    generateBill(menu, itemCount);
    
    return 0;
}