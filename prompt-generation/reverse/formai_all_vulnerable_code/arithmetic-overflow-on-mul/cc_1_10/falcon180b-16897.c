//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the prices of various items
#define COFFEE_PRICE 50
#define TEA_PRICE 30
#define BREAD_PRICE 20
#define CAKE_PRICE 40

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
typedef struct {
    int item[MAX_ITEMS];
    int quantity[MAX_ITEMS];
    int totalPrice;
} Order;

// Function to display the menu
void displayMenu() {
    printf("\n");
    printf("Welcome to the Medieval Cafe!\n");
    printf("Our menu includes:\n");
    printf("1. Coffee - %d gold coins\n", COFFEE_PRICE);
    printf("2. Tea - %d gold coins\n", TEA_PRICE);
    printf("3. Bread - %d gold coins\n", BREAD_PRICE);
    printf("4. Cake - %d gold coins\n", CAKE_PRICE);
}

// Function to take the order
Order takeOrder() {
    Order order;
    int i, j;

    // Initialize the order
    for (i = 0; i < MAX_ITEMS; i++) {
        order.item[i] = 0;
        order.quantity[i] = 0;
    }
    order.totalPrice = 0;

    // Take the order
    printf("\n");
    printf("Enter the items you wish to order (1-%d): ", MAX_ITEMS - 1);
    scanf("%d", &j);
    while (j >= 1 && j <= MAX_ITEMS) {
        order.item[j - 1] = 1;
        printf("\n");
        printf("Enter the quantity of %d: ", j);
        scanf("%d", &order.quantity[j - 1]);
        order.totalPrice += order.quantity[j - 1] * (j == 1? COFFEE_PRICE :
                                                                                (j == 2? TEA_PRICE :
                                                                                        (j == 3? BREAD_PRICE : CAKE_PRICE)));
        printf("\n");
        printf("Enter another item (y/n)? ");
        scanf(" %c", &j);
    }

    return order;
}

// Function to print the order
void printOrder(Order order) {
    int i;

    printf("\n");
    printf("Your order:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        if (order.item[i]) {
            printf("%d. %d x %s - %d gold coins\n", i + 1, order.quantity[i],
                   (i == 0? "Coffee" : (i == 1? "Tea" : (i == 2? "Bread" : "Cake"))),
                   COFFEE_PRICE * order.quantity[i]);
        }
    }
    printf("\n");
    printf("Total price: %d gold coins\n", order.totalPrice);
}

// Main function
int main() {
    Order order;

    // Display the menu
    displayMenu();

    // Take the order
    order = takeOrder();

    // Print the order
    printOrder(order);

    return 0;
}