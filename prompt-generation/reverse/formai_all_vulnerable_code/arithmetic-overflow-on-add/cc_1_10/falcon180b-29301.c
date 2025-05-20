//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Define the structure of each item in the menu
typedef struct {
    char name[50];
    float price;
} MenuItem;

// Define the structure of each order
typedef struct {
    int itemCount;
    MenuItem items[MAX_ITEMS];
} Order;

// Function to add an item to the order
void addItem(Order* order) {
    int count = order->itemCount;
    printf("Enter the name of the item: ");
    scanf("%s", order->items[count].name);
    printf("Enter the price of the item: ");
    scanf("%f", &order->items[count].price);
    order->itemCount++;
}

// Function to calculate the total price of the order
float calculateTotal(Order* order) {
    float total = 0.0;
    for(int i=0; i<order->itemCount; i++) {
        total += order->items[i].price;
    }
    return total;
}

// Function to print the order
void printOrder(Order* order) {
    printf("Order:\n");
    for(int i=0; i<order->itemCount; i++) {
        printf("%s - $%.2f\n", order->items[i].name, order->items[i].price);
    }
    printf("Total: $%.2f\n", calculateTotal(order));
}

int main() {
    Order order;
    int choice;

    do {
        printf("\nCafe Billing System\n");
        printf("1. Add item to order\n");
        printf("2. Print order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                printOrder(&order);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}