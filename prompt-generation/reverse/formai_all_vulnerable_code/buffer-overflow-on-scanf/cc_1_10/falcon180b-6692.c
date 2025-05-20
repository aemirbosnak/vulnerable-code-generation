//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complex
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

    count++;
}

void display_items(struct item items[], int count) {
    printf("\nItem\tPrice\tQuantity\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(struct item items[], int count) {
    float total = 0.0;

    for (int i = 0; i < count; i++) {
        total += items[i].price * items[i].quantity;
    }

    printf("\nTotal Expense: $%.2f\n", total);
}

int main() {
    struct item items[MAX_ITEMS];
    int count = 0;

    while (count < MAX_ITEMS) {
        printf("\nEnter 1 to add item\nEnter 2 to display items\nEnter 3 to calculate total\nEnter 4 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_ITEMS) {
                    printf("Cannot add more items.\n");
                } else {
                    add_item(items, count);
                    count++;
                }
                break;
            case 2:
                if (count == 0) {
                    printf("No items added.\n");
                } else {
                    display_items(items, count);
                }
                break;
            case 3:
                if (count == 0) {
                    printf("No items added.\n");
                } else {
                    calculate_total(items, count);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}