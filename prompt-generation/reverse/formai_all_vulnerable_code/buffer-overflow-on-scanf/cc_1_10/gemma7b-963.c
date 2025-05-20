//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[] = {
    {"Coffee", 10, 5.0},
    {"Tea", 8, 4.0},
    {"Juice", 12, 3.0},
    {"Smoothie", 6, 6.0}
};

int main() {

    int i, totalItems = 4, orderQuantity, itemIndex;
    float totalAmount = 0.0;

    printf("Welcome to The Coffee Bean!\n");
    printf("--------------------\n");

    // Display items
    for (i = 0; i < totalItems; i++) {
        printf("%s - %d - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    // Get the order quantity for each item
    printf("Enter the quantity of each item:\n");
    for (i = 0; i < totalItems; i++) {
        printf("%s: ", items[i].name);
        scanf("%d", &orderQuantity);
        items[i].quantity -= orderQuantity;
        totalAmount += items[i].price * orderQuantity;
    }

    // Calculate the total amount
    printf("Total amount: $%.2f\n", totalAmount);

    // Print the receipt
    printf("--------------------\n");
    printf("Thank you for your order at The Coffee Bean!\n");
    printf("Your order:\n");
    for (i = 0; i < totalItems; i++) {
        printf("%s - %d - $%.2f\n", items[i].name, orderQuantity, items[i].price);
    }
    printf("Total amount: $%.2f\n", totalAmount);

    return 0;
}