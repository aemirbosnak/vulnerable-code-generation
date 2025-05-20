//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum {
    MENU_ITEM_COFFEE = 1,
    MENU_ITEM_TEA = 2,
    MENU_ITEM_CAKE = 3,
    MENU_ITEM_SANDWICH = 4,
    MENU_ITEM_COUNT = 5
};

struct menu_item {
    char name[32];
    int price;
};

struct menu_item menu_items[] = {
    {"Coffee", 50},
    {"Tea", 30},
    {"Cake", 80},
    {"Sandwich", 100}
};

int main() {
    int num_items;
    double total_price = 0.0;

    printf("Welcome to the Cafe!\n");
    printf("Please select the items you wish to purchase:\n");

    for (int i = 0; i < MENU_ITEM_COUNT; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu_items[i].name, menu_items[i].price);
    }

    printf("Enter the number of items you wish to purchase: ");
    scanf("%d", &num_items);

    printf("You ordered:\n");
    for (int i = 0; i < num_items; i++) {
        int item_index;
        printf("Enter the index of the item you want to purchase (1-%d): ", MENU_ITEM_COUNT - 1);
        scanf("%d", &item_index);
        total_price += menu_items[item_index - 1].price;
        printf("%d. %s - $%.2f\n", item_index, menu_items[item_index - 1].name, menu_items[item_index - 1].price);
    }

    printf("Total price: $%.2f\n", total_price);

    return 0;
}