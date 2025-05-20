//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for menu items and orders
typedef struct {
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int quantity;
    MenuItem item;
} Order;

// Function to print the menu
void printMenu(MenuItem menu[], int size) {
    printf("Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take customer order
void takeOrder(Order order[], int size, char* customerName) {
    printf("\nWelcome, %s! What would you like to order?\n", customerName);
    int choice;
    scanf("%d", &choice);

    if (choice >= 1 && choice <= size) {
        printf("You have chosen %s.\n", order[choice-1].item.name);
        printf("How many would you like to order? ");
        scanf("%d", &order[choice-1].quantity);
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to calculate total bill
float calculateTotal(Order order[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += order[i].quantity * order[i].item.price;
    }
    return total;
}

// Function to print receipt
void printReceipt(Order order[], int size, float total, char* customerName) {
    printf("\nThank you for your order, %s!\n", customerName);
    printf("Your total bill is: $%.2f\n", total);
    for (int i = 0; i < size; i++) {
        printf("%s x %d - $%.2f\n", order[i].item.name, order[i].quantity, order[i].quantity * order[i].item.price);
    }
}

int main() {
    // Define menu items
    MenuItem menu[] = {{"Coffee", 3.50}, {"Tea", 2.50}, {"Cake", 4.50}};

    // Define order structure and initialize with zeros
    Order order[10];
    memset(order, 0, sizeof(order));

    // Take customer order
    char customerName[50];
    printf("Enter your name: ");
    scanf("%s", customerName);
    takeOrder(order, 3, customerName);

    // Calculate total bill
    float total = calculateTotal(order, 3);

    // Print receipt
    printReceipt(order, 3, total, customerName);

    return 0;
}