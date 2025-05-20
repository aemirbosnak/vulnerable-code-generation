//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 10
#define PRICE_PER_ITEM 1.50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} item;

item items[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Cannot add item. Max limit reached.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);

    num_items++;
}

void print_bill() {
    float total = 0.0;

    printf("\n========== C AFE BILLING SYSTEM ==========\n");
    printf("Item\tName\tQuantity\tPrice\tTotal\n");

    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t%d\t$%.2f\t$%.2f\n", i + 1, items[i].name, items[i].quantity, PRICE_PER_ITEM, PRICE_PER_ITEM * items[i].quantity);
        total += PRICE_PER_ITEM * items[i].quantity;
    }

    printf("\n===============\nTotal:\t$%.2f", total);
}

int main() {
    char command[10];
    int choice = -1;

    while (1) {
        printf("\nC AFE BILLING SYSTEM\n1. Add Item\n2. Print Bill\n3. Exit\nEnter your choice: ");
        scanf("%s", command);

        if (strcmp(command, "1") == 0) {
            add_item();
        } else if (strcmp(command, "2") == 0) {
            print_bill();
            break;
        } else if (strcmp(command, "3") == 0) {
            exit(0);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}