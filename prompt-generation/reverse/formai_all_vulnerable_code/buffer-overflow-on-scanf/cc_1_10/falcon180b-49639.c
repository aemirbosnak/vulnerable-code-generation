//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

void add_item(struct item items[], int count, char name[], float price, int quantity) {
    if (count >= MAX_ITEMS) {
        printf("Error: Maximum number of items reached.\n");
        return;
    }

    strcpy(items[count].name, name);
    items[count].price = price;
    items[count].quantity = quantity;
    count++;
}

void display_menu(struct item items[], int count) {
    printf("\nMenu:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f (%d left)\n", i+1, items[i].name, items[i].price, items[i].quantity);
    }
    printf("%d. Exit\n", count+1);
}

void place_order(struct item items[], int count, int choice) {
    if (choice < 1 || choice > count) {
        printf("Invalid choice.\n");
        return;
    }

    printf("You ordered %s.\n", items[choice-1].name);
    items[choice-1].quantity--;

    if (items[choice-1].quantity == 0) {
        printf("Item sold out.\n");
    }
}

int main() {
    struct item items[MAX_ITEMS];
    int count = 0;

    add_item(items, count, "Coffee", 3.50, 50);
    add_item(items, count, "Tea", 2.00, 30);
    add_item(items, count, "Cake", 4.50, 20);

    int choice;
    while (1) {
        display_menu(items, count);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == count+1) {
            break;
        }

        place_order(items, count, choice);
    }

    return 0;
}