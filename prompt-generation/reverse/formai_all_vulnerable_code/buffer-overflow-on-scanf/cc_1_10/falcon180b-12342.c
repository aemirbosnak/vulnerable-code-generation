//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
};

void add_item(struct item items[], int *count) {
    printf("Enter item name: ");
    scanf("%s", items[*count].name);
    printf("Enter item price: ");
    scanf("%f", &items[*count].price);
    (*count)++;
}

void display_menu(struct item items[], int count) {
    printf("\nMenu:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

void place_order(struct item items[], int count, int customer_order[], int order_count) {
    printf("\nOrder for customer %d:\n", order_count+1);
    for (int i = 0; i < order_count; i++) {
        int index = customer_order[i] - 1;
        if (index >= 0 && index < count) {
            printf("%d. %s - $%.2f\n", i+1, items[index].name, items[index].price);
        } else {
            printf("%d. Invalid item\n", i+1);
        }
    }
    printf("\nTotal cost: $%.2f\n\n", 0);
}

int main() {
    struct item menu[MAX_ITEMS];
    int menu_count = 0;

    add_item(menu, &menu_count);
    add_item(menu, &menu_count);
    add_item(menu, &menu_count);

    int order[MAX_ITEMS];
    int order_count = 0;

    while (1) {
        display_menu(menu, menu_count);

        printf("\nEnter number of items in order: ");
        scanf("%d", &order_count);

        if (order_count > MAX_ITEMS || order_count < 1) {
            printf("Invalid order size\n");
            continue;
        }

        for (int i = 0; i < order_count; i++) {
            printf("Enter item number: ");
            scanf("%d", &order[i]);

            if (order[i] < 1 || order[i] > menu_count) {
                printf("Invalid item number\n");
                i--;
                continue;
            }
        }

        place_order(menu, menu_count, order, order_count);

        break;
    }

    return 0;
}