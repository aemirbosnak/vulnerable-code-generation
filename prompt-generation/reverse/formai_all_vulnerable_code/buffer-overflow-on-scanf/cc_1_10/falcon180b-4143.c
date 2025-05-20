//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE 1000

typedef struct item {
    char name[MAX_NAME_LENGTH];
    float price;
} item;

void add_item(item *menu, int *num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", menu[*num_items].name);
    printf("Enter the price of the item: ");
    scanf("%f", &menu[*num_items].price);
    (*num_items)++;
}

void display_menu(item *menu, int num_items) {
    printf("\nMenu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void take_order(item *menu, int num_items, float *total_cost) {
    int num_items_ordered = 0;
    printf("\nEnter the number of items you wish to order: ");
    scanf("%d", &num_items_ordered);

    for (int i = 0; i < num_items_ordered; i++) {
        int item_number;
        printf("Enter the number of the item you wish to order: ");
        scanf("%d", &item_number);
        if (item_number >= 1 && item_number <= num_items) {
            (*total_cost) += menu[item_number-1].price;
            printf("\nItem %d added to your order.\n", item_number);
        } else {
            printf("\nInvalid item number.\n");
        }
    }
}

void calculate_bill(float *total_cost, float *tax, float *total_bill) {
    printf("\nCalculating bill...\n");
    (*tax) = (*total_cost) * 0.08;
    (*total_bill) = (*total_cost) + (*tax);
    printf("\nTotal cost: $%.2f\n", *total_cost);
    printf("Tax: $%.2f\n", *tax);
    printf("Total bill: $%.2f\n", *total_bill);
}

int main() {
    item menu[MAX_ITEMS];
    int num_items = 0;

    add_item(menu, &num_items);
    add_item(menu, &num_items);
    add_item(menu, &num_items);

    display_menu(menu, num_items);

    float total_cost = 0;
    float tax = 0;
    float total_bill = 0;

    take_order(menu, num_items, &total_cost);
    calculate_bill(&total_cost, &tax, &total_bill);

    return 0;
}