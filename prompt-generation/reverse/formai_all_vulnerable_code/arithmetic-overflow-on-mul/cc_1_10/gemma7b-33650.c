//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 50, 10},
    {"Tea", 40, 8},
    {"Juice", 30, 6},
    {"Smoothie", 45, 4},
    {"Cookies", 20, 12},
    {"Biscuits", 25, 14},
    {"Scones", 35, 9},
    {"Muffins", 30, 7},
    {"Pancakes", 32, 11},
    {"Waffles", 38, 5}
};

void print_menu() {
    printf("*** C Cafe Menu ***\n");
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        printf("%s - %d - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("\n");
}

int main() {
    int item_num = 0;
    char item_name[20];
    int quantity;
    int total_price = 0;

    print_menu();

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        if (strcmp(item_name, items[i].name) == 0) {
            item_num = i;
            break;
        }
    }

    if (item_num == -1) {
        printf("Item not found.\n");
    } else {
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        items[item_num].quantity -= quantity;

        total_price = items[item_num].price * quantity;
        printf("Total price: %d\n", total_price);
    }

    return 0;
}