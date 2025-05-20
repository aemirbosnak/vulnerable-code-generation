//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct {
    char name[30];
    float price;
    int quantity;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount);
float calculateTotal(MenuItem menu[], int itemCount);
void printReceipt(MenuItem menu[], int itemCount, float total);

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50, 0},
        {"Tea", 1.50, 0},
        {"Sandwich", 4.00, 0},
        {"Burger", 5.50, 0},
        {"Pasta", 6.00, 0},
        {"Salad", 3.50, 0},
        {"Juice", 2.00, 0},
        {"Soda", 1.00, 0},
        {"Cake", 2.75, 0},
        {"Ice Cream", 3.00, 0}
    };

    int choice;
    int itemCount = 0;
    
    printf("Welcome to the C Cafe!\n");
   
    while (1) {
        displayMenu(menu, MAX_ITEMS);
        printf("Enter the item number to order (or 0 to finish): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        if (choice > 0 && choice <= MAX_ITEMS) {
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &menu[choice - 1].quantity);
            itemCount++;
        } else {
            printf("Invalid choice, please choose again.\n");
        }
    }

    if (itemCount > 0) {
        float total = calculateTotal(menu, MAX_ITEMS);
        printReceipt(menu, MAX_ITEMS, total);
    } else {
        printf("No items ordered. Thank you!\n");
    }

    return 0;
}

void displayMenu(MenuItem menu[], int itemCount) {
    printf("\nAvailable Menu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d: %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

float calculateTotal(MenuItem menu[], int itemCount) {
    float total = 0.0f;
    for (int i = 0; i < itemCount; i++) {
        if (menu[i].quantity > 0) {
            total += menu[i].price * menu[i].quantity;
        }
    }
    return total;
}

void printReceipt(MenuItem menu[], int itemCount, float total) {
    printf("\n--- Receipt ---\n");
    for (int i = 0; i < itemCount; i++) {
        if (menu[i].quantity > 0) {
            printf("%s x %d - $%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    printf("-----------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("Thank you for visiting C Cafe!\n");
}