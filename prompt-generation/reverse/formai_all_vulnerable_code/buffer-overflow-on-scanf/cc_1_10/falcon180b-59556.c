//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100

typedef struct item {
    char name[50];
    double price;
    int quantity;
} item_t;

item_t items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Maximum number of items reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item price: ");
    if (scanf("%lf", &items[num_items].price)!= 1) {
        printf("Invalid input.\n");
        return;
    }

    printf("Enter item quantity: ");
    if (scanf("%d", &items[num_items].quantity)!= 1) {
        printf("Invalid input.\n");
        return;
    }

    num_items++;
}

void display_items() {
    printf("\nItem\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%.2lf\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total() {
    double total = 0.0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }

    printf("\nTotal: $%.2lf\n", total);
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");

        int choice;
        if (scanf("%d", &choice)!= 1) {
            printf("Invalid input.\n");
            continue;
        }

        switch (choice) {
        case 1:
            add_item();
            break;
        case 2:
            display_items();
            break;
        case 3:
            calculate_total();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}