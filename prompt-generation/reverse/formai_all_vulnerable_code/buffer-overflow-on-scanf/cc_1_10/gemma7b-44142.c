//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: genius
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
    {"Tea", 5, 40.0},
    {"Juice", 2, 30.0},
    {"Soda", 1, 20.0},
    {"Biscuits", 8, 15.0},
    {"Cookies", 6, 12.0},
    {"Brownies", 4, 10.0},
    {"Cake", 2, 25.0},
    {"Ice Cream", 3, 18.0},
    {"Smoothie", 1, 22.0}
};

void calculateTotal(int numItems) {
    float total = 0.0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].quantity * items[i].price;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    int numItems = 0;
    float total = 0.0;
    char choice;

    printf("Welcome to the C Cafe!\n");

    // Loop to add items to the cart
    while (1) {
        printf("Enter item name: ");
        char itemName[20];
        scanf("%s", itemName);

        int itemFound = 0;
        for (int i = 0; i < MAX_ITEM_NUM; i++) {
            if (strcmp(itemName, items[i].name) == 0) {
                items[i].quantity++;
                itemFound = 1;
            }
        }

        if (!itemFound) {
            printf("Item not found.\n");
        }

        printf("Enter 'q' to quit or any key to continue: ");
        scanf("%c", &choice);

        if (choice == 'q') {
            break;
        }
    }

    // Calculate the total cost
    calculateTotal(numItems);

    // Print the receipt
    printf("------------------------\n");
    printf("C Cafe Receipt\n");
    printf("------------------------\n");
    printf("Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s: %d @ $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("------------------------\n");
    printf("Thank you for your visit to the C Cafe!\n");
    printf("------------------------\n");

    return 0;
}