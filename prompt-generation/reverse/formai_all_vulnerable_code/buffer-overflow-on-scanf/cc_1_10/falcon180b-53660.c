//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
// This program is a simple C Cafe Billing System that allows the user to order items from a menu and calculates the total cost of their order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Item;

int main() {
    int numItems, i, choice;
    float totalCost = 0.0;
    char input[MAX_NAME_LENGTH];
    Item menu[MAX_ITEMS] = {{"Coffee", 2.50}, {"Tea", 1.75}, {"Cake", 3.50}, {"Cookie", 1.25}, {"Sandwich", 4.50}, {"Soup", 3.75}, {"Salad", 5.00}, {"Pizza", 6.50}, {"Pasta", 7.50}, {"Burger", 5.75}};

    printf("Welcome to the C Cafe!\n");
    printf("Please select an item from the menu:\n");

    for (i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= MAX_ITEMS) {
        totalCost += menu[choice-1].price;
        printf("You ordered %s for $%.2f.\n", menu[choice-1].name, menu[choice-1].price);
    } else {
        printf("Invalid choice.\n");
    }

    printf("\nEnter '1' to order another item or '0' to check out:\n");
    scanf("%d", &choice);

    while (choice == 1) {
        printf("Please select an item from the menu:\n");

        for (i = 0; i < MAX_ITEMS; i++) {
            printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
        }

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= MAX_ITEMS) {
            totalCost += menu[choice-1].price;
            printf("You ordered %s for $%.2f.\n", menu[choice-1].name, menu[choice-1].price);
        } else {
            printf("Invalid choice.\n");
        }

        printf("\nEnter '1' to order another item or '0' to check out:\n");
        scanf("%d", &choice);
    }

    printf("\nYour total cost is $%.2f.\n", totalCost);

    return 0;
}