//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 10, 5.0},
    {"Tea", 8, 4.0},
    {"Juice", 12, 3.0},
    {"Smoothie", 6, 6.0},
    {"Biscuits", 14, 2.0},
    {"Cookies", 16, 3.5},
    {"Brownies", 18, 4.5},
    {"Muffins", 20, 5.5},
    {"Scones", 12, 3.0},
    {"Pancakes", 8, 4.0}
};

int main() {

    int numItems = 0;
    float totalCost = 0.0;

    printf("Welcome to the Caffeinated Catastrophe!\n");
    printf("Please select an item: ");

    char itemName[20];
    scanf("%s", itemName);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, itemName) == 0) {
            numItems++;
            totalCost += items[i].price * items[i].quantity;
        }
    }

    if (numItems == 0) {
        printf("Oops, that item doesn't exist!\n");
    } else {
        printf("Here's your order:\n");
        for (int i = 0; i < numItems; i++) {
            printf("%s - %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }

        printf("Total cost: $%.2f\n", totalCost);
        printf("Please tender your payment: $");

        float payment = 0.0;
        scanf("%f", &payment);

        if (payment < totalCost) {
            printf("Sorry, that's not enough money!\n");
        } else {
            printf("Thank you for your order! Come again soon!\n");
            return 0;
        }
    }

    return 0;
}