//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
} Item;

Item menu[] = {{"Burger", 5.00}, {"Sandwich", 3.50}, {"Pizza", 8.99}, {"Coke", 1.50}, {"Water", 1.00}};

int main() {
    int num_items = 0;
    Item bill[MAX_ITEMS];
    float total_bill = 0;
    char choice[MAX_NAME_LEN];

    while (1) {
        printf("\n**** C Cafe Billing System ****\n");
        printf("Please choose an item from the menu:\n");
        for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
            printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
        }
        printf("%d. Exit\n", sizeof(menu) / sizeof(menu[0]) + 1);
        scanf("%d", &choice);

        if (choice > sizeof(menu) / sizeof(menu[0])) {
            break;
        }

        if (num_items >= MAX_ITEMS) {
            printf("Sorry, maximum number of items reached.\n");
            continue;
        }

        for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
            if (strcmp(menu[i].name, choice) == 0) {
                bill[num_items++] = menu[i];
                total_bill += menu[i].price;
                break;
            }
        }

        printf("Item '%s' added to the bill.\n", choice);
    }

    printf("\n**** Your Bill ****\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, bill[i].name, bill[i].price);
        total_bill += bill[i].price;
    }
    printf("%d. Total Bill - $%.2f\n", num_items + 1, total_bill);

    return 0;
}