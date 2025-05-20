//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Defining the structure for the menu
struct menu {
    char name[50];
    float price;
};

// Defining the structure for the order
struct order {
    int quantity;
    struct menu item;
};

// Function to display the menu
void displayMenu(struct menu menu[], int size) {
    printf("Welcome to Cafe Capulet\n");
    printf("Here is our menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to take the order
void takeOrder(struct order order[], int size) {
    printf("What would you like to order?\n");
    scanf("%d", &order[0].quantity);
    scanf("%s", order[0].item.name);
    printf("How many %s would you like? ", order[0].item.name);
    scanf("%d", &order[0].quantity);
    printf("Your order has been placed.\n");
}

// Function to calculate the total cost of the order
float calculateTotal(struct order order[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += order[i].quantity * order[i].item.price;
    }
    return total;
}

// Function to print the receipt
void printReceipt(struct order order[], int size, float total) {
    printf("Thank you for your order at Cafe Capulet!\n");
    printf("Your order consists of:\n");
    for (int i = 0; i < size; i++) {
        printf("%d x %s - $%.2f\n", order[i].quantity, order[i].item.name, order[i].item.price * order[i].quantity);
    }
    printf("Total cost: $%.2f\n", total);
}

int main() {
    // Defining the menu
    struct menu menu[] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Cake", 3.25}};
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    // Defining the order
    struct order order[10];
    int orderSize = 0;

    // Displaying the menu
    displayMenu(menu, menuSize);

    // Taking the order
    while (orderSize < 10) {
        takeOrder(order, orderSize);
        orderSize++;
    }

    // Calculating the total cost of the order
    float total = calculateTotal(order, orderSize);

    // Printing the receipt
    printReceipt(order, orderSize, total);

    return 0;
}