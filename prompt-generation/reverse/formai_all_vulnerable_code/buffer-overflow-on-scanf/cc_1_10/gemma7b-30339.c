//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 10, 50.0},
    {"Tea", 8, 40.0},
    {"Juice", 6, 30.0},
    {"Soda", 4, 20.0},
    {"Biscuits", 12, 10.0},
    {"Cookies", 14, 15.0},
    {"Brownies", 16, 20.0},
    {"Cakes", 8, 25.0},
    {"Pastries", 10, 12.0},
    {"Scones", 6, 18.0}
};

int main() {
    int item_num;
    float total_price = 0.0;
    char choice;

    printf("Welcome to the C Cafe Billing System!\n");

    // Get the item number
    printf("Enter the item number: ");
    scanf("%d", &item_num);

    // Validate the item number
    if (item_num < 0 || item_num >= MAX_ITEM_NUM) {
        printf("Invalid item number.\n");
        return 1;
    }

    // Get the item name
    printf("Enter the item name: ");
    scanf("%s", items[item_num].name);

    // Get the item quantity
    printf("Enter the item quantity: ");
    scanf("%d", &items[item_num].quantity);

    // Get the item price
    printf("Enter the item price: ");
    scanf("%f", &items[item_num].price);

    // Calculate the total price
    total_price += items[item_num].quantity * items[item_num].price;

    // Display the total price
    printf("Total price: $%.2f\n", total_price);

    // Ask for confirmation
    printf("Would you like to continue shopping? (Y/N): ");
    scanf("%c", &choice);

    // Continue shopping if the user enters Y
    if (choice == 'Y') {
        main();
    }

    // Exit the program
    return 0;
}