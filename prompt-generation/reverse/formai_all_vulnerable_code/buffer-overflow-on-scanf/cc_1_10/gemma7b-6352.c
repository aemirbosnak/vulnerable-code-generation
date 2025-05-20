//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 10, 5.0},
    {"Tea", 8, 4.0},
    {"Juice", 6, 3.5},
    {"Water", 12, 2.0},
    {"Smoothie", 4, 6.0},
    {"Ice Cream", 3, 7.0},
    {"Cookies", 5, 3.0},
    {"Scones", 2, 4.5},
    {"Pancakes", 6, 5.5},
    {"Waffles", 1, 6.5}
};

int main() {
    int item_num = 0;
    char customer_name[20];
    float total_price = 0.0;

    printf("Welcome to C Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    printf("Please select an item: ");
    for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
        printf("%d. %s - %d units - %.2f\n", item_num + 1, items[item_num].name, items[item_num].quantity, items[item_num].price);
    }
    int item_choice = 0;
    scanf("%d", &item_choice);

    item_num = item_choice - 1;
    int quantity = 0;
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    if (quantity > items[item_num].quantity) {
        printf("Sorry, insufficient quantity.\n");
    } else {
        total_price += items[item_num].price * quantity;
        items[item_num].quantity -= quantity;
    }

    printf("Thank you, %s. Your total price is: %.2f\n", customer_name, total_price);

    return 0;
}