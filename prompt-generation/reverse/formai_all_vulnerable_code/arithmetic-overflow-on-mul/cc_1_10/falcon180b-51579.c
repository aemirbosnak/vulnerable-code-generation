//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char name[50];
    int price;
} item;

int main() {
    int num_items, i;
    item items[100];
    float total_price = 0;

    printf("Welcome to our cafe!\n");

    // Add items to the menu
    num_items = 0;
    while (1) {
        printf("Enter a new item (press enter to finish):\n");
        scanf("%s", items[num_items].name);
        if (strcmp(items[num_items].name, "") == 0) {
            break;
        }
        printf("Enter the price of %s:\n", items[num_items].name);
        scanf("%d", &items[num_items].price);
        num_items++;
    }

    // Display the menu
    printf("\nOur menu:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s - $%.2f\n", items[i].name, items[i].price);
    }

    // Take customer orders
    int num_orders;
    printf("\nEnter the number of items you want to order:\n");
    scanf("%d", &num_orders);
    for (i = 0; i < num_orders; i++) {
        printf("Enter the name of the item you want to order:\n");
        scanf("%s", items[i].name);
        printf("Enter the quantity of %s you want to order:\n", items[i].name);
        scanf("%d", &items[i].price);
        total_price += items[i].price * items[i].price;
    }

    // Calculate and display the total price
    printf("\nYour total price is: $%.2f\n", total_price);

    return 0;
}