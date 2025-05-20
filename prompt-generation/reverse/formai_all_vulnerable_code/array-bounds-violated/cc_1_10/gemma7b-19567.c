//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 5.0, 10},
    {"Tea", 3.0, 5},
    {"Juice", 4.0, 7},
    {"Smoothie", 6.0, 3},
    {"Water", 2.0, 12},
    {"Soda", 3.5, 6},
    {"Juice Lemon", 4.5, 4},
    {"Mango Shake", 7.0, 2},
    {"Fruit Punch", 5.5, 8},
    {"Smoothie Berry", 6.5, 1}
};

void print_bill(int total_items, float total_amount) {
    printf("---------------------------------------------------\n");
    printf("C Cafe Billing System\n");
    printf("---------------------------------------------------\n");
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: $%.2f\n", total_amount);
    printf("Items:\n");
    for (int i = 0; i < total_items; i++) {
        printf("%s - $%.2f x %d\n", items[i].name, items[i].price, items[i].quantity);
    }
    printf("---------------------------------------------------\n");
    printf("Thank you for your visit at C Cafe!\n");
    printf("---------------------------------------------------\n");
}

int main() {
    int total_items = 0;
    float total_amount = 0.0;

    // Calculate total items and amount
    for (int i = 0; i < MAX_ITEM_NUM; i++) {
        total_items += items[i].quantity;
        total_amount += items[i].price * items[i].quantity;
    }

    // Print bill
    print_bill(total_items, total_amount);

    return 0;
}