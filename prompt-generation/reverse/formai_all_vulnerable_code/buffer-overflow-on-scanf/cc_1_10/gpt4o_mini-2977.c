//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define NAME_LENGTH 20

typedef struct Item {
    char name[NAME_LENGTH];
    float price;
} Item;

typedef struct Order {
    Item items[MAX_ITEMS];
    int count;
    float total;
} Order;

// Function to display menu to the lovers in the quaint cafe
void displayMenu() {
    printf("Welcome to the Verona Cafe!\n");
    printf("1. Sweet Nectar (drink) - $3.50\n");
    printf("2. Romeo's Breadsticks - $5.00\n");
    printf("3. Juliet's Salad - $7.00\n");
    printf("4. Star-Crossed Pizza - $10.00\n");
    printf("5. Tragic Dessert (cake) - $4.00\n");
    printf("Please select a number from the menu to order (or 0 to finish): ");
}

// Function to add an item to the lovers' order
void addItem(Order *order, int choice, Item menu[]) {
    if (order->count < MAX_ITEMS) {
        order->items[order->count] = menu[choice - 1];
        order->total += menu[choice - 1].price;
        order->count++;
        printf("Item added: %s - $%.2f\n", menu[choice - 1].name, menu[choice - 1].price);
    } else {
        printf("Alas! Your order cannot contain more than %d items.\n", MAX_ITEMS);
    }
}

// Function to display the lovers' order with the total bill
void displayOrder(Order order) {
    printf("\nYour Order:\n");
    for (int i = 0; i < order.count; i++) {
        printf("- %s: $%.2f\n", order.items[i].name, order.items[i].price);
    }
    printf("Total Amount Due: $%.2f\n", order.total);
}

// Function to process the payment; a moment of truth!
void processPayment(float total) {
    printf("\nThe total amount to pay is: $%.2f\n", total);
    printf("Enter amount paid: $");
    
    float payment;
    scanf("%f", &payment);
    
    if (payment < total) {
        printf("Oh dear! Insufficient funds. Thou hast not enough gold.\n");
    } else {
        printf("Payment successful! Change due: $%.2f\n", payment - total);
        printf("Thank you for visiting, dear lovers!\n");
    }
}

int main() {
    Item menu[] = {
        {"Sweet Nectar", 3.50},
        {"Romeo's Breadsticks", 5.00},
        {"Juliet's Salad", 7.00},
        {"Star-Crossed Pizza", 10.00},
        {"Tragic Dessert", 4.00}
    };

    Order order;
    order.count = 0;
    order.total = 0.0;

    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice > 0 && choice <= 5) {
            addItem(&order, choice, menu);
        } else if (choice < 0 || choice > 5) {
            printf("O noble traveler! Please choose from the very menu before thine eyes.\n");
        }
        
    } while (choice != 0);
    
    displayOrder(order);
    processPayment(order.total);

    return 0;
}