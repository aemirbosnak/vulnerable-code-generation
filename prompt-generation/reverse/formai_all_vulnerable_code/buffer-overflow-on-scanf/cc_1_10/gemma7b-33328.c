//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
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
    {"Coffee", 50.0, 10},
    {"Tea", 30.0, 8},
    {"Juice", 20.0, 6},
    {"Smoothie", 40.0, 5},
    {"Ice Cream", 25.0, 2}
};

void displayItems() {
    int i;
    for (i = 0; i < MAX_ITEM_NUM; i++) {
        printf("%s - %.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

int main() {
    int item_num, quantity, total_amount = 0;
    char item_name[50];

    printf("Welcome to the C Cafe!\n");
    displayItems();

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
        if (strcmp(item_name, items[item_num].name) == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            items[item_num].quantity -= quantity;

            total_amount += quantity * items[item_num].price;
        }
    }

    printf("Total amount: %.2f\n", total_amount);
    printf("Thank you for your visit!\n");

    return 0;
}