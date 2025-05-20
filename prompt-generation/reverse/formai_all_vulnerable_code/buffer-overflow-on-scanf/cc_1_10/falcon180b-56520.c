//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the menu items
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Function to display the menu
void displayMenu(MenuItem menu[], int size) {
    printf("MENU:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take the order from the customer
void takeOrder(MenuItem menu[], int size) {
    int choice;
    float total = 0;
    printf("Enter the number of the item you want to order: ");
    scanf("%d", &choice);
    total += menu[choice-1].price;
    printf("Your order has been placed. Total cost: $%.2f\n", total);
}

// Function to calculate the bill
void calculateBill(MenuItem menu[], int size, int quantity) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        if (menu[i].name == "Coffee") {
            total += 2.50 * quantity;
        } else if (menu[i].name == "Tea") {
            total += 1.50 * quantity;
        } else if (menu[i].name == "Cake") {
            total += 3.00 * quantity;
        }
    }
    printf("Total bill: $%.2f\n", total);
}

// Main function
int main() {
    MenuItem menu[] = {{"Coffee", 2.50}, {"Tea", 1.50}, {"Cake", 3.00}};
    int size = sizeof(menu)/sizeof(menu[0]);
    int quantity;
    printf("Enter the quantity of each item you want to order: ");
    scanf("%d", &quantity);
    calculateBill(menu, size, quantity);
    return 0;
}