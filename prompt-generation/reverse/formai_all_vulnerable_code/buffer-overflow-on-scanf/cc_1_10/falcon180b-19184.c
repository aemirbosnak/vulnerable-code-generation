//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char *name;
    float price;
    int quantity;
};

void add_item(struct item *items, int *count) {
    printf("Enter name of item: ");
    scanf("%s", items[*count].name);
    printf("Enter price of item: ");
    scanf("%f", &items[*count].price);
    printf("Enter quantity of item: ");
    scanf("%d", &items[*count].quantity);
    (*count)++;
}

void display_items(struct item *items, int count) {
    printf("Item Name\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void remove_item(struct item *items, int *count) {
    printf("Enter name of item to remove: ");
    char name[50];
    scanf("%s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            memmove(&items[i], &items[i + 1], (MAX_ITEMS - i - 1) * sizeof(struct item));
            (*count)--;
            return;
        }
    }
    printf("Item not found.\n");
}

int main() {
    struct item items[MAX_ITEMS];
    int count = 0;

    while (1) {
        printf("\n1. Add item\n2. Display items\n3. Remove item\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &count);
                break;
            case 2:
                display_items(items, count);
                break;
            case 3:
                remove_item(items, &count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}