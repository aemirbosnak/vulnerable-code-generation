//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 10, 50.0},
    {"Tea", 8, 40.0},
    {"Juice", 12, 30.0},
    {"Smoothie", 6, 45.0},
    {"Biscuits", 14, 20.0},
    {"Cookies", 16, 25.0},
    {"Brownies", 18, 35.0},
    {"Scones", 12, 30.0},
    {"Muffins", 10, 40.0},
    {"Pancakes", 8, 25.0}
};

void display_menu() {
    printf("----------------------------------------------------------------\n");
    printf("           Welcome to the C Cafe Billing System!\n");
    printf("----------------------------------------------------------------\n");
    printf("Here is the menu:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
    printf("\n");
}

int main() {
    display_menu();

    int item_no;
    printf("Please enter the number of the item you want to order: ");
    scanf("%d", &item_no);

    int quantity;
    printf("Please enter the quantity of the item you want to order: ");
    scanf("%d", &quantity);

    float total_price = items[item_no - 1].price * quantity;

    printf("Your order:\n");
    printf("%s - %d - %.2f\n", items[item_no - 1].name, quantity, items[item_no - 1].price);
    printf("Total price: %.2f\n", total_price);

    return 0;
}