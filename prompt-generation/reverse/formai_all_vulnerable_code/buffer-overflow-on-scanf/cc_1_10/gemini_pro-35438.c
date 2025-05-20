//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} item;

void add_item(item **items, int *num_items) {
    *items = realloc(*items, (*num_items + 1) * sizeof(item));
    printf("Enter item name: ");
    scanf("%s", (*items)[*num_items].name);
    printf("Enter quantity: ");
    scanf("%d", &(*items)[*num_items].quantity);
    printf("Enter price: ");
    scanf("%f", &(*items)[*num_items].price);
    (*num_items)++;
}

void remove_item(item **items, int *num_items) {
    int index;
    printf("Enter item index to remove: ");
    scanf("%d", &index);
    if (index >= *num_items) {
        printf("Invalid index.\n");
    } else {
        for (int i = index; i < *num_items - 1; i++) {
            (*items)[i] = (*items)[i + 1];
        }
        (*num_items)--;
        *items = realloc(*items, *num_items * sizeof(item));
    }
}

void print_items(item *items, int num_items) {
    printf("Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main(void) {
    int num_items = 0;
    item *items = NULL;
    int choice;
    float total = 0;

    do {
        printf("1. Add item\n2. Remove item\n3. Print items\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(&items, &num_items);
                break;
            case 2:
                remove_item(&items, &num_items);
                break;
            case 3:
                print_items(items, num_items);
                break;
            case 4:
                for (int i = 0; i < num_items; i++) {
                    total += items[i].quantity * items[i].price;
                }
                printf("Total: %.2f\n", total);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    free(items);
    return 0;
}