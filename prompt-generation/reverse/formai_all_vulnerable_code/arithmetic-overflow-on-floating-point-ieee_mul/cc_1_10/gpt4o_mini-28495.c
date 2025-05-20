//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
    float price;
    int quantity;
} MenuItem;

void displayMenu(MenuItem menu[], int itemCount);
void takeOrder(MenuItem menu[], int itemCount);
float calculateTotal(MenuItem order[], int orderCount);
void printInvoice(MenuItem order[], int orderCount, float total);

int main() {
    MenuItem menu[MAX_ITEMS] = {
        {"Coffee", 2.50, 0},
        {"Tea", 2.00, 0},
        {"Sandwich", 5.00, 0},
        {"Pastry", 3.50, 0},
        {"Cake", 4.00, 0},
        {"Juice", 3.00, 0}
    };
    
    int itemCount = 6;
    
    printf("========================================\n");
    printf(" Welcome to the C Cafe Billing System! \n");
    printf("========================================\n");
    
    takeOrder(menu, itemCount);
    
    return 0;
}

void displayMenu(MenuItem menu[], int itemCount) {
    printf("Menu:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("--------------------------------------------------\n");
}

void takeOrder(MenuItem menu[], int itemCount) {
    MenuItem order[MAX_ITEMS];
    int orderCount = 0;
    int choice, quantity;

    displayMenu(menu, itemCount);
    
    while (1) {
        printf("Enter the item number to order (0 to finish): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        if (choice < 1 || choice > itemCount) {
            printf("Invalid choice! Try again.\n");
            continue;
        }
        
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        
        if (quantity <= 0) {
            printf("Quantity must be greater than zero. Try again.\n");
            continue;
        }

        order[orderCount] = menu[choice - 1];
        order[orderCount].quantity = quantity;
        orderCount++;
        
        printf("Added %d x %s to your order.\n", quantity, order[orderCount - 1].name);
    }
    
    float total = calculateTotal(order, orderCount);
    printInvoice(order, orderCount, total);
}

float calculateTotal(MenuItem order[], int orderCount) {
    float total = 0.0;
    for (int i = 0; i < orderCount; i++) {
        total += order[i].price * order[i].quantity;
    }
    return total;
}

void printInvoice(MenuItem order[], int orderCount, float total) {
    printf("\n========================================\n");
    printf("                 Invoice                 \n");
    printf("========================================\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d x %s - $%.2f each\n", order[i].quantity, order[i].name, order[i].price);
    }
    printf("----------------------------------------\n");
    printf("Total Amount: $%.2f\n", total);
    printf("Thank you for visiting C Cafe!\n");
    printf("========================================\n");
}