//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[50];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 5.0, 10},
    {"Tea", 4.0, 8},
    {"Juice", 3.0, 12},
    {"Soda", 2.0, 15},
    {"Water", 1.0, 20}
};

void display_menu() {
    printf("------------------- MENU --------------------\n");
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        printf("%s - $%.2f - (%d)\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("----------------------------------------\n");
}

int main() {
    int item_num;
    char item_name[50];
    float quantity;
    float total_price = 0.0;

    display_menu();

    printf("Enter item number: ");
    scanf("%d", &item_num);

    if (item_num < 0 || item_num >= MAX_ITEM_NUM) {
        printf("Invalid item number.\n");
    } else {
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter quantity: ");
        scanf("%f", &quantity);

        items[item_num].quantity -= quantity;
        total_price += quantity * items[item_num].price;
    }

    printf("Total price: $%.2f\n", total_price);

    return 0;
}