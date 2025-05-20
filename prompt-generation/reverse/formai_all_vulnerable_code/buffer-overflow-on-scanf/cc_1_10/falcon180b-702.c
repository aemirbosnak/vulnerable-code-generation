//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY_LEN 5

typedef struct {
    char name[MAX_NAME_LEN];
    char quantity[MAX_QUANTITY_LEN];
    float price;
} Item;

void add_item(Item* items, int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the quantity of the item: ");
    scanf("%s", items[num_items].quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &items[num_items].price);
}

void calculate_total(Item* items, int num_items) {
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price * atof(items[i].quantity);
    }
    printf("Total: $%.2f\n", total);
}

void print_bill(Item* items, int num_items) {
    printf("Bill:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %s - $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("Enter 1 to add an item, 2 to calculate total, 3 to print bill, or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, num_items);
                num_items++;
                break;
            case 2:
                if (num_items > 0) {
                    calculate_total(items, num_items);
                }
                break;
            case 3:
                if (num_items > 0) {
                    print_bill(items, num_items);
                }
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}