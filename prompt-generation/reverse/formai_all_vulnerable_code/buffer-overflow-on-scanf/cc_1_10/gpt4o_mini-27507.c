//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    char name[50];
    float price;
    int quantity;
} MenuItem;

MenuItem menu[MAX_ITEMS];
int itemCount = 0;

void addItem(const char* name, float price) {
    if (itemCount < MAX_ITEMS) {
        strcpy(menu[itemCount].name, name);
        menu[itemCount].price = price;
        menu[itemCount].quantity = 0; // Initialize quantity to 0
        itemCount++;
    } else {
        printf("Menu is full. Cannot add more items.\n");
    }
}

void displayMenu() {
    printf("\nCafe Menu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

float calculateBill() {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += menu[i].price * menu[i].quantity;
    }
    return total;
}

void takeOrder() {
    int choice, quantity;
    while (1) {
        displayMenu();
        printf("Select an item number to order (0 to finish): ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= itemCount) {
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &quantity);
            menu[choice - 1].quantity += quantity; // Update the order quantity
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void printReceipt() {
    printf("\nReceipt:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        if (menu[i].quantity > 0) {
            printf("%s x %d = $%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }
    printf("-------------------------------------------------\n");
    printf("Total Amount: $%.2f\n", calculateBill());
    printf("Thank you for visiting!\n");
}

int main() {
    addItem("Coffee", 2.50);
    addItem("Tea", 1.75);
    addItem("Sandwich", 5.00);
    addItem("Cake", 3.25);
    addItem("Juice", 2.00);
    
    printf("Welcome to the Cafe Billing System\n");

    takeOrder();
    printReceipt();

    return 0;
}