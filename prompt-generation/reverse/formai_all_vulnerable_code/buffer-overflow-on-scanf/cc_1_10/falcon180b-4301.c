//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50

struct item {
    char name[50];
    float price;
};

void display_menu(struct item items[], int num_items) {
    printf("MENU\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
}

int main() {
    struct item menu_items[MAX_ITEMS];
    int num_items = 0;

    // Populate menu items
    strcpy(menu_items[num_items].name, "Coffee");
    menu_items[num_items].price = 2.50;
    num_items++;

    strcpy(menu_items[num_items].name, "Tea");
    menu_items[num_items].price = 1.50;
    num_items++;

    strcpy(menu_items[num_items].name, "Cake");
    menu_items[num_items].price = 3.50;
    num_items++;

    // Display menu
    display_menu(menu_items, num_items);

    // Take order
    int order[MAX_ITEMS];
    int num_orders = 0;

    while (num_orders < MAX_ITEMS) {
        printf("Enter item number to order or 0 to finish: ");
        scanf("%d", &order[num_orders]);

        if (order[num_orders] == 0) {
            break;
        } else if (order[num_orders] > num_items || order[num_orders] < 1) {
            printf("Invalid item number.\n");
        } else {
            num_orders++;
        }
    }

    // Calculate total
    float total = 0.0;

    for (int i = 0; i < num_orders; i++) {
        total += menu_items[order[i]-1].price;
    }

    // Print receipt
    printf("\nRECEIPT\n");
    printf("Item\t\tPrice\n");

    for (int i = 0; i < num_orders; i++) {
        printf("%d. %s\t\t$%.2f\n", i+1, menu_items[order[i]-1].name, menu_items[order[i]-1].price);
    }

    printf("\nTotal: $%.2f\n", total);

    return 0;
}