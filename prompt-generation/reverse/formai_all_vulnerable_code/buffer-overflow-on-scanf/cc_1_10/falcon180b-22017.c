//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

void add_item(struct item items[], int count) {
    printf("Enter item name: ");
    scanf("%s", items[count].name);
    printf("Enter item price: ");
    scanf("%f", &items[count].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[count].quantity);
}

void display_items(struct item items[], int count) {
    printf("\nItem Name\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(struct item items[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal Expense: %.2f\n", total);
}

int main() {
    struct item items[MAX_ITEMS];
    int count = 0;

    while (count < MAX_ITEMS) {
        printf("\nEnter 1 to add item or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_item(items, count);
            count++;
        } else if (choice!= 0) {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\nItems added:\n");
    display_items(items, count);

    calculate_total(items, count);

    return 0;
}